# Csq Abstract Syntax Tree (AST) Nodes

This document describes the various node types used in the Csq language's Abstract Syntax Tree. Each node represents a specific construct in the source code.

-   **`ExprNode`**: Represents any expression, such as `2 + 2`, `my_var`, or `get_value()`. The code generator translates this directly into its C++ equivalent.

-   **`VarDeclNode`**: Represents the declaration of a new variable, like `let x = 10;`.

-   **`VarAssignNode`**: Represents the assignment of a new value to an *existing* variable, like `x = 20;`.

-   **`BlockNode`**: Represents a block of code, typically enclosed in curly braces `{}` or defined by indentation. It contains a list of other statements.

-   **`FunDeclNode`**: Represents a global function declaration, like `fun my_func(a, b) { ... }`.

-   **`IfStmtNode`**: Represents an `if` statement and its condition.

-   **`ElifStmtNode`**: Represents an `else if` (or `elif`) statement and its condition.

-   **`ElseStmtNode`**: Represents an `else` block, which has no condition.

-   **`ForStmtNode`**: Represents a `for` loop, which iterates over a range or a collection.

-   **`WhileStmtNode`**: Represents a `while` loop, which executes as long as its condition is true.

-   **`CallNode`**: Represents a function or method call, like `my_func(1, 2)`.

-   **`PrintNode`**: Represents a built-in `print` statement for outputting values.

-   **`AccessNode`**: Represents accessing an element of a collection by its index, like `my_list[0]`.

-   **`CollectionUpdateNode`**: Represents updating an element of a collection at a specific index, like `my_list[0] = 5;`.

-   **`ReturnNode`**: Represents a `return` statement inside a function.

-   **`ImportNode`**: Represents an `import` statement for including other Csq modules.

-   **`CImportNode`**: Represents a special `cimport` statement for including C++ headers or libraries.

-   **`ClassNode`**: Represents a `class` declaration.

-   **`MethodNode`**: Represents a method declaration inside a class.

-   **`MemberVarDeclNode`**: Represents the declaration of a member variable (property) inside a class.

-   **`MemberVarAssignNode`**: Represents the assignment of a value to a class's member variable.

-   **`BreakNode`**: Represents a `break` statement used to exit a loop prematurely.

-   **`UnknownNode`**: A placeholder node for syntax that could not be parsed correctly.
