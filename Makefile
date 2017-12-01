SYMBOL_TABLE_SRC_DIR = SymbolTable
SYMBOL_TABLE_SRC = $(wildcard $(SYMBOL_TABLE_SRC_DIR)/*.cpp)

SYMBOL_TABLE_OBJ = $(SYMBOL_TABLE_SRC:$(SYMBOL_TABLE_SRC_DIR)/%.cpp=./%.o)

all: tree table

table: $(SYMBOL_TABLE_OBJ) parser.o lex.o visitor.o table.o
	g++ -g --std=c++14 -Wno-write-strings -o table.exe $(SYMBOL_TABLE_OBJ) visitor.o parser.o lex.o table.o -lfl

table.o:
	g++ -g --std=c++14 -c table.cpp -o table.o

./%.o: $(SYMBOL_TABLE_SRC_DIR)/%.cpp
	g++ -g --std=c++14  -c $< -o $@

tree: parser.o lex.o visitor.o tree.o
	g++ -g --std=c++14 -Wno-write-strings -o tree.exe visitor.o parser.o lex.o tree.o -lfl

tree.o:
	g++ -g --std=c++14 -c tree.cpp -o tree.o

parser.o:  bison.yy
	bison -dt --verbose bison.yy && mv bison.tab.hh tokens.h && mv bison.tab.cc parser.cpp && g++ -g -c --std=c++14 parser.cpp -Wno-write-strings -o parser.o

lex.o: flex.lex
	flex++ flex.lex && g++ -g --std=c++11 -c lex.yy.cc -Wno-write-strings -o lex.o

visitor.o: SyntaxTree/src/pretty_printer.cpp
	g++ -g --std=c++14 -c SyntaxTree/src/pretty_printer.cpp -o visitor.o

clean:
	rm lex.o visitor.o parser.o tree.o tree.exe table.o table.exe parser.cpp tokens.h lex.yy.cc bison.output graph_output.gv
