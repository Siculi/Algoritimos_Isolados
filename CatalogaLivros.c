/*
	Fa�a um programa que cria uma estrutura chamada livro, que cont�m os elementos: 
	t�tulo, autor, ano de edi��o, n�mero de p�ginas e pre�o. Crie uma vari�vel desta estrutura que � um vetor de 10 elementos. 
	O programa deve ler os valores para a estrutura e imprimir a m�dia do n�mero de p�ginas dos livros 
	e a quantidade de livros de cada autor.

*/
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h> 
#include <conio.h>

#define TAMANHO 10

struct livro
	{
		char titulo[50], autor[50];
		int ano_edicao;
		float num_pag, preco;
	}; 

struct incidencia
	{
		char autor_uni[50];
	};

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	int k, i, j, t_aux, quebra; t_aux = quebra = 0;
	char aux[50];
	float conta_obra[TAMANHO], conta_pag[TAMANHO], media = 0; 
	
	struct livro ficha_livros[TAMANHO];
	struct incidencia unicos[TAMANHO];
	
	printf("  ----------------------------------------\n");
	printf("\n\t<<< Cat�logo de Livros >>>\n\n");
		
	for(k=0;k<TAMANHO;k++)
	{
		printf("  ----------------------------------------\n");	printf(" - %i� Livro.\n\n", k+1);
		
		printf("\t * T�tulo: "); 
		fgets(ficha_livros[k].titulo,50,stdin);
		
		printf("\t * Autor: ");	
		fgets(ficha_livros[k].autor,50,stdin);		
		
		printf("\t * Ano de Edi��o: "); 
		scanf("%i", &ficha_livros[k].ano_edicao);
		
		printf("\t * N�mero de P�ginas: "); 
		scanf("%f", &ficha_livros[k].num_pag);
		
		printf("\t * Pre�o: "); 
		scanf("%f", &ficha_livros[k].preco);
		
		media = media + ficha_livros[k].num_pag;
		
		fflush(stdin); printf("\n");	
	}

printf("  ----------------------------------------\n\n");

// O algortimo abaixo separa todos os nomes diferentes e conta a incidencia de cada nome diferente. 
// -----------------------------------------------------------------------------------------------	
	for(i=0;i<TAMANHO;i++)
	{
		strcpy(aux, ficha_livros[i].autor);
				
		for(j=0;j<TAMANHO;j++)
		{
			if(strcmp(unicos[j].autor_uni, aux) == 0)
			{
				quebra = 1;
				break;
			}
		}
		
		if(quebra == 0)
		{
			strcpy(unicos[t_aux].autor_uni, aux); 
			t_aux++;
		}	
		quebra = 0;			
	}
	
	for(i=0;i<t_aux;i++)
	{
		conta_obra[i] = 0;
		conta_pag[i] = 0;
		for(j=0;j<TAMANHO;j++)
		{
			if(strcmp(unicos[i].autor_uni, ficha_livros[j].autor) == 0)
			{
				conta_obra[i] = conta_obra[i] + 1;
				conta_pag[i] = conta_pag[i] + ficha_livros[j].num_pag;
			}
		}
	}
	//for(i=0;i<t_aux;i++){printf("%s\n", unicos[i].autor_uni);} //Mostra os nomes unicos
// -----------------------------------------------------------------------------------------------	
		
	for(i=0;i<t_aux;i++)
	{
		printf("  *  %s", unicos[i].autor_uni);
		printf("\t  -  Qt. Livros: %f\n", conta_obra[i]);
		printf("\t  -  M�dia: %.2f P�g./Livro\n\n", conta_pag[i]/conta_obra[i]);
		fflush(stdin);
	}
		
	printf("  ----------------------------------------");
	printf("\nM�dia Total: %.2f P�ginas/Livro.", media/TAMANHO);
		
	getch();
	return 0;
}

