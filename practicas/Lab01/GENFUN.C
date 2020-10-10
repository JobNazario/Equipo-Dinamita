#include "stdio.h"
#include "GENFUN.h"

int main(void)
{
	
	uint8 au8BuferTest[12] = "HELLo WORLD";
	printf("Buffer befor funtion %s\n", au8BuferTest);
	GENFUN_vCapsOff(&au8BuferTest[0],12);
	printf("Buffer afther funtion %s\n", au8BuferTest);
	GENFUN_vCapsOn(&au8BuferTest[0],12);
	printf("Buffer befor funtion %s\n", au8BuferTest);

	uint8 au8BuferAverage[12] = [5,6,1,4,3,1,5,9,4,9.8];
	printf("The average is%s\n", );
	for (int i = 0; i < 12; ++i)
	{
		printf("%c\n", au8BuferAverage);
	}
}

void GENFUN_vCapsOff (uint8 *pu8Src, uint8 u8SizeOfList) 
{
	while(u8SizeOfList !=0)
	{
		if(	*pu8Src >= ASCCI_LOW_THRESHOLD_CAPSON_TO_OFF &&
			*pu8Src <= ASCCI_HIGH_THRESHOLD_CAPSON_TO_OFF )
		{
			*pu8Src += ASCCI_COVERTION_FACTOR;
		}
		else
		{
			/*Nothing to do*/
		}
		pu8Src ++;
		u8SizeOfList --;
	}
}

void GENFUN_vCapsOn (uint8 *pu8Src, uint8 u8SizeOfList) 
{
	while(u8SizeOfList !=0)
	{
		if(	*pu8Src >= ASCCI_LOW_THRESHOLD_CAPSON_TO_On &&
			*pu8Src <= ASCCI_HIGH_THRESHOLD_CAPSON_TO_On )
		{
			*pu8Src -= ASCCI_COVERTION_FACTOR;
		}
		else
		{
			/*Nothing to do*/
		}
		pu8Src++;
		u8SizeOfList --;
	}
}



char GENFUN_u8GetAverage (uint8 *pu8Src, uint8 u8SizeOfList)
{
	uint8 Avarege = 0;
	while(u8SizeOfList !=0)
	{
		Avarege += *pu8Src;
		pu8Src ++;
		u8SizeOfList--;
	}
	Avarege= Avarege/u8SizeOfList;
} 