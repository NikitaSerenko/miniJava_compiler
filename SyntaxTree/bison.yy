
%{
#include <stdio.h>
#include <string.h>

#include "src/pretty_printer.h"  

extern "C" int yylex();

void yyerror(char *s) 
{
  printf ("%s\n", s);
}

Printer *pp = new Printer("./graph.gv");
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
goal  : main_class END 			{$$ = new Program((MainClass *)($1)); $$->accept(pp); printf("goal only\n");}
      | main_class class_s END 	{$$ = new Program((MainClass *)($1), (ClassDeclList *)($2)); $$->accept(pp); printf("goal\n");}
      ;

main_class  : CLASS id L_BRACKET
              PUBLIC STATICVOIDMAIN L_ROUND STRING L_SQUARE R_SQUARE id R_ROUND
              L_BRACKET statement_s R_BRACKET
              R_BRACKET 		{$$ = new MainClass((Id *)($2), (Id *)($10), (StatementList *)($13));}
            ;

class_s : class_s class 		{$$ = new ClassDeclList((ClassDeclList *)($1), (ClassDecl *)($2));}
        | class 				{$$ = new ClassDeclList((ClassDecl *)($1));}
        ;

class   : CLASS id L_BRACKET R_BRACKET 								{$$ = new ClassDecl((Id *)($2), nullptr);}
        | CLASS id L_BRACKET var_s R_BRACKET 						{$$ = new ClassDecl((Id *)($2), nullptr, (VarDeclList *)($4));}
        | CLASS id L_BRACKET method_s R_BRACKET 					{$$ = new ClassDecl((Id *)($2), nullptr, (MethodDeclList *)($4));}
        | CLASS id L_BRACKET var_s method_s R_BRACKET 				{$$ = new ClassDecl((Id *)($2), nullptr, (VarDeclList *)($4), (MethodDeclList *)($5));}
        | CLASS id EXTENDS id L_BRACKET R_BRACKET 					{$$ = new ClassDecl((Id *)($2), (Id *)($4)); printf("class ext (%s)\n", $2 );}
        | CLASS id EXTENDS id L_BRACKET var_s R_BRACKET 			{$$ = new ClassDecl((Id *)($2), (Id *)($4), (VarDeclList *)($6));}
        | CLASS id EXTENDS id L_BRACKET method_s R_BRACKET 			{$$ = new ClassDecl((Id *)($2), (Id *)($4), (MethodDeclList *)($6));}
        | CLASS id EXTENDS id L_BRACKET var_s method_s R_BRACKET 	{$$ = new ClassDecl((Id *)($2), (Id *)($4), (VarDeclList *)($6), (MethodDeclList *)($7));}
        ;

var_s    : var_s var 			{$$ = new VarDeclList((VarDeclList *)($1), (VarDecl *)($2)); }
        | var     				{$$ = new VarDeclList((VarDecl *)($1));}
        ;

var     : type id SEMICOLON 	{$$ = new VarDecl((Type *)($1), (Id *)($2));}
        ;

method_s : method_s method 		{$$ = new MethodDeclList((MethodDeclList *)($1), (MethodDecl *)($2));}
        | method  				{$$ = new MethodDeclList((MethodDecl *)($1));}
        ;

method	:	modifier type id L_ROUND arg_s R_ROUND
          L_BRACKET var_s statement_s RETURN exp SEMICOLON R_BRACKET   {$$ = new MethodDecl((MethodModifier *)($1), (Type *)($2), (Id *)($3), (ArgDeclList *)($5), (VarDeclList *)($8), (StatementList *)($9), (Expr *)($11));}
        | modifier type id L_ROUND arg_s R_ROUND
        L_BRACKET var_s RETURN exp SEMICOLON R_BRACKET                 {$$ = new MethodDecl((MethodModifier *)($1),(Type *)($2), (Id *)($3), (ArgDeclList *)($5), (VarDeclList *)($8), nullptr, (Expr *)($10));}
        | modifier type id L_ROUND arg_s R_ROUND
        L_BRACKET statement_s RETURN exp SEMICOLON R_BRACKET           {$$ = new MethodDecl((MethodModifier *)($1),(Type *)($2), (Id *)($3), (ArgDeclList *)($5), nullptr, (StatementList *)($8), (Expr *)($10));}
        | modifier type id L_ROUND arg_s R_ROUND
        L_BRACKET RETURN exp SEMICOLON R_BRACKET                       {$$ = new MethodDecl((MethodModifier *)($1),(Type *)($2), (Id *)($3), (ArgDeclList *)($5), nullptr, nullptr, (Expr *)($9));}
        ;

arg_s    : %empty                      {$$ = new ArgDeclList();}
        | arg_s COMMA type id          {$$ = new ArgDeclList((ArgDeclList *)($1), (Type *)($3), (Id *)($4));}
        | type id                      {$$ = new ArgDeclList((Type *)($1), (Id *)($2));}
        ;

modifier: PUBLIC                       {$$ = new MethodModifier("PUBLIC");}
    | PRIVATE                          {$$ = new MethodModifier("PRIVATE");}
    ;

type	:	INT L_SQUARE R_SQUARE           {$$ = new BasicType(INT_ARRAY_);}
		|	BOOLEAN                           {$$ = new BasicType(BOOL_);}
		|	INT                               {$$ = new BasicType(INT_);}
		|	id                                {$$ = new ClassType((Id *)($1));}
		;

statement_s:	statement_s statement      {$$ = new StatementList((StatementList *)($1), (Statement *)($2));}
		|	statement                          {$$ = new StatementList((Statement *)($1));}
		;

statement:	L_BRACKET statement_s R_BRACKET            {$$ = new Statements((StatementList *)($2)); printf("statement 1\n");}
		|	IF L_ROUND exp R_ROUND statement ELSE statement  {$$ = new IfStatement((Expr *)($3), (Statement *)($5), (Statement *)($7));}
		|	WHILE L_ROUND exp R_ROUND statement              {$$ = new WhileStatement((Expr *)($3), (Statement *)($5));}
		|	SYSTEMOUTPRINTLN L_ROUND exp R_ROUND SEMICOLON   {$$ = new PrintLineStatement((Expr *)($3));}
		|	id EQUALS exp SEMICOLON                          {$$ = new AssignStatement((Id *)($1), (Expr *)($3));}
		|	id L_SQUARE exp R_SQUARE EQUALS exp SEMICOLON    {$$ = new RandomAccessAssignStatement((Id *)($1), (Expr *)($3), (Expr *)($6));}
		;

exp_s:	exp_s COMMA exp  		{$$ = new ExprList((ExprList *)($1), (Expr *)($3));}
			|	exp 			{$$ = new ExprList((Expr *)($1));}
			;

exp : exp AND exp 							{$$ = new BinaryExpr((Expr *)($1), AND_T, (Expr *)($3));}
		|	exp LESS exp  					{$$ = new BinaryExpr((Expr *)($1), LESS_T, (Expr *)($3));}
		|	exp PLUS exp  					{$$ = new BinaryExpr((Expr *)($1), PLUS_T, (Expr *)($3));}
		|	exp MINUS exp 					{$$ = new BinaryExpr((Expr *)($1), MINUS_T, (Expr *)($3));}
		|	exp STAR exp  					{$$ = new BinaryExpr((Expr *)($1), TIMES_T, (Expr *)($3));}
		|	exp PERCENT exp 				{$$ = new BinaryExpr((Expr *)($1), MOD_T, (Expr *)($3));}
		|	exp OR exp 						{$$ = new BinaryExpr((Expr *)($1), OR_T, (Expr *)($3));}
		|	exp L_SQUARE exp R_SQUARE 		{$$ = new RandomAccessExpr((Expr *)($1), (Expr *)($3));}
		| exp DOT LENGTH 					{$$ = new LengthExpr((Expr *)($1));}
    | exp DOT id L_ROUND R_ROUND 			{$$ = new CallMethodExpr((Expr *)($1), (Id *)($3), nullptr);}
		| exp DOT id L_ROUND exp_s R_ROUND  {$$ = new CallMethodExpr((Expr *)($1), (Id *)($3), (ExprList *)($5));}
		| INTEGER                           {$$ = new IntegerExpr(yylval.intVal);}
		| TRUE                              {$$ = new TrueExpr();}
		|	FALSE  							{$$ = new FalseExpr();}
		| id                                {$$ = $1;}
		| THIS                              {$$ = new ThisExpr();}
		| NEW INT L_SQUARE exp R_SQUARE     {$$ = new NewIntArrayExpr((Expr *)($4));}
		| NEW id L_ROUND R_ROUND            {$$ = new NewObjectExpr((Id *)($2));}
		| BANG exp                          {$$ = new NotExpr((Expr *)($2));}
		| L_ROUND exp R_ROUND               {$$ = $2;}
		;

id 	:	ID 						{$$ = new Id(std::string(yylval.nameId)); printf("ID");} ;
%%

int main (void) {
  yyparse();
  delete pp;
}
