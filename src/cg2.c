#include<stdio.h>
#include "dict.c"
#include "rbencode.c"
#define DEFAULT_PATH "a.bin"
#define VERBOSE 0
// Code Generator


FILE *fp;
void cg_start() {
	fp = fopen(DEFAULT_PATH,"wb");
}

void cg_set(char *s) {
	fp = fopen(s,"wb");

}

int decode_reg(char *s) {
	if (!initialized)
		init_dict();
	return getval(s);
}



int _rmcode(char *mnemonic) {
	if (!strcmp(mnemonic,"ADC"))
	return 002;
	else if (!strcmp(mnemonic,"ADD"))
	return 000;
	else if (!strcmp(mnemonic,"AND"))
	return -2;
	else if (!strcmp(mnemonic,"CMP"))
	return 007;
	else if (!strcmp(mnemonic,"MOV"))
	return 000;
	else if (!strcmp(mnemonic,"OR"))
	return 001;
	else if (!strcmp(mnemonic,"SBB"))
	return 003;
	else if (!strcmp(mnemonic,"SUB"))
	return 005;
	else if (!strcmp(mnemonic,"XOR"))
	return 110;
	else if (!strcmp(mnemonic,"adc"))
	return 002;
	else if (!strcmp(mnemonic,"add"))
	return 000;
	else if (!strcmp(mnemonic,"and"))
	return -2;
	else if (!strcmp(mnemonic,"cmp"))
	return 007;
	else if (!strcmp(mnemonic,"mov"))
	return 000;
	else if (!strcmp(mnemonic,"or"))
	return 001;
	else if (!strcmp(mnemonic,"sbb"))
	return 003;
	else if (!strcmp(mnemonic,"sub"))
	return 005;
	else if (!strcmp(mnemonic,"xor"))
	return 110;
	return -1;



}

int _opcode(char *mnemonic) {
	if (!strcmp(mnemonic,"adc"))
		return 004;
	else if (!strcmp(mnemonic,"add"))
		return 000;
	else if (!strcmp(mnemonic,"and"))
		return 010;
	else if (!strcmp(mnemonic,"cmp"))
		return 016;
	else if (!strcmp(mnemonic,"div"))
		return 075;
	else if (!strcmp(mnemonic,"idiv"))
		return 075;
	else if (!strcmp(mnemonic,"mul"))
		return 075;
	else if (!strcmp(mnemonic,"imul"))
		return 075;
	else if (!strcmp(mnemonic,"lds"))
		return 061;
	else if (!strcmp(mnemonic,"lea"))
		return 063;
	else if (!strcmp(mnemonic,"mov"))
		return 042;
	else if (!strcmp(mnemonic,"or"))
		return 002;
	else if (!strcmp(mnemonic,"sbb"))
		return 005;
	else if (!strcmp(mnemonic,"sub"))
		return 012;
	else if (!strcmp(mnemonic,"xor"))
		return 014;
	else if (!strcmp(mnemonic,"ADC"))
		return 004;
	else if (!strcmp(mnemonic,"ADD"))
		return 000;
	else if (!strcmp(mnemonic,"AND"))
		return 010;
	else if (!strcmp(mnemonic,"CMP"))
		return 016;
	else if (!strcmp(mnemonic,"DIV"))
		return 075;
	else if (!strcmp(mnemonic,"IDIV"))
		return 075;
	else if (!strcmp(mnemonic,"MUL"))
		return 075;
	else if (!strcmp(mnemonic,"IMUL"))
		return 075;
	else if (!strcmp(mnemonic,"LDS"))
		return 061;
	else if (!strcmp(mnemonic,"LEA"))
		return 063;
	else if (!strcmp(mnemonic,"MOV"))
		return 042;
	else if (!strcmp(mnemonic,"OR"))
		return 002;
	else if (!strcmp(mnemonic,"SBB"))
		return 005;
	else if (!strcmp(mnemonic,"SUB"))
		return 012;
	else if (!strcmp(mnemonic,"XOR"))
		return 014;
	return -1;
}

int iopcode(char * mnemonic) {
	
	if (!strcmp(mnemonic,"ADC"))
		return 0100;
	else if (!strcmp(mnemonic,"ADD"))
		return 0100;
	else if (!strcmp(mnemonic,"AND"))
		return 0100;
	else if (!strcmp(mnemonic,"CMP"))
		return 0100;
	else if (!strcmp(mnemonic,"MOV"))
		return 061;
	else if (!strcmp(mnemonic,"OR"))
		return 0100;
	else if (!strcmp(mnemonic,"SBB"))
		return 0100;
	else if (!strcmp(mnemonic,"SUB"))
		return 0100;
	else if (!strcmp(mnemonic,"XOR"))
		return 0100;
	else if (!strcmp(mnemonic,"adc"))
		return 0100;
	else if (!strcmp(mnemonic,"add"))
		return 0100;
	else if (!strcmp(mnemonic,"and"))
		return 0100;
	else if (!strcmp(mnemonic,"cmp"))
		return 0100;
	else if (!strcmp(mnemonic,"mov"))
		return 061;
	else if (!strcmp(mnemonic,"or"))
		return 0100;
	else if (!strcmp(mnemonic,"sbb"))
		return 0100;
	else if (!strcmp(mnemonic,"sub"))
		return 0100;
	else if (!strcmp(mnemonic,"xor"))
		return 0100;
	int ret = _opcode(mnemonic);
	if (ret!=-1)
		return ret;
	return -1;

}


int extr(char *);

struct code {
	
	unsigned opcode:6;
	unsigned s:1;
	unsigned w:1;
	unsigned mod:2;
	unsigned reg:3;
	unsigned rm:3;
	unsigned opc:8;
	unsigned imm8:8;
	unsigned dispa:8;
	unsigned dispb:8;
	unsigned imm16a:8;
	unsigned imm16b:8;
	

};


typedef struct code code;
code buffer;

void _clean() {
	buffer.opcode=0;
	buffer.s=0;
	buffer.w=0;
	buffer.mod=0;
	buffer.reg=0;
	buffer.rm=0;
	buffer.opc=0;
	buffer.imm8=0;
	buffer.dispa=0;
	buffer.dispb=0;
	buffer.imm16a=0;
	buffer.imm16b=0;
}





int code_0op(char *mnem){
	if (!initialized)
		init_dict();	
	int res = getval(mnem);
	if(res!=-1)
		putc(res,fp);
	return (res!=-1?1:0);


}

int code_1op(char *mnem,char *op) {
	
	char buf[20];
	strcpy(buf,mnem);
	strcat(buf,",");
	strcat(buf,op);
	int res = getval(buf);
	if(res!=-1)
		putc(res,fp);
	int codesize = (res!=-1?1:0);
	
	if(VERBOSE)
		printf("\nInstruction Result:%d",codesize);
	return codesize;	
}

int code_1op_imm(char *mnem,char * simm) {
	int imm = extr2(simm);//hex conv
	if (!initialized)
		init_dict();
	if (imm==3&&(!strcmp(mnem,"int")) || !(strcmp(mnem,"INT")))	{
		putc(0xcc,fp);
		if(VERBOSE)
		printf("\nInstruction Result:%d",1);
		return 1;
	}
	
	int w =((imm&0xff) == imm) ?0:1;
	int res;	
	char buf[20];
	strcpy(buf,mnem);
	strcat(buf,",");
	
	if(w)
		strcat(buf,"iw");
	else
		strcat(buf,"ib");
	res = getval(buf);
	if(res!=-1) {
		putc(res,fp);
		if(w){
			int mat[2];
			encode(mat,imm);
			putc(mat[0],fp);
			putc(mat[1],fp);
			if(VERBOSE)
				printf("\nInstruction Result:%d",3);
			return 3;
		}
		else {
			putc(imm,fp);
			if(VERBOSE)
		printf("\nInstruction Result:%d",2);
			return 2;
			}
	}
	else {
	//error handling	
	}
if(VERBOSE)
		printf("\nInstruction Result:%d",0);
return 0;
}
int code_1op_mem(char *mnem,char *ev) {
	int codesize=0;	
	buffer.mod=00;
	buffer.rm = (*(ev+1)=='B'||*(ev+1)=='b')?6:7;	
	
	if(!strcmp(mnem,"POP")||!(strcmp(mnem,"pop"))){
		buffer.reg = 0;
		buffer.opc = 0xaf;
		int xt = extr(ev);
		if (!xt){
			int tmp[2];
			encode(tmp,xt);
			buffer.dispa=tmp[0];
			buffer.dispb=tmp[1];
		}}
	if(!strcmp(mnem,"PUSH")||!(strcmp(mnem,"push"))){
		buffer.reg = 6;
		buffer.opc = 0xff;
			int xt = extr(ev);
		if (!xt){
			int tmp[2];
			encode(tmp,xt);
			buffer.dispa=tmp[0];
			buffer.dispb=tmp[1];
		}
	}
	if(buffer.opc){ 
		putc(byte1(buffer),fp);codesize++;}
	if(byte2(buffer)) {
		putc(byte2(buffer),fp);codesize++;}
	if(buffer.rm==7)	{
		putc(buffer.dispa,fp);
		putc(buffer.dispb,fp);
		codesize++;
	}
	_clean();

	if(VERBOSE)
		printf("\nInstruction Result:%d",codesize);
	return codesize;
}

int code_2op(char *mnem,char * sreg1,char * sreg2){
	int reg1 = getval(sreg1);
	int reg2 = getval(sreg2);
	int codesize = 0;	
	if(!((reg1+1)&&(reg2+1)))
		{if(VERBOSE)
		printf("\nInstruction Result:%d",codesize);
		return 0;}
	buffer.s = 0;
	buffer.w = reg1>7?1:0;
	buffer.mod = 3;
	buffer.rm = reg2;
	buffer.reg =reg1;
	int t_opcode = _opcode(mnem);
	if (t_opcode==-1){
	if(VERBOSE)
		printf("\nInstruction Result:%d",codesize);	return 0; }//insert some error handling code here
	buffer.opcode = t_opcode;
	if(byte1(buffer)) {
		putc(byte1(buffer),fp);codesize++;}	
	if(byte2(buffer)) {
		putc(byte2(buffer),fp);codesize++;}
	_clean();
	if(VERBOSE)
		printf("\nInstruction Result:%d",codesize);
	return codesize;
}
int code_2op_reg_imm(char *mnem,char * sreg1,int imm){
	int reg1 = getval(sreg1);
	int codesize = 0;
	//printf("\n%s:%d\n%s:%d",sreg1,reg1,reg2);
	if(!(reg1+1)){if(VERBOSE)
		printf("\nInstruction Result:%d",codesize);
		return 0;}
	buffer.s = 0;
	buffer.w = reg1>7?1:0;
	buffer.mod = 3;
	int t_rmcode = _rmcode(mnem);
	if(t_rmcode==-2)
		{
		if(reg1==0||reg1==4||reg1==8) {
			buffer.opcode = 011;			
			if(buffer.w){
				int mat[2];
				encode(mat,imm);
				putc(mat[0],fp);
				putc(mat[1],fp);
				codesize += 2;
			}
			else {
				putc(imm,fp);codesize++;}
			if(byte1(buffer)) {
				putc(byte1(buffer),fp);
				codesize++;}
		}
		if(VERBOSE)
		printf("\nInstruction Result:%d",codesize);
	return codesize;	
		}

	buffer.reg =reg1;
	int t_opcode = _opcode(mnem);
	if (t_opcode==-1||t_rmcode==-1)
		{if(VERBOSE)
		printf("\nInstruction Result:%d",codesize);return 0;} //insert some error handling code here
	buffer.opcode = t_opcode;
	buffer.rm = t_rmcode;
	if(byte1(buffer)) { 
		putc(byte1(buffer),fp);
		codesize++;
}	
	if(byte2(buffer)) {
		putc(byte2(buffer),fp);
		codesize++;}
	if(buffer.w){
			int mat[2];
			encode(mat,imm);
			putc(mat[0],fp);
			putc(mat[1],fp);codesize+=2;
		}
		else{
			putc(imm,fp);codesize++;}
	_clean();
	if(VERBOSE)
		printf("\nInstruction Result:%d",codesize);
	return codesize;
}

int code_2op_reg_mem(char *mnem,char * sreg1,char *ev)	{
	int reg1 = getval(sreg1);
	int codesize = 0;
	if(!(reg1+1)){
		return 0;if(VERBOSE)
		printf("\nInstruction Result:%d",codesize);}	
	buffer.w=1;
	buffer.s = 0;
	buffer.mod = 0;
	buffer.rm = (*(ev+1)=='B'||*(ev+1)=='b')?6:7;	
	buffer.reg =reg1;
	int xt = extr(ev);
		if (!xt){
			int tmp[2];
			encode(tmp,xt);
			buffer.dispa=tmp[0];
			buffer.dispb=tmp[1];
		}
	int t_opcode = _opcode(mnem);
	if (t_opcode==-1)
		return 0; //insert some error handling code here
	buffer.opcode = t_opcode;
	if(byte1(buffer)) {
		putc(byte1(buffer),fp);	codesize++;}
	if(byte2(buffer)) {
		putc(byte2(buffer),fp);codesize++;}
	if(buffer.rm==7)	{
		putc(buffer.dispa,fp);
		putc(buffer.dispb,fp);
		codesize+=2;
	}
	_clean();
}
int code_2op_mem_reg(char *mnem,char *ev,char *sreg1){
	int reg1 = getval(sreg1);
	int codesize=0;
	if(!(reg1+1)){if(VERBOSE)
		printf("\nInstruction Result:%d",codesize);
		return 0;}
	buffer.w=1;
	buffer.s = 1;
	buffer.mod = 0;
	buffer.rm = (*(ev+1)=='B'||*(ev+1)=='b')?6:7;	
	buffer.reg =reg1;
	int xt = extr(ev);
		if (!xt){
			int tmp[2];
			encode(tmp,xt);
			buffer.dispa=tmp[0];
			buffer.dispb=tmp[1];
		}
	int t_opcode = _opcode(mnem);
	if (t_opcode==-1)
{if(VERBOSE)
		printf("\nInstruction Result:%d",codesize);		return 0;} //insert some error handling code here
	buffer.opcode = t_opcode;
	if(byte1(buffer)) {
		putc(byte1(buffer),fp);codesize++;}
	if(byte2(buffer)) {
		putc(byte2(buffer),fp);codesize++;}
	if(buffer.rm==7)	{
		putc(buffer.dispa,fp);
		putc(buffer.dispb,fp);
		codesize+=2;
	}
	_clean();
	if(VERBOSE)
		printf("\nInstruction Result:%d",codesize);
	return codesize;
}	

int code_jump(char *mnem,int imm) {
	int codesize = 0;
//check size
	int w = imm>255?1:0;
	if (w) {
		if(strcmp(mnem,"jmp")==0||strcmp(mnem,"JMP")==0) {
			putc(0xe9,fp);
			codesize++;
			}
		else {
			putc(0x0f,fp);
			codesize++;
			 if(strcmp(mnem,"JO")==0||strcmp(mnem,"jo")==0) {
			putc(0x80,fp);
			codesize++;
		}else if(strcmp(mnem,"JNO")==0||strcmp(mnem,"jno")==0) {
			putc(0x81,fp);
			codesize++;
		}else if(strcmp(mnem,"JB")==0||strcmp(mnem,"jb")==0) {
			putc(0x82,fp);
			codesize++;
		}else if(strcmp(mnem,"JNB")==0||strcmp(mnem,"jnb")==0) {
			putc(0x83,fp);
			codesize++;
		}else if(strcmp(mnem,"JZ")==0||strcmp(mnem,"jz")==0) {
			putc(0x84,fp);
			codesize++;
		}else if(strcmp(mnem,"JNZ")==0||strcmp(mnem,"jnz")==0) {
			putc(0x85,fp);
			codesize++;
		}else if(strcmp(mnem,"JBE")==0||strcmp(mnem,"jbe")==0) {
			putc(0x86,fp);
			codesize++;
		}else if(strcmp(mnem,"JA")==0||strcmp(mnem,"ja")==0) {
			putc(0x87,fp);
			codesize++;
		}else if(strcmp(mnem,"JS")==0||strcmp(mnem,"js")==0) {
			putc(0x88,fp);
			codesize++;
		}else if(strcmp(mnem,"JNS")==0||strcmp(mnem,"jns")==0) {
			putc(0x89,fp);
			codesize++;
		}else if(strcmp(mnem,"JPE")==0||strcmp(mnem,"jpe")==0) {
			putc(0x8a,fp);
			codesize++;
		}else if(strcmp(mnem,"JPO")==0||strcmp(mnem,"jpo")==0) {
			putc(0x8b,fp);
			codesize++;
		}else if(strcmp(mnem,"JL")==0||strcmp(mnem,"jl")==0) {
			putc(0x8c,fp);
			codesize++;
		}else if(strcmp(mnem,"JGE")==0||strcmp(mnem,"jge")==0) {
			putc(0x8d,fp);
			codesize++;
		}else if(strcmp(mnem,"JLE")==0||strcmp(mnem,"jle")==0) {
			putc(0x8e,fp);
			codesize++;
		}else if(strcmp(mnem,"JG")==0||strcmp(mnem,"jg")==0) {
			putc(0x8f,fp);
			codesize++;
		}


		}
		int tmp[2];
		encode(tmp,imm);
		buffer.dispa=tmp[0];
		buffer.dispb=tmp[1];
		putc(buffer.dispa,fp);
		putc(buffer.dispb,fp);
		codesize+=2;
		
		

	}
	else {
		if(strcmp(mnem,"jmp")==0||strcmp(mnem,"JMP")==0) {
			putc(0xe9,fp);
			codesize++;
			}
		else if(strcmp(mnem,"JO")==0||strcmp(mnem,"jo")==0) {
			putc(0x70,fp);
			codesize++;
		}else if(strcmp(mnem,"JNO")==0||strcmp(mnem,"jno")==0) {
			putc(0x71,fp);
			codesize++;
		}else if(strcmp(mnem,"JB")==0||strcmp(mnem,"jb")==0) {
			putc(0x72,fp);
			codesize++;
		}else if(strcmp(mnem,"JNB")==0||strcmp(mnem,"jnb")==0) {
			putc(0x73,fp);
			codesize++;
		}else if(strcmp(mnem,"JZ")==0||strcmp(mnem,"jz")==0) {
			putc(0x74,fp);
			codesize++;
		}else if(strcmp(mnem,"JNZ")==0||strcmp(mnem,"jnz")==0) {
			putc(0x75,fp);
			codesize++;
		}else if(strcmp(mnem,"JBE")==0||strcmp(mnem,"jbe")==0) {
			putc(0x76,fp);
			codesize++;
		}else if(strcmp(mnem,"JA")==0||strcmp(mnem,"ja")==0) {
			putc(0x77,fp);
			codesize++;
		}else if(strcmp(mnem,"JS")==0||strcmp(mnem,"js")==0) {
			putc(0x78,fp);
			codesize++;
		}else if(strcmp(mnem,"JNS")==0||strcmp(mnem,"jns")==0) {
			putc(0x79,fp);
			codesize++;
		}else if(strcmp(mnem,"JPE")==0||strcmp(mnem,"jpe")==0) {
			putc(0x7a,fp);
			codesize++;
		}else if(strcmp(mnem,"JPO")==0||strcmp(mnem,"jpo")==0) {
			putc(0x7b,fp);
			codesize++;
		}else if(strcmp(mnem,"JL")==0||strcmp(mnem,"jl")==0) {
			putc(0x7c,fp);
			codesize++;
		}else if(strcmp(mnem,"JGE")==0||strcmp(mnem,"jge")==0) {
			putc(0x7d,fp);
			codesize++;
		}else if(strcmp(mnem,"JLE")==0||strcmp(mnem,"jle")==0) {
			putc(0x7e,fp);
			codesize++;
		}else if(strcmp(mnem,"JG")==0||strcmp(mnem,"jg")==0) {
			putc(0x7f,fp);
			codesize++;
		}
	putc(imm,fp);
	codesize++;	
	}


	if(VERBOSE)
		printf("\nInstruction Result:%d",codesize);
	return codesize;
}

int byte1(code a) {
	return (a.opcode&0x3f)*4+a.s*2+a.w;
}

int byte2(code a) {
	return (a.mod*64+a.reg * 8 + a.rm);
}

int extr(char *a) {
	char b[20],c[20]="0x";
	int len = strlen(a);
	int scale = a[len-2]=='h'?16:10;
	if(scale==16)	{
		
		sscanf(a,"[%s",b);
		len = strlen(b);
		b[len-2]='\0';
		
		return atoi(strcat(c,b));	
	}
	
	sscanf(a,"[%s",b);
	len = strlen(b);
	b[len-1]='\0';
	return atoi(b);
}

int extr2(char *a) {
	char b[20],c[20]="0x";
	int len = strlen(a);
	int scale = a[len-1]=='h'?16:10;
	if(scale==16)	{
		b[len-1]='\0';
		
		return atoi(strcat(c,b));	
	}
	b[len-1]='\0';
	return atoi(b);
}

