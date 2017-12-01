%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SymbolTable/TableVisitor.h"

extern "C" int yylex();

void yyerror(char *s)
{
    printf("ERROR %s\n", s);
}

Program* program;

%}

%union {
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
}

%locations

%token	CLASS
%token  VAR
%token	EXTENDS
%token	PUBLIC
%token  PRIVATE
%token	STATICVOIDMAIN
%token	STRING
%token	INT

%token	BOOLEAN
%token	IF
%token	ELSE
%token 	WHILE
%token	SYSTEMOUTPRINTLN
%token	LENGTH
%token	TRUE
%token	FALSE
%token	NEW
%token	THIS
%token	RETURN
%token	DIGIT
%token	LETER

%token	COMMENT

%token	L_BRACKET
%token	R_BRACKET
%token	L_ROUND
%token  R_ROUND
%token 	L_SQUARE
%token 	R_SQUARE

%token	SEMICOLON

%token 	MINUS
%token 	PLUS
%token 	PERCENT
%token 	DIVIDE
%token 	EQUALS

%token 	COMMA
%token 	DOT
%token 	STAR
%token 	LESS
%token 	BANG
%token	AND
%token  OR

%token  END 0

%token	<intVal>	INTEGER
%token 	<intVal>	BOOL_VAL
%token	<nameId> ID

%type<myId> id;
%type<program> goal;
%type<mainClass> main_class;
%type<classSeq> class_s;
%type<myClass> class;
%type<statementSeq> statement_s;
%type<mystatement> statement;
%type<expression> exp;
%type<expressions> exp_s;
%type<variable> var;
%type<variables> var_s;
%type<myMethod> method;
%type<methods> method_s;
%type<myType> type;
%type<args> arg_s;
%type<myModifier> modifier;

%left OR
%left AND
%left MINUS
%left PLUS
%left PERCENT
%left STAR
%left LESS
%left DOT
%left L_SQUARE
%right BANG

%%

goal  : main_class END                                                 {$$ = new Program($1, new Coordinates(yylloc.first_column, yylloc.first_line)); program = $$;}
      | main_class class_s END                                         {$$ = new Program($1, $2, new Coordinates(yylloc.first_column, yylloc.first_line)); program = $$;};


main_class  : CLASS id L_BRACKET
              PUBLIC STATICVOIDMAIN L_ROUND STRING L_SQUARE R_SQUARE id R_ROUND
              L_BRACKET statement_s R_BRACKET
              R_BRACKET                                                {$$ = new MainClass($2, $10, $13, new Coordinates(yylloc.first_column, yylloc.first_line));};


class_s  : class_s class                                               {$$ = new ClassDeclList($1, $2);}
         | class                                                       {$$ = new ClassDeclList($1);};


class   : CLASS id L_BRACKET R_BRACKET                                 {$$ = new ClassDecl($2, nullptr, new Coordinates(yylloc.first_column, yylloc.first_line));}
        | CLASS id L_BRACKET var_s R_BRACKET                           {$$ = new ClassDecl($2, nullptr, $4, new Coordinates(yylloc.first_column, yylloc.first_line));}
        | CLASS id L_BRACKET method_s R_BRACKET                        {$$ = new ClassDecl($2, nullptr, $4, new Coordinates(yylloc.first_column, yylloc.first_line));}
        | CLASS id L_BRACKET var_s method_s R_BRACKET                  {$$ = new ClassDecl($2, nullptr, $4, $5, new Coordinates(yylloc.first_column, yylloc.first_line));}
        | CLASS id EXTENDS id L_BRACKET R_BRACKET                      {$$ = new ClassDecl($2, $4, new Coordinates(yylloc.first_column, yylloc.first_line));}
        | CLASS id EXTENDS id L_BRACKET var_s R_BRACKET                {$$ = new ClassDecl($2, $4, $6, new Coordinates(yylloc.first_column, yylloc.first_line));}
        | CLASS id EXTENDS id L_BRACKET method_s R_BRACKET             {$$ = new ClassDecl($2, $4, $6, new Coordinates(yylloc.first_column, yylloc.first_line));}
        | CLASS id EXTENDS id L_BRACKET var_s method_s R_BRACKET       {$$ = new ClassDecl($2, $4, $6, $7, new Coordinates(yylloc.first_column, yylloc.first_line));};


var_s  : var_s var                                                     {$$ = new VarDeclList($1, $2);}
       | var                                                           {$$ = new VarDeclList($1);};


var  : type id SEMICOLON                                               {$$ = new VarDecl($1, $2, new Coordinates(yylloc.first_column, yylloc.first_line));};


method_s  : method_s method                                            {$$ = new MethodDeclList($1, $2);}
          | method                                                     {$$ = new MethodDeclList($1);};


method  : modifier type id L_ROUND arg_s R_ROUND
          L_BRACKET var_s statement_s RETURN exp SEMICOLON R_BRACKET   {$$ = new MethodDecl($1, $2, $3, $5, $8, $9, $11, new Coordinates(yylloc.first_column, yylloc.first_line));}
        | modifier type id L_ROUND arg_s R_ROUND
          L_BRACKET var_s RETURN exp SEMICOLON R_BRACKET               {$$ = new MethodDecl($1, $2, $3, $5, $8, nullptr, $10, new Coordinates(yylloc.first_column, yylloc.first_line));}
        | modifier type id L_ROUND arg_s R_ROUND
          L_BRACKET statement_s RETURN exp SEMICOLON R_BRACKET         {$$ = new MethodDecl($1, $2, $3, $5, nullptr, $8, $10, new Coordinates(yylloc.first_column, yylloc.first_line));}
        | modifier type id L_ROUND arg_s R_ROUND
          L_BRACKET RETURN exp SEMICOLON R_BRACKET                     {$$ = new MethodDecl($1, $2, $3, $5, nullptr, nullptr, $9, new Coordinates(yylloc.first_column, yylloc.first_line));};


arg_s  : %empty                                                        {$$ = new ArgDeclList();}
       | arg_s COMMA type id                                           {$$ = new ArgDeclList($1, $3, $4);}
       | type id                                                       {$$ = new ArgDeclList($1, $2);};


modifier  : PUBLIC                                                     {$$ = new MethodModifier("PUBLIC");}
          | PRIVATE                                                    {$$ = new MethodModifier("PRIVATE");};


type  : INT L_SQUARE R_SQUARE                                          {$$ = new BasicType(INT_ARRAY_);}
      |	BOOLEAN                                                        {$$ = new BasicType(BOOL_);}
      |	INT                                                            {$$ = new BasicType(INT_);}
      |	id                                                             {$$ = new ClassType($1);};


statement_s  : statement_s statement                                   {$$ = new StatementList($1, $2);}
             | statement                                               {$$ = new StatementList($1);};


statement  : L_BRACKET statement_s R_BRACKET                           {$$ = new Statements($2);}
           | IF L_ROUND exp R_ROUND statement ELSE statement           {$$ = new IfStatement($3, $5, $7, new Coordinates(yylloc.first_column, yylloc.first_line));}
           | WHILE L_ROUND exp R_ROUND statement                       {$$ = new WhileStatement($3, $5, new Coordinates(yylloc.first_column, yylloc.first_line));}
           | SYSTEMOUTPRINTLN L_ROUND exp R_ROUND SEMICOLON            {$$ = new PrintLineStatement($3, new Coordinates(yylloc.first_column, yylloc.first_line));}
           | id EQUALS exp SEMICOLON                                   {$$ = new AssignStatement($1, $3, new Coordinates(yylloc.first_column, yylloc.first_line));}
           | id L_SQUARE exp R_SQUARE EQUALS exp SEMICOLON             {$$ = new RandomAccessAssignStatement($1, $3, $6, new Coordinates(yylloc.first_column, yylloc.first_line));};


exp_s  : exp_s COMMA exp                                               {$$ = new ExprList($1, $3);}
       | exp                                                           {$$ = new ExprList($1);};


exp  : exp AND exp                                                     {$$ = new BinaryExpr($1, AND_T, $3, new Coordinates(yylloc.first_column, yylloc.first_line));}
        | exp LESS exp                                                 {$$ = new BinaryExpr($1, LESS_T, $3, new Coordinates(yylloc.first_column, yylloc.first_line));}
        | exp PLUS exp                                                 {$$ = new BinaryExpr($1, PLUS_T, $3, new Coordinates(yylloc.first_column, yylloc.first_line));}
        | exp MINUS exp                                                {$$ = new BinaryExpr($1, MINUS_T, $3, new Coordinates(yylloc.first_column, yylloc.first_line));}
        | exp STAR exp                                                 {$$ = new BinaryExpr($1, TIMES_T, $3, new Coordinates(yylloc.first_column, yylloc.first_line));}
        | exp PERCENT exp                                              {$$ = new BinaryExpr($1, MOD_T, $3, new Coordinates(yylloc.first_column, yylloc.first_line));}
        | exp OR exp                                                   {$$ = new BinaryExpr($1, OR_T, $3, new Coordinates(yylloc.first_column, yylloc.first_line));}
        | exp L_SQUARE exp R_SQUARE                                    {$$ = new RandomAccessExpr($1, $3, new Coordinates(yylloc.first_column, yylloc.first_line));}
        | exp DOT LENGTH                                               {$$ = new LengthExpr($1, new Coordinates(yylloc.first_column, yylloc.first_line));}
        | exp DOT id L_ROUND R_ROUND                                   {$$ = new CallMethodExpr($1, $3, nullptr, new Coordinates(yylloc.first_column, yylloc.first_line));}
        | exp DOT id L_ROUND exp_s R_ROUND                             {$$ = new CallMethodExpr($1, $3, $5, new Coordinates(yylloc.first_column, yylloc.first_line));}
        | INTEGER                                                      {$$ = new IntegerExpr(yylval.intVal, new Coordinates(yylloc.first_column, yylloc.first_line));}
        | TRUE                                                         {$$ = new TrueExpr(new Coordinates(yylloc.first_column, yylloc.first_line));}
        | FALSE                                                        {$$ = new FalseExpr(new Coordinates(yylloc.first_column, yylloc.first_line));}
        | id                                                           {$$ = $1;}
        | THIS                                                         {$$ = new ThisExpr(new Coordinates(yylloc.first_column, yylloc.first_line));}
        | NEW INT L_SQUARE exp R_SQUARE                                {$$ = new NewIntArrayExpr($4, new Coordinates(yylloc.first_column, yylloc.first_line));}
        | NEW id L_ROUND R_ROUND                                       {$$ = new NewObjectExpr($2, new Coordinates(yylloc.first_column, yylloc.first_line));}
        | BANG exp                                                     {$$ = new NotExpr($2, new Coordinates(yylloc.first_column, yylloc.first_line));}
        | L_ROUND exp R_ROUND                                          {$$ = $2;};


id  : ID                                                               {$$ = new Id(std::string(yylval.nameId), new Coordinates(yylloc.first_column, yylloc.first_line));};

%%
