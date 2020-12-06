#include <bml.h>
#include <stdio.h>
#include <windows.h> // SLEEP()
#include <Types.h >

void bml(void)
{
		while (1)
	{
		SM_Bomba_De_Infusion();
		delay (3000);
	}
	void delay(int number_of_seconds)
	{
		 clock_t start_time = clock(); 
	}

	void delay(int quantity_of_mililiters)
	{
    int milli_liters = 1000 * number_of_liters; 
 
    clock_t start_quantity_of_mililiters = clock(); 
   
    while (clock() < start_time + milli_liters) 
	}
}