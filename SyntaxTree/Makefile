all: parser

parser: parser.o lex.o visitor.o
	g++ --std=c++11 -Wno-write-strings -o parser visitor.o lex.o parser.o -lfl

parser.o:  bison.yy
	bison -dt --verbose bison.yy && mv bison.tab.hh tokens.h && mv bison.tab.cc parser.cpp && g++ -c --std=c++11 parser.cpp -Wno-write-strings -o parser.o

lex.o: flex.lex
	flex++ flex.lex && g++ -c --std=c++11 lex.yy.cc -Wno-write-strings -o lex.o

visitor.o: src/pretty_printer.cpp src/declarations.cpp
	g++ -c --std=c++11 src/pretty_printer.cpp src/declarations.cpp -o visitor.o

clean:
	rm  lex.yy.cc parser.cpp tokens.h lex.o visitor.o parser.o parser
