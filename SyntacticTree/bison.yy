
%{
#include <stdio.h>
#include <string.h>

#include "src/printer.h"  


#define RED "\x1b[31m"
#define RESET "\x1b[0m"

extern "C" int yylex();

void yyerror(char *s) 
{
  printf (RED "%s\n" RESET, s);
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
goal  : main_class END                                                          {$$ = new Program((MainClass *)($1)); $$->accept(pp); printf("goal only\n");}
      | main_class class_s END                                                  {$$ = new Program((MainClass *)($1), (ClassDeclList *)($2)); $$->accept(pp); printf("goal\n");}
      ;

main_class  : CLASS id L_BRACKET
              PUBLIC STATICVOIDMAIN L_ROUND STRING L_SQUARE R_SQUARE id R_ROUND
              L_BRACKET statement_s R_BRACKET
              R_BRACKET                                                         {$$ = new MainClass((Id *)($2), (Id *)($10), (StatementList *)($13)); printf("main_class\n");}
            ;

class_s : class_s class                                                         {$$ = new ClassDeclList((ClassDeclList *)($1), (ClassDecl *)($2)); printf("classes\n");}
        | class                                                                 {$$ = new ClassDeclList((ClassDecl *)($1)); printf("classes\n");}
        ;

class   : CLASS id L_BRACKET R_BRACKET                         {$$ = new ClassDecl((Id *)($2), nullptr); printf("class (%s)\n", $2 );}
        | CLASS id L_BRACKET var_s R_BRACKET                   {$$ = new ClassDecl((Id *)($2), nullptr, (VarDeclList *)($4)); printf("class (%s) vars\n", $2 );}
        | CLASS id L_BRACKET method_s R_BRACKET                {$$ = new ClassDecl((Id *)($2), nullptr, (MethodDeclList *)($4)); printf("class (%s) methods\n", $2 );}
        | CLASS id L_BRACKET var_s method_s R_BRACKET          {$$ = new ClassDecl((Id *)($2), nullptr, (VarDeclList *)($4), (MethodDeclList *)($5)); printf("class (%s) vars methods\n", $2);}
        | CLASS id EXTENDS id L_BRACKET R_BRACKET                 {$$ = new ClassDecl((Id *)($2), (Id *)($4)); printf("class ext (%s)\n", $2 );}
        | CLASS id EXTENDS id L_BRACKET var_s R_BRACKET           {$$ = new ClassDecl((Id *)($2), (Id *)($4), (VarDeclList *)($6)); printf("class ext (%s) vars\n", $2 );}
        | CLASS id EXTENDS id L_BRACKET method_s R_BRACKET        {$$ = new ClassDecl((Id *)($2), (Id *)($4), (MethodDeclList *)($6)); printf("class ext (%s) methods\n", $2 );}
        | CLASS id EXTENDS id L_BRACKET var_s method_s R_BRACKET  {$$ = new ClassDecl((Id *)($2), (Id *)($4), (VarDeclList *)($6), (MethodDeclList *)($7)); printf("class ext(%s) vars methods\n", $2);}
        ;

var_s    : var_s var                                           {$$ = new VarDeclList((VarDeclList *)($1), (VarDecl *)($2)); printf("vars_vars\n");}
        | var                                                  {$$ = new VarDeclList((VarDecl *)($1)); printf("vars_var\n");}
        ;

var     : type id SEMICOLON                                    {$$ = new VarDecl((Type *)($1), (Id *)($2)); printf("var\n");}
        ;

method_s : method_s method                                     {$$ = new MethodDeclList((MethodDeclList *)($1), (MethodDecl *)($2)); printf("methods 1\n");}
        | method                                               {$$ = new MethodDeclList((MethodDecl *)($1)); printf("methods 2\n");}
        ;

method	:	modifier type id L_ROUND arg_s R_ROUND
          L_BRACKET var_s statement_s RETURN exp SEMICOLON R_BRACKET   {$$ = new MethodDecl((MethodModifier *)($1), (Type *)($2), (Id *)($3), (ArgDeclList *)($5), (VarDeclList *)($8), (StatementList *)($9), (Expr *)($11)); printf("method 1 (%s)\n", $3);}
        | modifier type id L_ROUND arg_s R_ROUND
        L_BRACKET var_s RETURN exp SEMICOLON R_BRACKET                 {$$ = new MethodDecl((MethodModifier *)($1),(Type *)($2), (Id *)($3), (ArgDeclList *)($5), (VarDeclList *)($8), nullptr, (Expr *)($10)); printf("method 2 (%s)\n", $3);}
        | modifier type id L_ROUND arg_s R_ROUND
        L_BRACKET statement_s RETURN exp SEMICOLON R_BRACKET           {$$ = new MethodDecl((MethodModifier *)($1),(Type *)($2), (Id *)($3), (ArgDeclList *)($5), nullptr, (StatementList *)($8), (Expr *)($10)); printf("method 3 (%s)\n", $3);}
        | modifier type id L_ROUND arg_s R_ROUND
        L_BRACKET RETURN exp SEMICOLON R_BRACKET                       {$$ = new MethodDecl((MethodModifier *)($1),(Type *)($2), (Id *)($3), (ArgDeclList *)($5), nullptr, nullptr, (Expr *)($9)); printf("method 4 (%s)\n", $3);}
        ;

arg_s    : %empty                      {$$ = new ArgDeclList();}
        | arg_s COMMA type id          {$$ = new ArgDeclList((ArgDeclList *)($1), (Type *)($3), (Id *)($4)); printf("args 2\n");}
        | type id                      {$$ = new ArgDeclList((Type *)($1), (Id *)($2)); printf("args 3\n");}
        ;

modifier: PUBLIC                       {$$ = new MethodModifier("PUBLIC"); printf("public\n");}
    | PRIVATE                          {$$ = new MethodModifier("PRIVATE"); printf("private\n");}
    ;

type	:	INT L_SQUARE R_SQUARE           {$$ = new BasicType(INT_ARRAY_); printf("int[]\n");}
		|	BOOLEAN                           {$$ = new BasicType(BOOL_); printf("boolean\n");}
		|	INT                               {$$ = new BasicType(INT_); printf("int\n");}
		|	id                                {$$ = new ClassType((Id *)($1)); printf("id\n");}
		;

statement_s:	statement_s statement      {$$ = new StatementList((StatementList *)($1), (Statement *)($2)); printf("statements 1\n");}
		|	statement                          {$$ = new StatementList((Statement *)($1)); printf("statements 2\n");}
		;

statement:	L_BRACKET statement_s R_BRACKET            {$$ = new Statements((StatementList *)($2)); printf("statement 1\n");}
		|	IF L_ROUND exp R_ROUND statement ELSE statement  {$$ = new IfStatement((Expr *)($3), (Statement *)($5), (Statement *)($7)); printf("statement 2 if\n");}
		|	WHILE L_ROUND exp R_ROUND statement              {$$ = new WhileStatement((Expr *)($3), (Statement *)($5)); printf("statement 3 while\n");}
		|	SYSTEMOUTPRINTLN L_ROUND exp R_ROUND SEMICOLON   {$$ = new PrintLineStatement((Expr *)($3)); printf("statement 4 sys out print\n");}
		|	id EQUALS exp SEMICOLON                          {$$ = new AssignStatement((Id *)($1), (Expr *)($3)); printf("statement 5 =\n");}
		|	id L_SQUARE exp R_SQUARE EQUALS exp SEMICOLON    {$$ = new RandomAccessAssignStatement((Id *)($1), (Expr *)($3), (Expr *)($6)); printf("statement 6 id[]=\n");}
		;

exp_s:	exp_s COMMA exp  {$$ = new ExprList((ExprList *)($1), (Expr *)($3)); printf("expressions 1\n");}
			|	exp              {$$ = new ExprList((Expr *)($1)); printf("expression 2\n");}
			;

exp : exp AND exp                       {$$ = new BinaryExpr((Expr *)($1), AND_T, (Expr *)($3)); printf("and\n");}
		|	exp LESS exp                      {$$ = new BinaryExpr((Expr *)($1), LESS_T, (Expr *)($3)); printf("less\n");}
		|	exp PLUS exp                      {$$ = new BinaryExpr((Expr *)($1), PLUS_T, (Expr *)($3)); printf("PLUS\n");}
		|	exp MINUS exp                     {$$ = new BinaryExpr((Expr *)($1), MINUS_T, (Expr *)($3)); printf("MINUS\n");}
		|	exp STAR exp                      {$$ = new BinaryExpr((Expr *)($1), TIMES_T, (Expr *)($3)); printf("*\n");}
		|	exp PERCENT exp                   {$$ = new BinaryExpr((Expr *)($1), MOD_T, (Expr *)($3)); printf("PERCENT\n");}
		|	exp OR exp                        {$$ = new BinaryExpr((Expr *)($1), OR_T, (Expr *)($3)); printf("or\n");}
		|	exp L_SQUARE exp R_SQUARE         {$$ = new RandomAccessExpr((Expr *)($1), (Expr *)($3)); printf("[ ]\n");}
		| exp DOT LENGTH                    {$$ = new LengthExpr((Expr *)($1)); printf("LENGTH\n");}
    | exp DOT id L_ROUND R_ROUND        {$$ = new CallMethodExpr((Expr *)($1), (Id *)($3), nullptr); printf("%s()\n", $3);/*call method*/}
		| exp DOT id L_ROUND exp_s R_ROUND  {$$ = new CallMethodExpr((Expr *)($1), (Id *)($3), (ExprList *)($5)); printf("%s()\n", $3);/*call method*/}
		| INTEGER                           {$$ = new IntegerExpr(yylval.intVal); printf("INTEGER\n");}
		| TRUE                              {$$ = new TrueExpr(); printf("true\n");}
		|	FALSE                             {$$ = new FalseExpr(); printf("false\n");}
		| id                                {$$ = $1; printf("id\n");}
		| THIS                              {$$ = new ThisExpr(); printf("THIS\n");}
		| NEW INT L_SQUARE exp R_SQUARE     {$$ = new NewIntArrayExpr((Expr *)($4)); printf("new int [exp]\n");}
		| NEW id L_ROUND R_ROUND            {$$ = new NewObjectExpr((Id *)($2)); printf("new (%s) ()\n", $2);}
		| BANG exp                          {$$ = new NotExpr((Expr *)($2)); printf("!exp\n");}
		| L_ROUND exp R_ROUND               {$$ = $2; printf("(exp)\n");}
		;

id 	:	ID                             {$$ = new Id(std::string(yylval.nameId)); printf("ID");} ;
%%

int main (void) {
//  yydebug=0;
  yyparse();
  delete pp;
}
