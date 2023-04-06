#if !defined(AST_Csq4_H)
#define AST_Csq4_H

//Imports
#include "../Grammar/grammar.h"
#include "../Tokenizer/tokenizer.h"
#include "../Memory/stack.h"
#include <memory>
#include <stack>
using namespace std;

//Alias for shared_ptr;
#define Ptr shared_ptr


//Node types
typedef enum {
    VAR_DECLARATION,
    VAR_ASSIGNMENT,
    CLASS_DEFINITION,
    FOR_LOOP,
    WHILE_LOOP,
    EXPR_TYPE,
    FUNCTION_DECL,
    BLOCK,
    IF_STATEMENT,
    ELIF_STATEMENT,
    ELSE_STATEMENT,
    FUN_ARGUMENT,
    PROGRAM, //The basic node type is Program which doesn't needs to be traversed.
} NODE_TYPE;

//Node struct
struct Node;
//body struct for node type
struct Node{
    NODE_TYPE type;
    Node(NODE_TYPE nodetype){
        type = nodetype;
    }
    Node(){}
};

//Declaration for Node types.
struct Expr;
struct VarDecl;
struct VarAssign;
struct Block;
struct FunctionDecl;
struct ClassDecl;
struct ForLoop;
struct WhileLoop;
struct IfStmt;
struct ElifStmt;
struct ElseStmt;
struct FunArg;
// Definitions for above Node types

struct Expr : Node{
    string expr;
    Expr(){type = EXPR_TYPE; expr = "";}
    Expr(string express){type = EXPR_TYPE; expr = express;}
};

struct VarDecl : Node{
    string name;
    Expr value;
    VarDecl(string name_, string value_){
        name = name_;
        value = value_;
        type = VAR_DECLARATION;
    }
    VarDecl(){
        name = "";
        value = Expr();
        type = VAR_DECLARATION;

    }
};


struct VarAssign : Node{
    string name;
    Expr value;
    VarAssign(string name_, string value_){
        name = name_;
        value = value_;
        type = VAR_ASSIGNMENT;
    }
    VarAssign(){
        name = "";
        value = Expr();
        type = VAR_ASSIGNMENT;
    }
};

struct Block : Node{
    vector<string> statements;
    Block(){type = BLOCK;}
    Block(vector<string> statement){statements = statement;type = BLOCK;}
};

struct FunctionDecl : Node{
    string name;
    vector<string> params = {};
    Block body;
    FunctionDecl(){
        type = FUNCTION_DECL;
        name = "";
    }
    FunctionDecl(string name_, vector<string> params_){
        type = FUNCTION_DECL;
        name = name_;
        params = params_;
    }
};

struct ForLoop : Node{
    Expr condition;
    string iter_name;
    Block body;
    ForLoop(){type = FOR_LOOP;}
    ForLoop(string itername, Expr cond){type = FOR_LOOP;iter_name = itername;condition = cond;}
};

struct WhileLoop : Node{
    Expr condition;
    Block body;
    WhileLoop(){type = WHILE_LOOP;}
    WhileLoop(Expr cond){type = WHILE_LOOP;condition = cond;}
};

struct IfStmt : Node{
    Expr condition;
    Block body;
    IfStmt(){type = IF_STATEMENT;}
    IfStmt(Expr cond){type = IF_STATEMENT;condition = cond;}
};

struct ElifStmt : Node{
    Expr condition;
    Block body;
    ElifStmt(){type = ELIF_STATEMENT;}
    ElifStmt(Expr cond){type = ELIF_STATEMENT;condition = cond;}
};

struct ElseStmt : Node{
    Block body;
    ElseStmt(){type = ELSE_STATEMENT;}
};


//Functions to add nodes for ease of use.

Ptr<Node> addNode(VarDecl decl){
    auto node = make_shared<VarDecl>();
    node->name = decl.name;
    node->value = decl.value;
    return static_pointer_cast<Node>(node);
}

Ptr<Node> addNode(VarAssign decl){
    auto node = make_shared<VarAssign>();
    node->name = decl.name;
    node->value = decl.value;
    return static_pointer_cast<Node>(node);
}

Ptr<Node> addNode(Expr decl){
    auto node = make_shared<Expr>();
    node->expr = decl.expr;
    return static_pointer_cast<Node>(node);
}

Ptr<Node> addNode(Block decl){
    auto node = make_shared<Block>();
    node->statements = decl.statements;
    return static_pointer_cast<Node>(node);
}

Ptr<Node> addNode(FunctionDecl decl){
    auto node = make_shared<FunctionDecl>();
    node->body = decl.body;
    node->name = decl.name;
    node->params = decl.params;
    return static_pointer_cast<Node>(node);
}

void addStatement(Ptr<Block> block, string statement){
    block->statements.push_back(statement);
}
void addParam(Ptr<FunctionDecl> fun, string param){
    fun->params.push_back(param);
}


//Importing visitor containing all utilities to visit AST.
#include "visitor.h"

#endif // AST_Csq4_H