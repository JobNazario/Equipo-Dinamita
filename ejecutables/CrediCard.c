#include "stdio.h"
#include "into.h"

unit8 u8LuhnCheck ( unit8 *pu8Data,unit8 u8Check); 
void main (void) 
{
  int u8Check;
  char *pu8Data; 
  gets(pu8Data);
  printf("Ingresa tu numero de tarjeta > "); //solicitud de credi card
  printf("Codigo ingresado %s\n", pu8Data);
  u8LuhnCheck(pu8Data,u8Check);
} 
/*{ unit8 au8CardNumber[16]={5,3,2,1,6,5,4,2,7,9,4,6,2,4,6,7} ; 
u8Check= u8LuhnCheck(&au8CardNumber[0]); 
} */

unit8 u8LuhnCheck (unit8 *pu8Data,unit8 u8Check)
{ 
  int n = 0; //Algoritmo de Luhn
  //u8Check = 0;
  for(int i = 0; i < 16; i++) //Ciclo para ir sumando los numeros ya sea multiplicados x2 o con su valor original segun 
  {
    if(i%2 == 0)
    {
      n = (pu8Data[i]-'0') * 2;
      if(n >= 10)
        n = (n - 10) + 1;
    } 
    else
    {
      n = pu8Data[i]-'0';
    }
    u8Check = u8Check + n;
  }
  //Si el resultado es multiplo de 10 entonces la sumatoria es correcta
  if(u8Check%10 == 0)
  {
    printf("La tarjeta es valida %d\n", u8Check);
  }//%d la usamos para verificar que sean correctos las sumatorias
  else 
  {
    printf("La tarjeta es invalida %d\n", u8Check);
  }
}