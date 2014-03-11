#include <stdio.h>

double A;
double s;
double VAL[8] = {10, 17, 100, 184, 1000, 1575, 10000, 17893};

void calcPrec(double *a,double *S,double *valor){
	*a = 1;
	*S = *valor + *a;

	while(*S > *valor){
		*a = *a/2;
		*S = *valor + *a;
	}

        double  prec = (*a)*2;
        printf("VAL = %0.0f\n",*valor);
        printf("PREC = %0.11e\n", prec);
}

int main(){
        system("clear");
	
	int i;
	for(i=0; i<8; i++){
		calcPrec(&A, &s, &VAL[i]);	
	}
}
