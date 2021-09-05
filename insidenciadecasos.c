#include<stdio.h>

int main(){
	
	/*
		Algoritmo para contar insidencias de casos.
		Em outras palavras, 
		esse algoritmo gera ao final um vetor "unicos[12]" apenas com letras não repetidas que estão em "vetor[12]".
	*/
		
	int i, j, t_aux, quebra;
	char vetor[12] = {'A','A','B','C','D','D','E','H','A','W','J','E'};
	char aux, unicos[12];
	
	t_aux = quebra = 0; 
	
	for(i=0;i<12;i++)
	{
		aux = vetor[i];
		
		for(j=0;j<12;j++)
		{
			if(aux == unicos[j])
			{
				quebra = 1;
				break;
			}
		}
	
		if(quebra == 0)
		{
			unicos[t_aux] = aux;
			t_aux++;
		}
		quebra = 0;			
	}
	
	for(i=0;i<t_aux;i++)
	{
		printf("%c ", unicos[i]);
	}
				
	return 0;
}
