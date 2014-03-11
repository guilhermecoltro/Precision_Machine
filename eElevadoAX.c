#include <stdio.h>
#include <math.h>

//Constantes de Configuração
#define al 8 //Constante definindo tamando do vetor x
#define semN 0//Constante responsável por dizer se a conta será feita ou não com um limite : 0 - Com Limite /  1 - Sem Limite
#define inc 10 //Constante definindo valor a ser incrementado a n a cada volta do loop
#define max 100 //Constante definindo valor maximo de n

double x[al]= {2 , 4, 6, 8, 10, 12, 14, 16};//Vetor que receberá os valores de "x"
//Fim Configuração

int n;

double theCutter(int base, int fat){
        int potencia[fat];
        int fatorial[fat];
        double pote=1 , fato=1;

        int i=0, j=0;

        for(i=0; i<fat; i++){
                fatorial[i] = fat - i;
                potencia[i] = base;
        }

        for(i=0; i<fat; i++){
                for(j=0; j<fat; j++){
                        if(fatorial[i]%potencia[j]==0 && potencia[j]!=1){
                                fatorial[i] /= potencia[j];
                                potencia[j] = 1;
                        }
                }
        }

        for(i=0; i<fat; i++){
                pote *= potencia[i];
                fato *= fatorial[i];
        }


        return pote/fato;
}

double serieTaylor(int n, double x){
	int i;
	double sum =0;

	for(i=0; i<n; i++){
	        sum += theCutter((int) x, i);
	}

	return sum;
}

double serieTaylorSemN(double x){

	int i, control = 1;
	double soma = 1, check = 0;

	for(i=1;control==1; i++){
		check = (soma+theCutter((int) x, i));            

		if(check==soma){
			control = 0; 
		}
		else{
			soma += theCutter((int) x, i);
		}
	}
	return soma;
}

double calcEXNegativo(int terms, double value){
	return (1/(serieTaylor(terms, sqrt(pow(value, 2)))));
}

double calcEXNegativoSemN(double value){
	return (1/(serieTaylorSemN(sqrt(pow(value, 2)))));
}

void negativo(){
	
	int i=0;

	if(semN == 0){
		printf("x \tn \tResultado - Série \tResultado - Inversão  \t Diferença (Inversão - Série) \n");		

	        for(i=0; i<al; i++){
        	        for(n=1; n<max; n+=inc){
                	        printf("%d \t%d \t%0.17e \t%0.17e \t%0.17e \n",(int) x[i], n, serieTaylor(n, x[i]), calcEXNegativo(n, x[i]), (calcEXNegativo(n, x[i]) - serieTaylor(n, x[i])));
                	}
        	}
	}
	else{
		printf("x \tResultado - Série \tResultado - Inversão \tDiferença(Inversão - Série)\n");	
	
		for(i=0; i<al; i++){
			printf("%d \t%0.17e \t%0.17e \t%0.17e \n", (int) x[i],  serieTaylorSemN(x[i]), calcEXNegativoSemN(x[i]), (calcEXNegativoSemN(x[i]) - serieTaylorSemN(x[i])));
		}
	}

}

void positivo(){

	int i=0;

	if(semN == 0){
	        printf("x \tn \tResultado \n");

	        for(i=0; i<al; i++){
        	        for(n=1; n<max; n+=inc){
                	        printf("%d \t%d \t%0.17e \n",(int) x[i], n, serieTaylor(n, x[i]));
	                }
	        }
	}
	else{
		printf("x \tResultado \n");
		
		for(i=0; i<al; i++){
			printf("%d \t%0.17e \n", (int) x[i], serieTaylorSemN(x[i]));
		}
	}

}

int checkArray(double *array){
	
	if(al == 0){
		return -2;
	}

	if(inc < 0 || inc == 0){
		return -3;
	}

	double k = array[0];
	int i;

	
	if(k<0){
		for(i=1; i<al; i++){
			if(array[i]>0){
				return -1;
			}
		}
	}
	else{
		for(i=1; i<al; i++){
			if(array[i]<0){
				return -1;
			}
		}
	}

	return 0;
	
}


int main(){

	system("clear");
	
	if(checkArray(x) != 0){
		if(checkArray(x) == -1){
			puts("ERRO: O Vetor Possui Variáveis de sinais Opostos!");
		}
		else if(checkArray(x) == -2){
			puts("ERRO: O Array encontra-se vazio!");
		}
		else{
			puts("ERRO: O Número de termos deve ser maior do que zero!");
		}
	}
	else{
		if(x[0] < 0){
			negativo();
		}
		else{
			positivo();
		}
	}
	
}
