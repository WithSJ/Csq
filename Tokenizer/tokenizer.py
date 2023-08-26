'''
Python implementation of Csq Tokenizer
'''
from ..Grammar.grammer import *
import re
# Type of Tokens  
class TokenType:
    KEYWORD = 1
    IDENTIFIER = 2
    STR = 3
    VALUE = 4
    SYMBOL = 5
    AROPERATOR = 6
    ASOPERATOR = 7
    COPERATOR = 8
    LOPERATOR = 9
    COMMENT =10
    INDENT = 11
    NEWLINE = 12
    ACCESS_OPERATOR = 13
    UNKNOWN = 14
    BLANK = 15

class STOKEN:
    LBRACE = 1
    RBRACE = 2
    LPAREN = 3
    RPAREN = 4
    LBRACK = 5
    RBRACK = 6
    PERCENT = 7
    EQUAL = 8
    TILDE = 9
    COMMA = 10
    GREATER = 11
    LESSER = 12
    SEMI = 13
    COLAN = 14
    PLUS = 15
    MINUS = 16
    STAR = 17
    BSLASH = 18
    HASHTAG = 19
    AMPER = 20
    VBAR = 21
    NOT = 22
    HAT = 23
    NOTSYMBOL = 24
    DOT = 25
    OR = 26
    AND = 27
    MOD = 28
    FSLASH = 29
    WALRUS = 30

class Token:
    def __init__(self,token:str, token_type:int) -> None:
        self.token = token
        self.type = token_type

def addToken(value:str,token_type:int) -> Token:
    token = Token()
    token.token = value
    token.type = token_type
    return token

# This Func not need in Python
# def _in(item:str,list:list) -> bool:
#     """Check Item is present in List"""
#     if item in list:
#         return True
#     else:
#         return False

def isIdentifier(val:str) -> bool:
    return re.match(pattern=IDENTIFIERS,string=val)

def isInt(val:str) -> bool:
    return re.match(pattern=INTEGER,string=val)

def isDecimal(val:str) -> bool:
    return re.match(pattern=DECIMAL,string=val)

def isValue(val:str) -> bool:
    if isDecimal(val) or isInt(val):
        return True
    else:
        return False

def isComment(val:str) -> bool:
    return val == "#"

def isLogicalOperator(val:str) -> bool:
    if val in LOGICAL_OPERATORS:
        return True
    else:
        return False

def isAssignmentOperator(val:str) -> bool:
    if val in ASSIGNMENT_OPERATORS:
        return True
    else:
        return False

def isComparisonOperator(val:str) -> bool:
    if val in COMPARISON_OPERATORS:
        return True
    else:
        return False

def isArithmeticOperator(val:str) -> bool:
    if val in ARITHMETIC_OPERATORS:
        return True
    else:
        return False

def isOperator(val:str) -> bool:
    if (isArithmeticOperator(val) or isLogicalOperator(val) or 
        isAssignmentOperator(val) or isComparisonOperator(val)):
        return True
    else:
        return False

def isSymbol(val:str) -> bool:
    if val in SYMBOLS:
        return True
    else:
        return False

def isSymbolLaterals(val:str) -> bool:
    if isSymbol(val) or isOperator(val):
        return True
    else:
        return False
    
def isKeyword(val:str) -> bool:
    if val in KEYWORDS_TABLE:
        return True
    else:
        return False
    
