#include "stdio.h" 

int main() 
{
	long BitsVar,BitSel;
	char OpToDo,VarRes;

	printf("De cuantos Bits es tu variable?:\n");
	scanf("%ld",&BitsVar);
	if(BitsVar == 8 || BitsVar==16 || BitsVar==32)
	{
		do{
			printf("1-operacion AND\n 2-operacion OR\n 3-operacion XOR\n Selecione la opcion desada.");
			scanf("%d",&OpToDo);
			printf("Corrimiento para la operacion:\n");
			scanf("%ld",BitSel);
			if (OpToDo <=3 && OpToDo>0)
			{
				if (OpToDo==1)
				{
					VarRes&=~(1<<BitSel);
					printf(" Valor de variable = %ld\n",VarRes);
				}
				else if (OpToDo==2)
				{
					VarRes|=(1<<BitSel);
					printf(" Valor de variable = %ld\n",VarRes);
				}
				else 
				{
					VarRes^=(1<<BitSel);
					printf(" Valor de variable = %ld\n",VarRes);
					
				}
			}
			else 
			{
				printf("Error: operacion no disponible intente de nuevo\n");
			}
		}while(OpToDo <=3 && OpToDo>0);
	}
	else 
	{
		printf("Error!!!, El tamanio de la variable debe de ser 8,16 o 32\n");
	}
return 0;
}