#include "stdio.h"
#include "into.h"

unit8 u8LuhnCheck ( unit8 *pu8Data); 
void main (void) 
{
  int u8Check;
  char *pu8Data; 
  
  //printf("Ingresa tu numero de tarjeta > "); //solicitud de credi card
  
  //gets(pu8Data);
  //printf("Codigo ingresado %s\n", pu8Data);
  //u8LuhnCheck(pu8Data,u8Check);
unit8 u8CardNumber[16]={5,9,1,3,1,6,6,1,1,2,1,7,7,8,8,0} ; 
u8Check= u8LuhnCheck(&u8CardNumber[0]); 
//confirmar con el regreso

if(u8Check == 1)
  {
    printf("La tarjeta es valida ");
  }
  else 
  {
    printf("La tarjeta es invalida ");
  }

} 


unit8 u8LuhnCheck (unit8 *pu8Data)
{ 
	//L-NOTA: validar : primero operasion → condisionar el resultado →mode vinario y retornar
  int n = 0; //Algoritmo de Luhn
  unit8 u8Check = 0;
  unit8 mode=0;
  for(int i = 0; i < 16; i++) //Ciclo para ir sumando los numeros ya sea multiplicados x2 o con su valor original segun 
  {
    if(i%2 == 0)
    {
      n = (pu8Data[i]) * 2;
      if(n >= 10)
        n = (n - 10) + 1;
    } 
    else
    {
      n = pu8Data[i];
    }
    u8Check = u8Check + n;
  }
  //Si el resultado es multiplo de 10 entonces la sumatoria es correcta
  if(u8Check%10 == 0)
  {
     mode=1;
     
  }//%d la usamos para verificar que sean correctos las sumatorias
  else 
  {
    mode=0;
    
  }
 
  return mode;
}