typedef unsigned char uint8;
typedef unsigned short unit16;
typedef unsigned int unit32;

typedef enum 
{
	enOn = 0,
	enOff,	
}SupplyControl;

typedef enum
{
	enDelay,
	enStates,
	enInfuserOn,
	enInfuserOff,
	enInterface = 0
}PresentStates;

void InfusionPumpSupply (void);