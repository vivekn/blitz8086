#include<stdio.h>

int dec2hex(int n) {

	int i=0;
	while(n!=0){
	i = 16*i+(n & 0xff);
	n/=16;
	}
return i;
}


void main() {
	printf("%x",dec2hex(100));

}
