/*
	Faça um programa que cria uma estrutura chamada livro, que contém os elementos: 
	título, autor, ano de edição, número de páginas e preço. Crie uma variável desta estrutura que é um vetor de 10 elementos. 
	O programa deve ler os valores para a estrutura e imprimir a média do número de páginas dos livros 
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
	printf("\n\t<<< Catálogo de Livros >>>\n\n");
		
	for(k=0;k<TAMANHO;k++)
	{
		printf("  ----------------------------------------\n");	printf(" - %iº Livro.\n\n", k+1);
		
		printf("\t * Título: "); 
		fgets(ficha_livros[k].titulo,50,stdin);
		
		printf("\t * Autor: ");	
		fgets(ficha_livros[k].autor,50,stdin);		
		
		printf("\t * Ano de Edição: "); 
		scanf("%i", &ficha_livros[k].ano_edicao);
		
		printf("\t * Número de Páginas: "); 
		scanf("%f", &ficha_livros[k].num_pag);
		
		printf("\t * Preço: "); 
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
		printf("\t  -  Qt. Livros: %.0f\n", conta_obra[i]);
		printf("\t  -  Média: %.2f Pág./Livro\n\n", conta_pag[i]/conta_obra[i]);
		fflush(stdin);
	}
		
	printf("  ----------------------------------------");
	printf("\nMédia Total: %.2f Páginas/Livro.", media/TAMANHO);
		
	getch();
	return 0;
}

