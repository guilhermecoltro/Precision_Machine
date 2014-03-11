#include <stdio.h>

float A=1;
float s=2;
float prec;

int main(){
	system("clear");

	while(s>1){
		A = A/2;
		s = 1+A;
	}

	
	prec = 2*A;
	printf("%0.11e\n", prec);
}
