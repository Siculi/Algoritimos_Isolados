#include <stdio.h>
#include <stdlib.h>

int main(){
	
	/*
		Este algoritmo conta a quantidade de numero pares e impares dentro de uma intervalo dos Naturais.
		Onde; 
			A1 é o primeiro valor da sequencia e 
			An o ultimo valor da sequencia
	*/
	
	int x           = 0;
	int valDigitado = 0;
	int aux = 0, auxif;
	int cp, ci;
	char resp;
	
	cp = ci = 0; resp = 's';
	
	printf("\t\t!!!Contador de Pares e Impares!!!\n");
	
	while(resp == 's' || resp == 'S')
	{
		printf("\n===================================================================\n");				
		printf("\nDigite o A1 da sequencia: ");
		scanf("%i", &x);
		printf("Digite o An da sequencia: ");
		scanf("%i", &valDigitado);

		if(x>valDigitado)
		{
			auxif = valDigitado;
			valDigitado = x;
			x = auxif;
		}
	
		aux = x;
	
		printf("\nPares: ");
		while(x<=valDigitado)
		{
			if((x%2)==0)
			{
				if(x == valDigitado || x == valDigitado - 1)
				{
					printf("%i.", x);
				}else{printf("%i, ", x);}
				cp = cp + 1;
			}
			x = x + 1;
		}
	
			x = aux;
	
		printf("\n\nImpares: ");
		
		while(x<=valDigitado)
		{
			if((x%2)!=0)
			{
				if(x == valDigitado || x == valDigitado - 1)
				{
					printf("%i.", x);
				}else{printf("%i, ", x);}
				ci = ci + 1;
			}
			x = x + 1;
		}
	
		printf("\n\nNumero de Pares:   %i",cp);
		printf("\nNumero de Impares: %i",ci);
		printf("\n---------------------");
		printf("\nTotal:             %i", ci+cp);
		printf("\n\n===================================================================");
						
		printf("\n\nRepetir [S/N]: ");
		scanf(" %c", &resp);
			
		while(resp != 's' && resp != 'S' && resp != 'n' && resp != 'N')
		{
			printf("A letra %c nao e aceita. Repetir [S/N]: ", resp);
			scanf(" %c", &resp);
		}
				
		cp = ci = 0;
				
		}
	
	return 0;
}
