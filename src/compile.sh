bison -d parser.y;
flex lexer.l;
cc  -o compiler parser.tab.c lex.yy.c;
