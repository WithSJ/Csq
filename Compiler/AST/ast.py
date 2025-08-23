"""
Python implementation of Csq AST
"""
from enum import Enum, auto
from typing import List, Optional

from Compiler.Tokenizer.tokenizer import Token, TokenType, tokenize


class NodeTypes(Enum):
    """Enumeration for all AST node types."""
    EXPR = auto()
    VAR_DECL = auto()
    VAR_ASSIGN = auto()
    FUN_DECL = auto()
    IF_STMT = auto()
    ELSE_STMT = auto()
    ELIF_STMT = auto()
    FOR_STMT = auto()
    WHILE_STMT = auto()
    BLOCK = auto()
    FUN_CALL = auto()
    PRINT = auto()
    ACCESS = auto()
    COLLECTION_UPDATE = auto()
    RETURN = auto()
    IMPORT = auto()
    UNKNOWN_NODE = auto()
    CIMPORT = auto()
    CLASS = auto()
    BREAK = auto()
    METHOD_DECL = auto()
    MEMBER_VAR_DECL = auto()
    MEMBER_VAR_ASSIGN = auto()


class ASTNode:
    """Parent class for all AST nodes."""
    def __init__(self, node_type: NodeTypes):
        self.type: NodeTypes = node_type
        self.indent_level: int = 0

    def visit(self) -> str:
        """
        Generates the target language code for this node.
        Base implementation raises an error, subclasses should override this.
        """
        raise NotImplementedError(f"visit() method not implemented for {self.__class__.__name__}")


class ExprNode(ASTNode):
    """Node representing an expression."""
    def __init__(self, tokens: List[Token]):
        super().__init__(NodeTypes.EXPR)
        self.tokens = tokens

    def visit(self) -> str:
        val = "".join(tok.token for tok in self.tokens)
        # Special case for C++ vector initialization syntax
        if val.startswith('{') and val.endswith('}'):
            return f"vector<Cell>{val}"
        return val


class VarDeclNode(ASTNode):
    """Node representing a variable declaration."""
    def __init__(self, identifier: str, value: ExprNode, var_type: str = ""):
        super().__init__(NodeTypes.VAR_DECL)
        self.identifier = identifier
        self.var_type = var_type  # Note: this seems unused in the original codegen
        self.value = value

    def visit(self) -> str:
        return f'allocateVar("{self.identifier}", Cell({self.value.visit()}));'


class VarAssignNode(ASTNode):
    """Node representing assigning a new value to an existing variable."""
    def __init__(self, identifier: str, value: ExprNode):
        super().__init__(NodeTypes.VAR_ASSIGN)
        self.identifier = identifier
        self.value = value

    def visit(self) -> str:
        return f'assignVar("{self.identifier}", Cell({self.value.visit()}));'


class BlockNode(ASTNode):
    """Node representing a block of statements."""
    def __init__(self, statements: List[ASTNode]):
        super().__init__(NodeTypes.BLOCK)
        self.statements = statements


class FunDeclNode(ASTNode):
    """Node representing a function declaration."""
    def __init__(self, identifier: str, parameters: List[str]):
        super().__init__(NodeTypes.FUN_DECL)
        self.identifier = identifier
        self.parameters = parameters

    def visit(self) -> str:
        # A better fix would be in the parser to not generate empty/whitespace params.
        clean_params = [p for p in self.parameters if p.strip()]
        param_str = ", ".join(f"Cell {p}" for p in clean_params)
        
        code = f"auto {self.identifier} = [&]({param_str}){{\n"

        # Allocate parameters as local variables within the function scope.
        '''
        As parameters are also in terms of variables so they should also
        undergo the generation of variable allocation code so that it can
        be used effectively by other species.
        '''
        for arg in clean_params:
            code += f'    allocateVar("{arg}", Cell({arg}));\n'

        return code


class IfStmtNode(ASTNode):
    """Node representing an if statement."""
    def __init__(self, condition: ExprNode):
        super().__init__(NodeTypes.IF_STMT)
        self.condition = condition

    def visit(self) -> str:
        return f"if({self.condition.visit()}){{"


class ElseStmtNode(ASTNode):
    """Node representing an else statement."""
    def __init__(self):
        super().__init__(NodeTypes.ELSE_STMT)

    def visit(self) -> str:
        return "else{"


class ElifStmtNode(ASTNode):
    """Node representing an else if (elif) statement."""
    def __init__(self, condition: ExprNode):
        super().__init__(NodeTypes.ELIF_STMT)
        self.condition = condition

    def visit(self) -> str:
        return f"else if({self.condition.visit()}){{"


class ForStmtNode(ASTNode):
    """Node representing a for loop statement."""
    def __init__(self, iter_name: str, condition: ExprNode):
        super().__init__(NodeTypes.FOR_STMT)
        self.iter_name = iter_name
        self.condition = condition

    def visit(self) -> str:
        # NOTE: This method's logic is based on a brittle parser that seems to produce
        # single tokens like "range(10" instead of a proper expression tree.
        # The code below tries to robustly handle this, but the parser should be fixed.
        def get_cpp_expr(expr_str: str) -> str:
            """Helper to generate C++ code for a value, which could be a literal or a variable."""
            # Re-tokenizing inside the code generator is a design flaw.
            # This should be handled by the parser creating typed expression nodes.
            token = tokenize(expr_str)[0]
            if token.type == TokenType.VALUE:
                return expr_str
            # Assuming it's a variable that needs .intVal to be accessed
            return f"{expr_str}.intVal"

        try:
            # The original code implies a token structure like ['range(start', ',', 'to', 'range(end)'].
            # This is fragile. We extract the inner parts.
            start_expr_str = self.condition.tokens[0].token[6:-1] # from "range(start"
            end_expr_str = self.condition.tokens[3].token[6:-1]   # from "range(end"
        except IndexError:
            return "// ERROR: Malformed for-loop structure in AST.\n"

        start_val = get_cpp_expr(start_expr_str)
        end_val = get_cpp_expr(end_expr_str)
        iter_var = f"{self.iter_name}__iter"

        return (
            f'allocateVar("{self.iter_name}", Cell(0));\n'
            f'for(int {iter_var} = {start_val}; {iter_var} < {end_val}; {iter_var}++) {{\n'
            f'    assignVar("{self.iter_name}", Cell({iter_var}));\n'
        )


class WhileStmtNode(ASTNode):
    """Node representing a while loop."""
    def __init__(self, condition: ExprNode):
        super().__init__(NodeTypes.WHILE_STMT)
        self.condition = condition

    def visit(self) -> str:
        return f"while({self.condition.visit()}){{"


class CallNode(ASTNode):
    """Node representing a function call."""
    def __init__(self, name: str, params: List[ExprNode]):
        super().__init__(NodeTypes.FUN_CALL)
        self.name = name
        self.params = params


class PrintNode(ASTNode):
    """Node representing a print statement."""
    def __init__(self, value: ExprNode):
        super().__init__(NodeTypes.PRINT)
        self.value = value

    def visit(self) -> str:
        return f"print({self.value.visit()});"


class UnknownNode(ASTNode):
    """Node for unrecognized syntax."""
    def __init__(self):
        super().__init__(NodeTypes.UNKNOWN_NODE)


class AccessNode(ASTNode):
    """Node for accessing a collection element, e.g., my_list[i]."""
    def __init__(self, source: str, index: ExprNode):
        super().__init__(NodeTypes.ACCESS)
        self.source = source
        self.index = index


class CollectionUpdateNode(ASTNode):
    """Node for updating a collection element, e.g., my_list[i] = val."""
    def __init__(self, source: str, index: ExprNode, value: ExprNode):
        super().__init__(NodeTypes.COLLECTION_UPDATE)
        self.source = source
        self.index = index
        self.value = value


class ReturnNode(ASTNode):
    """Node for a return statement."""
    def __init__(self, value: ExprNode):
        super().__init__(NodeTypes.RETURN)
        self.value = value

    def visit(self) -> str:
        return f"return {self.value.visit()};"


class ImportNode(ASTNode):
    """Node for an import statement."""
    def __init__(self, name: str, path: str):
        super().__init__(NodeTypes.IMPORT)
        self.name = name
        self.path = path


class CImportNode(ASTNode):
    """Node for a C-level import statement."""
    def __init__(self, name: str, path: str):
        super().__init__(NodeTypes.CIMPORT)
        self.name = name
        self.path = path


class ClassNode(ASTNode):
    """Node for a class declaration."""
    def __init__(self, name: str):
        super().__init__(NodeTypes.CLASS)
        self.name = name

    def visit(self) -> str:
        return f'__classes__["{self.name}"] = Class();'


class MethodNode(ASTNode):
    """Node for a method declaration inside a class."""
    def __init__(self, identifier: str, class_name: str, parameters: List[str]):
        super().__init__(NodeTypes.METHOD_DECL)
        self.identifier = identifier
        self.class_name = class_name
        self.parameters = parameters

    def visit(self) -> str:
        # This codegen implies all methods take a single Cell argument,
        # which likely holds a list of the actual arguments.
        return (
            f'__classes__["{self.class_name}"].methods["{self.identifier}"] = [](Cell args){{\n'
            '    allocateVar("arg", args);\n'
        )


class MemberVarDeclNode(ASTNode):
    """Node for declaring a member variable in a class."""
    def __init__(self, identifier: str, class_name: str, value: ExprNode):
        super().__init__(NodeTypes.MEMBER_VAR_DECL)
        self.identifier = identifier
        self.class_name = class_name
        self.value = value

    def visit(self) -> str:
        return f'__classes__["{self.class_name}"].members["{self.identifier}"] = {self.value.visit()};'


class MemberVarAssignNode(ASTNode):
    """Node for assigning to a class's static/member variable."""
    def __init__(self, class_name: str, member_name: str, value: ExprNode):
        super().__init__(NodeTypes.MEMBER_VAR_ASSIGN)
        self.class_name = class_name
        self.member_name = member_name
        self.value = value

    def visit(self) -> str:
        # This appears to be for static-like member assignment.
        # The value should be wrapped in a Cell for consistency.
        return f'__classes__["{self.class_name}"].members["{self.member_name}"] = Cell({self.value.visit()});'


class BreakNode(ASTNode):
    """Node for a break statement."""
    def __init__(self):
        super().__init__(NodeTypes.BREAK)

    def visit(self) -> str:
        return "break;"