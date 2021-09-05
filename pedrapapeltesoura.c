#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>

int main()
{
	// Pedra, Papel e Tesoura finalizado.
	
	setlocale(LC_ALL, "Portuguese");
	
	char resp;
	int i,j, pon_vc, pon_pc, emp;
	
	pon_vc = pon_pc = emp = 0;
	srand(time(NULL));
	
	do{
	
		do{
			printf("\tJokempô\n");
			printf("\n1) Pedra.");
			printf("\n2) Tesoura.");
			printf("\n3) Papel.");
			printf("\n\nEscolha: ");
			scanf("%i", &i);
			system("cls");
		}while(!(i==1 || i==2  || i==3)) ;
				
		j = rand()%3 + 1;
		
		printf("\tJokempô\n\nVc:");
	
		if(i==1)
		{
			printf("Pedra");
		}else
			{
				if(i==2)
			{
				printf("Tesoura");
			}else
				{
					printf("Papel");
				}
			}
	
		printf(" X PC:");
	
		if(j==1)
		{
			printf("Pedra");
		}else
			{
			if(j==2)
			{
				printf("Tesoura");
			}else
				{
					printf("Papel");
				}
			}
	
		printf("\n\n");
			
		if(i==j)
		{
			printf("!!! Empate !!!");
			emp = emp + 1;
		}else
			{
				if(i==1 && j==2)
				{
					printf("!!! Você Ganhou !!!");
					pon_vc = pon_vc + 1;
				}else
					{
						if(i==2 && j==3)
						{
							printf("!!! Você Ganhou !!!");
							pon_vc = pon_vc + 1;
						}else
							{
								if(i==3 && j==1)
								{
									printf("!!! Você Ganhou !!!");
									pon_vc = pon_vc + 1;
								}else
									{
										printf("!!! Você Perdeu !!!");
										pon_pc = pon_pc + 1;
									}
							}
					}
			}
	
	printf("\n\nDigite qualquer tecla para jogar de novo ou [N] para sair: ");
	scanf(" %c", &resp);
	
	system("cls");
	
	if(resp=='n'){resp = 'N';}
	
	}while(resp!='N');
	
	printf("- Score -\n");
	printf("\nEmpates:  %i", emp);
	printf("\nDerrotas: %i", pon_pc);
	printf("\nVitórias: %i", pon_vc);
	printf("\n\n");
	
	system("pause");
			
	return 0;
}
