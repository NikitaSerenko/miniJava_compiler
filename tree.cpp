#include "SyntaxTree/src/pretty_printer.h"
#include "tokens.h"

extern Program *program;

int main(void) {
    yyparse();
    Printer *printer = new Printer("./SyntaxTree.gv");
    program->accept(printer);
    delete printer;
}