bison -d parser.y;
flex lexer.l;
cc  -g -o blitz-debug parser.tab.c lex.yy.c;
gdb blitz-debug
