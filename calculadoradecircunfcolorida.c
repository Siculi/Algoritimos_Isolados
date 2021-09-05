#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#define Pi 3.141592

int main()
{
	setlocale(LC_ALL, "Portuguese");
	system("color 0A");
	char resp = 's'; 
	int num = 0;
	float valor, resul;
			
	do
		{
			valor = resul = 0;
			
			printf("\t>>> Calculadora de Circulos <<<");
			printf("\n\n");
			printf("1) Entre com o RAIO para descobrir a CIRCUNFERÊNCIA.");
			printf("\n----------------------------------------------------");
			printf("\n2) Entre com a CIRCUNFERÊNCIA para descobrir o RAIO.");
			printf("\n----------------------------------------------------");
			printf("\n\nEscolha uma opcão: ");
			scanf("%i", &num);
			printf("\n");
			
			switch(num)
				{
					case 1:
						printf("RAIO           = ");
						scanf("%f", &valor);
						resul = valor * 2 * Pi;
						printf("CIRCUNFERENCIA = %f",resul);	
						break;
						
					case 2:
						printf("CIRCUNFERENCIA = ");
						scanf("%f", &valor);
						resul = valor/(2*Pi);
						printf("RAIO           = %f", resul);
						break;
					
					default:
						printf("Nenhuma opcao escolhida.");
				}
			
			do
				{
					printf("\n\nFazer outro calculo [S/N]: ");
					scanf(" %c", &resp);
				}while(resp != 'S' && resp != 's' && resp != 'N' && resp != 'n');
				
			system("cls");
		}while(resp == 's' || resp == 'S');
	
	return 0;
}
