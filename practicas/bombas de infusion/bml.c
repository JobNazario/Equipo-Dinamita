#include "bml.h"
#include "stdio.h"
#include "stdlib.h"

void bml (void)
{
int opcion;  
do  
{
  system("cls");   
  printf("\t1) programar bomba 1\n");
  printf("\t2) programar bomba 2\n"); 
  printf("\t3) programar bomba 3\n");
  printf("\t4) Salir\n\n");
  printf("     Seleccione una opcion: ");
  scanf("%i",&opcion);				// Capturo opcion del Menu

  switch (opcion)
  {
   case 1: AdjustableTime();           
           break;
   case 2: AdjustableTime1();                     
           break;
   case 3: AdjustableTime2();                        
           break;
   case 4: break;                  	// Fin del Programa
   default: printf("\nError, Ingrese una de las siete opciones\n\n");
            system("pause");
            break;     
  }
}while(opcion!=7);
//return 0;  
}