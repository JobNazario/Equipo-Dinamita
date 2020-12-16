#include "BML.h"

void delay(int number_of_seconds);

void BML ( void )
{
	static uint8 u8FlagApp1 = TIME_TARGET_FOR_APP1;
	static uint8 u8FlagApp2 = TIME_TARGET_FOR_APP2;
	static uint8 u8FlagApp3 = TIME_TARGET_FOR_APP3;

	if( u8FlagApp1 == 0 )
	{
		u8FlagApp1 = TIME_TARGET_FOR_APP1;
		MonitorApp1();	
	}
	else
	{
		u8FlagApp1--;
	}

	if( u8FlagApp2 == 0 )
	{
		u8FlagApp2 = TIME_TARGET_FOR_APP2;
		MonitorApp2();		
	}
	else
	{
		u8FlagApp2--;
	}

	if( u8FlagApp3 == 0 )
	{
		u8FlagApp3 = TIME_TARGET_FOR_APP3;
		MonitorApp3();		
	}
	else
	{
		u8FlagApp3--;
	}

	delay(1000);		/* 1 seg  */
}

void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Storing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not achieved 
    while (clock() < start_time + milli_seconds) 
        ; 
} 