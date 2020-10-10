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
	//ocurrence
	uint8 u8ArrayOcurrences = 0;
	uint8 au8NumberArray[5] = {2,5,8,4,8};
	GENFUN_u8GetOccurence (uint8 *pu8Src, uint8 u8Target, uint8 u8SizeOfList); 
	printf("Repeated times of %s;  %i",u8Target,targetRepeat);

	printf("\nGet Ocurrence\n");
	printf("Array:%s\n", au8BufferTest2);
	printf("Ocurrence target: %c\n", ASCII_TARGET_CODE);
	u8ArrayOcurrences = GENFUN_u8GetOccurrence ( &au8BufferTest2[0], ASCII_TARGET_CODE, 12 );
	printf("Ocurrences in array: %i\n", u8ArrayOcurrences);
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
int GENFUN_u8GetOccurence (uint8 *pu8Src, uint8 u8Target, uint8 u8SizeOfList) 
{
	uint8 u8ArrayOcurrences = 0;
	while(u8SizeOfList !=0)
	{
		if(*pu8Src==u8Target)
		{
			u8ArrayOcurrences++;
		}
		else
		{
			/*Nothing to do*/
		}
		pu8Src++;
		u8SizeOfList --;
	}
	return u8ArrayOcurrences;
}

