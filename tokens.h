/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_BISON_TAB_HH_INCLUDED
# define YY_YY_BISON_TAB_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    END = 0,
    CLASS = 258,
    VAR = 259,
    EXTENDS = 260,
    PUBLIC = 261,
    PRIVATE = 262,
    STATICVOIDMAIN = 263,
    STRING = 264,
    INT = 265,
    BOOLEAN = 266,
    IF = 267,
    ELSE = 268,
    WHILE = 269,
    SYSTEMOUTPRINTLN = 270,
    LENGTH = 271,
    TRUE = 272,
    FALSE = 273,
    NEW = 274,
    THIS = 275,
    RETURN = 276,
    DIGIT = 277,
    LETER = 278,
    COMMENT = 279,
    L_BRACKET = 280,
    R_BRACKET = 281,
    L_ROUND = 282,
    R_ROUND = 283,
    L_SQUARE = 284,
    R_SQUARE = 285,
    SEMICOLON = 286,
    MINUS = 287,
    PLUS = 288,
    PERCENT = 289,
    DIVIDE = 290,
    EQUALS = 291,
    COMMA = 292,
    DOT = 293,
    STAR = 294,
    LESS = 295,
    BANG = 296,
    AND = 297,
    OR = 298,
    INTEGER = 299,
    BOOL_VAL = 300,
    ID = 301
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 22 "bison.yy" /* yacc.c:1909  */

    int intVal;
    char* nameId;
    Program *program;
    MainClass *mainClass;
    TrueExpr* mytrue;
    FalseExpr *myfalse;
    ClassDecl *myClass;
    VarDecl *variable;
    VarDeclList *variables;
    Expr *expression;
    ClassDeclList *classSeq;
    StatementList *statementSeq;
    Statements *statements;
    Statement *mystatement;
    ExprList *expressions;
    Id *myId;
    MethodModifier* myModifier;
    MethodDecl *myMethod;
    MethodDeclList *methods;
    Type *myType;
    ArgDeclList *args;
    BasicType *basicType;

#line 127 "bison.tab.hh" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_BISON_TAB_HH_INCLUDED  */
