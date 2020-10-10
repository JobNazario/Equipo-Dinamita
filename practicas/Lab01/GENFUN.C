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

