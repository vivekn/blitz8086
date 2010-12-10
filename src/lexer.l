
%x chst
%option noyywrap
let		[A-Za-z]
num 	[0-9]
hnum	[0-9a-f]
letn		[A-Za-z_]


%{
#include<stdio.h>
#include<stdlib.h>
#include "parser.tab.h"
char c=' ';
%}



%%
	
ES:	{
    yylval.id = (char *) yytext;
    return ZEROP;
    }
DAA	{
    yylval.id = (char *) yytext;
    return ZEROP;
    }
CS:	{
    yylval.id = (char *) yytext;
    return ZEROP;
    }
DAS	{
    yylval.id = (char *) yytext;
    return ZEROP;
    }
SS:	{
    yylval.id = (char *) yytext;
    return ZEROP;
    }
AAA	{
    yylval.id = (char *) yytext;
    return ZEROP;
    }
DS:	{
    yylval.id = (char *) yytext;
    return ZEROP;
    }
AAS	{
    yylval.id = (char *) yytext;
    return ZEROP;
    }
NOP	{
    yylval.id = (char *) yytext;
    return ZEROP;
    }
CBW	{
    yylval.id = (char *) yytext;
    return ZEROP;
    }
CWD	{
    yylval.id = (char *) yytext;
    return ZEROP;
    }
WAIT	{
    yylval.id = (char *) yytext;
    return ZEROP;
    }
PUSHF	{
    yylval.id = (char *) yytext;
    return ZEROP;
    }
POPF	{
    yylval.id = (char *) yytext;
    return ZEROP;
    }
SAHF	{
    yylval.id = (char *) yytext;
    return ZEROP;
    }
LAHF	{
    yylval.id = (char *) yytext;
    return ZEROP;
    }
MOVSB	{
    yylval.id = (char *) yytext;
    return ZEROP;
    }
MOVSW	{
    yylval.id = (char *) yytext;
    return ZEROP;
    }
CMPSB	{
    yylval.id = (char *) yytext;
    return ZEROP;
    }
CMPSW	{
    yylval.id = (char *) yytext;
    return ZEROP;
    }
STOSB	{
    yylval.id = (char *) yytext;
    return ZEROP;
    }
STOSW	{
    yylval.id = (char *) yytext;
    return ZEROP;
    }
LODSB	{
    yylval.id = (char *) yytext;
    return ZEROP;
    }
LODSW	{
    yylval.id = (char *) yytext;
    return ZEROP;
    }
SCASB	{
    yylval.id = (char *) yytext;
    return ZEROP;
    }
SCASW	{
    yylval.id = (char *) yytext;
    return ZEROP;
    }
RET	{
    yylval.id = (char *) yytext;
    return ZEROP;
    }
RETF	{
    yylval.id = (char *) yytext;
    return ZEROP;
    }
INTO	{
    yylval.id = (char *) yytext;
    return ZEROP;
    }
IRET	{
    yylval.id = (char *) yytext;
    return ZEROP;
    }
XLAT	{
    yylval.id = (char *) yytext;
    return ZEROP;
    }
LOCK	{
    yylval.id = (char *) yytext;
    return ZEROP;
    }
REPNZ	{
    yylval.id = (char *) yytext;
    return ZEROP;
    }
REPZ	{
    yylval.id = (char *) yytext;
    return ZEROP;
    }
HLT	{
    yylval.id = (char *) yytext;
    return ZEROP;
    }
CMC	{
    yylval.id = (char *) yytext;
    return ZEROP;
    }
CLC	{
    yylval.id = (char *) yytext;
    return ZEROP;
    }
STC	{
    yylval.id = (char *) yytext;
    return ZEROP;
    }
CLI	{
    yylval.id = (char *) yytext;
    return ZEROP;
    }
STI	{
    yylval.id = (char *) yytext;
    return ZEROP;
    }
CLD	{
    yylval.id = (char *) yytext;
    return ZEROP;
    }
STD	{
    yylval.id = (char *) yytext;
    return ZEROP;
    }
RETF	{
    yylval.id = (char *) yytext;
    return ZEROP;
    }
RET	{
    yylval.id = (char *) yytext;
    return ZEROP;
    }
PUSH	{
    yylval.id = (char *) yytext;
    return ONEOP;
    }
POP	{
    yylval.id = (char *) yytext;
    return ONEOP;
    }
INC	{
    yylval.id = (char *) yytext;
    return ONEOP;
    }
DEC	{
    yylval.id = (char *) yytext;
    return ONEOP;
    }
JO	{
    yylval.id = (char *) yytext;
    return JUMP;
    }
JNO	{
    yylval.id = (char *) yytext;
    return JUMP;
    }
JB	{
    yylval.id = (char *) yytext;
    return JUMP;
    }
JNB	{
    yylval.id = (char *) yytext;
    return JUMP;
    }
JZ	{
    yylval.id = (char *) yytext;
    return JUMP;
    }
JNZ	{
    yylval.id = (char *) yytext;
    return JUMP;
    }
JBE	{
    yylval.id = (char *) yytext;
    return JUMP;
    }
JA	{
    yylval.id = (char *) yytext;
    return JUMP;
    }
JS	{
    yylval.id = (char *) yytext;
    return JUMP;
    }
JNS	{
    yylval.id = (char *) yytext;
    return JUMP;
    }
JPE	{
    yylval.id = (char *) yytext;
    return JUMP;
    }
JPO	{
    yylval.id = (char *) yytext;
    return JUMP;
    }
JL	{
    yylval.id = (char *) yytext;
    return JUMP;
    }
JGE	{
    yylval.id = (char *) yytext;
    return JUMP;
    }
JLE	{
    yylval.id = (char *) yytext;
    return JUMP;
    }
JG	{
    yylval.id = (char *) yytext;
    return JUMP;
    }
CALL	{
    yylval.id = (char *) yytext;
    return ONEOP;
    }
INT	{
    yylval.id = (char *) yytext;
    return ONEOP;
    }
LOOPNZ	{
    yylval.id = (char *) yytext;
    return ONEOP;
    }
LOOPZ	{
    yylval.id = (char *) yytext;
    return ONEOP;
    }
LOOP	{
    yylval.id = (char *) yytext;
    return ONEOP;
    }
JCXZ	{
    yylval.id = (char *) yytext;
    return JUMP;
    }
JMP	{
    yylval.id = (char *) yytext;
    return JUMP;
    }
GRP3a	{
    yylval.id = (char *) yytext;
    return ONEOP;
    }
GRP3b	{
    yylval.id = (char *) yytext;
    return ONEOP;
    }
GRP4	{
    yylval.id = (char *) yytext;
    return ONEOP;
    }
GRP5	{
    yylval.id = (char *) yytext;
    return ONEOP;
    }
ADD	{
yylval.id = (char *) yytext;
    return MNEMONIC;
    }
OR	{
yylval.id = (char *) yytext;
    return MNEMONIC;
    }
ADC	{
yylval.id = (char *) yytext;
    return MNEMONIC;
    }
SBB	{
yylval.id = (char *) yytext;
    return MNEMONIC;
    }
AND	{
yylval.id = (char *) yytext;
    return MNEMONIC;
    }
SUB	{
yylval.id = (char *) yytext;
    return MNEMONIC;
    }
XOR	{
yylval.id = (char *) yytext;
    return MNEMONIC;
    }
CMP	{
yylval.id = (char *) yytext;
    return MNEMONIC;
    }
GRP1	{
yylval.id = (char *) yytext;
    return MNEMONIC;
    }
TEST	{
yylval.id = (char *) yytext;
    return MNEMONIC;
    }
XCHG	{
yylval.id = (char *) yytext;
    return MNEMONIC;
    }
MOV	{
yylval.id = (char *) yytext;
    return MNEMONIC;
    }
LEA	{
yylval.id = (char *) yytext;
    return MNEMONIC;
    }
POP	{
yylval.id = (char *) yytext;
    return MNEMONIC;
    }
TEST	{
yylval.id = (char *) yytext;
    return MNEMONIC;
    }
IN	{
yylval.id = (char *) yytext;
    return MNEMONIC;
    }
OUT	{
yylval.id = (char *) yytext;
    return MNEMONIC;
    }

,	{return COMMA;}
(a|b|c|d|A|B|C|D)(h|l|x|H|L|X)  {	yylval.id = (char *) yytext;
				return REGISTER;}
\'		   {BEGIN chst;}
<chst>[.\n\t] 	{c=*yytext;}
<chst>\'	 	{BEGIN 0;yylval.id = (char *) yytext;return CHAR;}
\[{hnum}+(h|H)\]	{yylval.id = (char *) yytext;return MEMADDR;}
\[{num}\]		{yylval.id = (char *) yytext;return MEMADDR;}
{hnum}+(h|H)		{yylval.id = (char *) yytext;return HEXSTR;}
{num}+		{yylval.id = (char *) yytext;return INT;}
:{letn}+			{yylval.id = (char *) yytext;return LABEL;}
;.*(\n|(\r\n))				/*Eat up comments*/
([ \t\n]|(\r\n)|(\n))				/*Eat up Whitespace*/
%%


main(int argc,char *argv[]) {
		
	if(argc>1)	{
		yyin=fopen(argv[1],"r");
		if (argc>2) 
			cg_set(argv[2]);
	}
	else {
		yyin=fopen("input.txt","r");
		cg_start();
		}
	//yyout=fopen("tempdump","w");
	int passes =0;
	init_dict();	
	
	reset_unres();
	do {
	reset_byte();
	fseek(yyin,0,0);
	yyparse();passes++;} while (chk_unres());
	printf("\nNo of Passes:%d",passes);
	printf("\nSize in Bytes:%d",get_ctr());
	
}

yyerror (char *s) {
printf("\nWhoops! something went wrong!\t%d:%s\n",yylineno,s);

}
