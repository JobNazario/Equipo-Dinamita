#include "bml.h"

void bml (void)
{
	static uint8 u8Flag1 = TIME_TARGET_FOR_1;
	static uint8 u8Flag2 = TIME_TARGET_FOR_2;
	static uint8 u8Flag3 = TIME_TARGET_FOR_3;

	if(u8Flag1 == 0)
	{
		u8Flag1 = TIME_TARGET_FOR_1;
		PrintApp1();
	}
	else
	{
		u8Flag1--;
	}

	if(u8Flag2 == 0)
	{
		u8Flag2 = TIME_TARGET_FOR_2;
		PrintApp2();
	}
	else
	{
		u8Flag2--;
	}

	if(u8Flag3 == 0)
	{
		u8Flag3 = TIME_TARGET_FOR_3;
		PrintApp3();
	}
	else
	{
		u8Flag3--;
	}
	delay(1000);
}

void delay (int number_of_seconds)
{
	int milli_seconds = 1000 * number_of_seconds;
	clock_t start_time = clock();
	while(clock()< start_time + milli_seconds);
}

int clock1 (void)
{
    int milisegundos, segundos, minutos, horas;
    milisegundos=segundos=minutos=horas=0;
    while (minutos < 2)
    {
          if (milisegundos == 60) 
          {
                       
                       segundos++;
                       milisegundos = 0;
                       }
          if (segundos == 60) 
          {
                       
                       minutos++;
                       segundos = 0;
                       }
                       
                       if (minutos ==60)
                       
                       {
                                   horas++;
                                   minutos = 0;
                                   }
          printf("%02d:%02d:%02d:%02d\n",horas, minutos, segundos, milisegundos);
                       sleep(1);
                       milisegundos++;
                       }
                       return 0;
                       }