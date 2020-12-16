#include "BML.h"

void delay(int number_of_seconds);
void BML (void)
{
	static init8 u8FlagApp1 = TIME_TERGET_FOR_APP1;
	static init8 u8FlagApp2 = TIME_TERGET_FOR_APP2;
	static init8 u8FlagApp3 = TIME_TERGET_FOR_APP3;

	if (u8FlagApp1 == 0)
	{
	 	u8FLagApp1 = TIME_TERGET_FOR_APP1;
	 	MonitorApp1;
	}
	else
	{
		u8FlagApp1--;
	}
	//
	if (u8FlagApp2 == 0)
	{
	 	u8FLagApp2 = TIME_TERGET_FOR_APP2;
	 	MonitorApp2;
	}
	else
	{
		u8FlagApp2--;
	}
	//
	if (u8FlagApp3 == 0)
	{
	 	u8FLagApp3 = TIME_TERGET_FOR_APP3;
	 	MonitorApp3;
	}
	else
	{
		u8FlagApp3--;
	}
	delay(200);
}
void delay(int number_of_seconds)
{
	int milli_seconds = 1000 * number_of_seconds;
	clock_t start_time = clock();
	while(clock() < start_time + milli_seconds)
		;
}