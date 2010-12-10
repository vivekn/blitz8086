/*

Reverse Byte Encoder
(C) Vivek Narayanan,2010

*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void encode (int array[],unsigned long num) {

	int i=0;
	for(i=0;num!=0;i++) {
		array[i] = num & 0xff;
		num>>=8;

	}
	
}



void decompose (int array[]) {
	int i;
	for(i=0;array[i]!=0;i++) 
		printf("%x ",array[i]);
		
}


