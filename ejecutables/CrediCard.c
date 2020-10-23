#include "stdio.h"
#include "into.h"

unit8 un8LuhnChech ( unit8 *pu8Data); 
void main (void) 
 
{ unit8 au8CardNumber[16]={5,3,2,1,6,5,4,2,7,9,4,6,2,4,6,7} ; 
unit8 u8Check=0; 
u8Check= u8LuhnCheck(&au8CardNumber[0]); 
	if(u8Check==0) 
	{ 
		 
	} 
	else 
	{ 
		 
	} 
} 
unit8 u8LuhnCheck (unit8 *pu8Data) 
{ 
	 
}