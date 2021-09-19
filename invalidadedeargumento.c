#include<stdio.h>

int main(){
	
	/*
		Prova de Invalidade do argumento abaixo.
				
		1. s->(t->u)
		2. p->(w->x)
		3. t->(p^w)
		4. ~(t^x)
		----------------------
		5. s <-> u
	*/
	
	int s,t,u,p,w,x,p_1,p_2,p_3,p_4,arg, contador;
	contador = 0;
	
	printf("|s|t|u|p|w|x| s->(t->u) | p->(w->x) |  t->(p^w) |  ~(t^x)   |  s <-> u  |");
	printf("\n\n");
	
	for(s=0;s<2;s++)
	{
		for(t=0;t<2;t++)
		{
			for(u=0;u<2;u++)
			{
				for(p=0;p<2;p++)
				{
					for(w=0;w<2;w++)
					{
						for(x=0;x<2;x++)
						{
							p_1 = (!s||(!t||u)); p_2 = (!p||(!w||x)); 
							p_3 = (!t||(p&&w)); p_4 = !(t&&x); 
							arg = (!s||u)&&(!u||s);
							
							printf("|%i|%i|%i|%i|%i|%i|",s,t,u,p,w,x);
							printf("     %i     |", p_1);
							printf("     %i     |", p_2);
							printf("     %i     |", p_3);
							printf("     %i     |", p_4);
							printf("     %i     |", arg);
							if(((p_1&&p_2&&p_3&&p_4)==1)&&(arg==0)){printf(" Contra-exemplo ");contador++;} 
							printf("\n");
							
							
							
						}
					}
				}
			}
		}
	}
	
	printf("\nTotal de Contra-exemplo:%i", contador);
	
	return 0;
}
