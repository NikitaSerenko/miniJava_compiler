#include "SymbolTable/TableVisitor.h"
#include "tokens.h"


extern Program *program;

int main(void) {
    yyparse();
    TableVisitor visitor;
    visitor.ParseProgram(program);
}