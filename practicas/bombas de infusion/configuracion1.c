/*ESTE .C SE ENCARGA DE AQUELLAS ACCIONES QUE SON DISTINTAS
 A LOS TIMERS, ES DECIR EL ON/OFF Y SUMINISTRO DEL MEDICAMENTO*/

#include <configuracion.h>
#include <Types.h >

static void InfusionPumpSupply ( void )
{
	uint32 u32ResetInstrument = 0;
	static SupplyControl enInfuserOff = enOff;
	static PresentStates enActualState = enInterface;
	
	switch (enActualState)
	{
		case enInfuserOn  //ACTIVACION DE LA BOMBA PARA SUMINISTRAR
		{
			printf("Suministrando medicamento\n "); 
			enActualState = enDelay;
			break;

		}
		case enDelay:  //SUMINISTRA EL MEDICAMENTO SECUNDARIO
		{
			if(u8regime ! = 0)
			{
				printf("Incorporando medicamento secundario: %d \n", u8regime); 
				u8regime--;
			}
			else
			{
				enActualState = enInfuserOff;
			}
		}
		case enInfuserOff:  //DETIENE LA BOMBA
		{
			printf("Frenando el proceso \n"); 
			enActualState = enInterface;
			break;
		}

		case enInterface: //ENCIENDE O APAGA LA BOMBA
		{
			if ( enState == enInfuserOff;
			{
				printf("selccione la opcion deseada\n 1. apagar \n 0.encender\n "); 
				sacanf("%d", &u32ResetInstrument);
				if( u32ResetInstrument == 0 )
				{
					enState = enOn
				}
				else
				{
					printf("Encienda el suministro \n")
					sacanf("%d", &u8regime);
					u8regime = u8regime:
					enActualState = enInfuserOn
				}

			}