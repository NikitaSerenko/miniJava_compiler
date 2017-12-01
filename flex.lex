%{
#include <stdlib.h>
#include "SyntaxTree/src/visitor.h"
#include "tokens.h"

int lineNumber = 1;
int columnNumber = 1;

void updateLocation(char* yytext)
{
	yylloc.first_line = lineNumber;
	yylloc.first_column = columnNumber;

	for( int i = 0; i < strlen(yytext); i++ ) {
		if( yytext[i] == '\n' ) {
			lineNumber++;
			columnNumber = 1;
		} else {
			columnNumber++;
		}
	}

	yylloc.last_line = lineNumber;
	yylloc.last_column = columnNumber;
}

#define YY_USER_ACTION updateLocation(yytext);

%}

%option c++

DIGIT [0-9]
LETTER [a-zA-Z_]
id {LETTER}({DIGIT}|{LETTER})*
IntegerLiteral [1-9]{DIGIT}*|0

%%
"class" 					return CLASS;
"var" 						return VAR;
"extends" 					return EXTENDS;
"public" 					return PUBLIC;
"private"					return PRIVATE;
"static void main" 			return STATICVOIDMAIN;
"String" 					return STRING;
"int" 						return INT;
"boolean" 					return BOOLEAN;
"if" 						return IF;
"else" 						return ELSE;
"while" 					return WHILE;
"System.out.println" 		return SYSTEMOUTPRINTLN;
"length" 					return LENGTH;
"true" 						return TRUE;
"false" 					return FALSE;
"new" 						return NEW;
"this" 						return THIS;
"return" 					return RETURN;

{LETTER}({DIGIT}|{LETTER})* 	{ yylval.nameId = yytext; return ID; }
[1-9]{DIGIT}*|0		            { yylval.intVal = atoi(yytext); return INTEGER; }
"//".* 						;
[ \t\n]+ 					;

"{" 						return L_BRACKET;
"}" 						return R_BRACKET;
"(" 						return L_ROUND;
")" 						return R_ROUND;
"\[" 						return L_SQUARE;
"\]" 						return R_SQUARE;

";" 						return SEMICOLON;

"-" 						return MINUS;
"+" 						return PLUS;
"%" 						return PERCENT;
"/" 						return DIVIDE;
"=" 						return EQUALS;

"," 						return COMMA;
"." 						return DOT;
"*" 						return STAR;
"<" 						return LESS;
"!" 						return BANG;

"&&" 						return AND;
"||"						return OR;

. 							printf("Error! Error text => (%s)", yytext);


%%

extern "C" {
  int yywrap();
}

int yyFlexLexer::yywrap() {
  return ::yywrap();
}

yyFlexLexer lexer;

extern "C" int yylex()
{
    return lexer.yylex();
}
