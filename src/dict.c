#include<stdlib.h>
#include<string.h>
#define K 16 // chaining coefficient

// Custom Dictionary for 8086 Assembler - (C) Vivek Narayanan 2010

struct dict
{
	char *name; /* name of keyl */
	int val;   /* string value */
	struct dict *next; /* link field */
};

typedef struct dict dict;
dict *table[K];
int initialized = 0;

void  putval ( char *,int);

void init2() {
	/*0 operand opcodes */
		putval("ES:",0x26);
		putval("DAA",0x27);
		putval("CS:",0x2e);
		putval("DAS",0x2f);
		putval("SS:",0x36);
		putval("AAA",0x37);
		putval("DS:",0x3e);
		putval("AAS",0x3f);
		putval("NOP",0x90);
		putval("CBW",0x98);
		putval("CWD",0x99);
		putval("WAIT",0x9b);
		putval("PUSHF",0x9c);
		putval("POPF",0x9d);
		putval("SAHF",0x9e);
		putval("LAHF",0x9f);
		putval("MOVSB",0xa4);
		putval("MOVSW",0xa5);
		putval("CMPSB",0xa6);
		putval("CMPSW",0xa7);
		putval("STOSB",0xaa);
		putval("STOSW",0xab);
		putval("LODSB",0xac);
		putval("LODSW",0xad);
		putval("SCASB",0xae);
		putval("SCASW",0xaf);
		putval("RET",0xc3);
		putval("RETF",0xcb);
		putval("INTO",0xce);
		putval("IRET",0xcf);
		putval("XLAT",0xd7);
		putval("LOCK",0xf0);
		putval("REPNZ",0xf2);
		putval("REPZ",0xf3);
		putval("HLT",0xf4);
		putval("CMC",0xf5);
		putval("CLC",0xf8);
		putval("STC",0xf9);
		putval("CLI",0xfa);
		putval("STI",0xfb);
		putval("CLD",0xfc);
		putval("STD",0xfd);
		putval("es:",0x26);
		putval("daa",0x27);
		putval("cs:",0x2e);
		putval("das",0x2f);
		putval("ss:",0x36);
		putval("aaa",0x37);
		putval("ds:",0x3e);
		putval("aas",0x3f);
		putval("nop",0x90);
		putval("cbw",0x98);
		putval("cwd",0x99);
		putval("wait",0x9b);
		putval("pushf",0x9c);
		putval("popf",0x9d);
		putval("sahf",0x9e);
		putval("lahf",0x9f);
		putval("movsb",0xa4);
		putval("movsw",0xa5);
		putval("cmpsb",0xa6);
		putval("cmpsw",0xa7);
		putval("stosb",0xaa);
		putval("stosw",0xab);
		putval("lodsb",0xac);
		putval("lodsw",0xad);
		putval("scasb",0xae);
		putval("scasw",0xaf);
		putval("ret",0xc3);
		putval("retf",0xcb);
		putval("into",0xce);
		putval("iret",0xcf);
		putval("xlat",0xd7);
		putval("lock",0xf0);
		putval("repnz",0xf2);
		putval("repz",0xf3);
		putval("hlt",0xf4);
		putval("cmc",0xf5);
		putval("clc",0xf8);
		putval("stc",0xf9);
		putval("cli",0xfa);
		putval("sti",0xfb);
		putval("cld",0xfc);
		putval("std",0xfd);
	//1 operand opcodes (REGISTER)
		putval("push,es",0x06);
		putval("pop,es",0x07);
		putval("push,cs",0x0e);
		putval("push,ss",0x16);
		putval("push,ds",0x1e);
		putval("pop,ds",0x1f);
		putval("inc,ax",0x40);
		putval("inc,cx",0x41);
		putval("inc,dx",0x42);
		putval("inc,bx",0x43);
		putval("inc,sp",0x44);
		putval("inc,bp",0x45);
		putval("inc,si",0x46);
		putval("inc,di",0x47);
		putval("dec,ax",0x48);
		putval("dec,cx",0x49);
		putval("dec,dx",0x4a);
		putval("dec,bx",0x4b);
		putval("dec,sp",0x4c);
		putval("dec,bp",0x4d);
		putval("dec,si",0x4e);
		putval("dec,di",0x4f);
		putval("push,ax",0x50);
		putval("push,cx",0x51);
		putval("push,dx",0x52);
		putval("push,bx",0x53);
		putval("push,sp",0x54);
		putval("push,bp",0x55);
		putval("push,si",0x56);
		putval("push,di",0x57);
		putval("pop,ax",0x58);
		putval("pop,cx",0x59);
		putval("pop,dx",0x5a);
		putval("pop,bx",0x5b);
		putval("pop,sp",0x5c);
		putval("pop,bp",0x5d);
		putval("pop,si",0x5e);
		putval("pop,di",0x5f);
		
		putval("PUSH,ES",0x06);
		putval("POP,ES",0x07);
		putval("PUSH,CS",0x0e);
		putval("PUSH,SS",0x16);
		putval("PUSH,DS",0x1e);
		putval("POP,DS",0x1f);
		putval("INC,AX",0x40);
		putval("INC,CX",0x41);
		putval("INC,DX",0x42);
		putval("INC,BX",0x43);
		putval("INC,SP",0x44);
		putval("INC,BP",0x45);
		putval("INC,SI",0x46);
		putval("INC,DI",0x47);
		putval("DEC,AX",0x48);
		putval("DEC,CX",0x49);
		putval("DEC,DX",0x4a);
		putval("DEC,BX",0x4b);
		putval("DEC,SP",0x4c);
		putval("DEC,BP",0x4d);
		putval("DEC,SI",0x4e);
		putval("DEC,DI",0x4f);
		putval("PUSH,AX",0x50);
		putval("PUSH,CX",0x51);
		putval("PUSH,DX",0x52);
		putval("PUSH,BX",0x53);
		putval("PUSH,SP",0x54);
		putval("PUSH,BP",0x55);
		putval("PUSH,SI",0x56);
		putval("PUSH,DI",0x57);
		putval("POP,AX",0x58);
		putval("POP,CX",0x59);
		putval("POP,DX",0x5a);
		putval("POP,BX",0x5b);
		putval("POP,SP",0x5c);
		putval("POP,BP",0x5d);
		putval("POP,SI",0x5e);
		putval("POP,DI",0x5f);
	// 1op immediate		
		putval("INT,3",0xcc);
		putval("int,3",0xcc);
		putval("INT,ib",0xcd);
		putval("int,ib",0xcd);
		putval("RET,iw",0xc2);
		putval("RETF,iw",0xca);
		putval("ret,iw",0xc2);
		putval("retf,iw",0xca);
	// registers
		putval("AL",0x00);
		putval("CL",0x01);
		putval("DL",0x02);
		putval("BL",0x03);
		putval("AH",0x04);
		putval("CH",0x05);
		putval("DH",0x06);
		putval("BH",0x07);
		putval("AX",0x08);
		putval("CX",0x09);
		putval("DX",0x0A);
		putval("BX",0x0B);
		putval("SP",0x0C);
		putval("BP",0x0D);
		putval("SI",0x0E);
		putval("DI",0x0F);
		putval("al",0x0);
		putval("cl",0x1);
		putval("dl",0x2);
		putval("bl",0x3);
		putval("ah",0x4);
		putval("ch",0x5);
		putval("dh",0x6);
		putval("bh",0x7);
		putval("ax",0x8);
		putval("cx",0x9);
		putval("dx",0xa);
		putval("bx",0xb);
		putval("sp",0xc);
		putval("bp",0xd);
		putval("si",0xe);
		putval("di",0xf);
	/*Jump codes*/
		putval("JO",0x70);
		putval("jo",0x70);
		putval("JNO",0x71);
		putval("jno",0x71);
		putval("JB",0x72);
		putval("jb",0x72);
		putval("JNB",0x73);
		putval("jnb",0x73);
		putval("JZ",0x74);
		putval("jz",0x74);
		putval("JNZ",0x75);
		putval("jnz",0x75);
		putval("JBE",0x76);
		putval("jbe",0x76);
		putval("JA",0x77);
		putval("ja",0x77);
		putval("JS",0x78);
		putval("js",0x78);
		putval("JNS",0x79);
		putval("jns",0x79);
		putval("JPE",0x7A);
		putval("jpe",0x7A);
		putval("JPO",0x7B);
		putval("jpo",0x7B);
		putval("JL",0x7C);
		putval("jl",0x7C);
		putval("JGE",0x7D);
		putval("jge",0x7D);
		putval("JLE",0x7E);
		putval("jle",0x7E);
		putval("JG",0x7F);
		putval("jg",0x7F);
		putval("JMP",0xE9);
		putval("jmp",0xE9);
		putval("JMP",0xEA);
		putval("jmp",0xEA);
		putval("JMP",0xEB);
		putval("jmp",0xEB);	
		

}

void init_dict()
{	
	initialized = 1;
	int i;	
	for(i=0;i<K;i++)
		table[i] = (dict *)0;
	init2();
}

int getval (char *);


int hash (char *string) {
	int sum=0,m=0;
	char buf[100];
	strcpy(buf,string);
	for(m=0;buf[m]!='\0';m++)
		sum+=(int) buf[m];
	return sum%K;
}


void putval ( char *key_name,int sval )
{
	int hsh = hash(key_name);	
	dict *ptr;
	ptr = (dict *) malloc (sizeof(dict));
	ptr->name = (char *) malloc (strlen(key_name)+1);
	ptr->val = sval;
	strcpy (ptr->name,key_name);
	
	
	ptr->next = (struct dict *)table[hsh];
	table[hsh] = ptr;
	
}


int getval ( char *key_name )
{	
	int hsh = hash(key_name);	
	dict *ptr;
	for (ptr = table[hsh]; ptr != (dict *) 0;
		ptr = (dict *)ptr->next)
	if (strcmp (ptr->name,key_name) == 0)
		return ptr->val;
	return -1;
}

