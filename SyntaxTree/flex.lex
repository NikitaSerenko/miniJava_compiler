%{
#include <stdlib.h>
#include "src/visitor.h"
#include "tokens.h"

void updateLocation(const char* yytext);

#define YY_USER_ACTION updateLocation(yytext);

int lineNumber = 1;
int columnNumber = 1;

void updateLocation(char* yytext)
{
	printf(" ");
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

%}

%option c++

DIGIT [0-9]
LETER [a-zA-Z_]
id {LETER}({DIGIT}|{LETER})*
IntegerLiteral [1-9]{DIGIT}*|0

%%
"true" 						return TRUE;
"false" 					return FALSE;
"public" 					return PUBLIC;
"private"					return PRIVATE;
"class" 					return CLASS;
"var" 						return VAR;
"extends" 					return EXTENDS;
"new" 						return NEW;
"this" 						return THIS;
"return" 					return RETURN;
"int" 						return INT;
"boolean" 					return BOOLEAN;
"length" 					return LENGTH;
"static void main" 			return STATICVOIDMAIN;
"String" 					return STRING;
"if" 						return IF;
"else" 						return ELSE;
"while" 					return WHILE;
"System.out.println" 		return SYSTEMOUTPRINTLN;




{LETER}({DIGIT}|{LETER})* 	{
								yylval.nameId = yytext;
								return ID;
							}

[1-9]{DIGIT}*|0		{
						yylval.intVal = atoi(yytext);
						return INTEGER;
					}
"//".* 						;
[ \t\n]+ 					;

"{" 						return L_BRACKET;
"}" 						return R_BRACKET;
"+" 						return PLUS;
"-" 						return MINUS;
"\[" 						return L_SQUARE;
"\]" 						return R_SQUARE;
"*" 						return STAR;
"<" 						return LESS;
"!" 						return BANG;
";" 						return SEMICOLON;
"%" 						return PERCENT;
"/" 						return DIVIDE;
"=" 						return EQUALS;
"&&" 						return AND;
"||"						return OR;
"," 						return COMMA;
")" 						return R_ROUND;
"(" 						return L_ROUND;
"." 						return DOT;

. 							printf("ERROR(%s)", yytext);


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
