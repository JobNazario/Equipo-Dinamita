#include "stdio.h"
#include "funciones.h"

void main() 
{
  uint32 estacionamiento[X][Y];
  uint32 opc;

  uint32 tipoVehiculo; // 1 = Coche  // 2 = Moto  // 3 = Camión
  uint32 minutosEstancia; // Minutos totales de estacionamiento en parking
  uint32 minutosDiferencia; // Minutos en los que se aplicará la tarifa reducida
  uint64 Precio = 0; // Precio definitivo que pagará el cliente

   do {
        menu();
        scanf("%d",&opc);
	switch (opc) 
	{
	   case 1:
		iniciar(estacionamiento);
		break;
	   case 2:
		imprimir(estacionamiento);
		break;
	   case 3:
		ocupar(estacionamiento);
		break;
	   case 4:
		cancelar(estacionamiento);
		break;
	   case 0: break;
	   default:
		printf("\nNo ha introducido una opcion valida..\n");
	}
   } while (opc != 0);
   
    printf("Si usas un sedan pulse 1:\nSi usas moto pulse 2:\nSi usas una SUV pulsa 3:\n"); // Pide al usuario que indique el tipo de vehículo a estacionar
    scanf("%i",&tipoVehiculo); // Asigna el número introducido a la variable

    if (tipoVehiculo != 1 && tipoVehiculo != 2 && tipoVehiculo != 3) 
    {
        printf("\nNo a introducido un numero apto\n");
    } // Si la variable no vale 1 o 2 o 3 muestra en pantalla en pantalla el texto
    else 
    { // En caso de que el valor de la variable sí sea 1 o 2 o 3 pregunta cuantos minutos ha estado estacionado su vehículo
        printf("\nCuantos minutos a estado su vehiculo en el parking?\n");
        scanf("%i",&minutosEstancia);
    } // Asigna los minutos dados por el usuario a la variable
 
    minutosDiferencia = minutosEstancia - minutosCambio;// Asigna un valor a la variable
     
     if (tipoVehiculo == 1) // Si es un coche...
     {
         if (minutosEstancia <= minutosCambio) // Y ha estado aparcado durante 1 hora o menos...
         {
            Precio = minutosEstancia * tarifaNormalCoche + precioEntrada; //Precio = Minutos por precio minuto, más tarifa por entrar
            printf("El precio es de:%f pesos",Precio);
         } // Y muestra en pantalla el importe a pagar
         else 
         {
            Precio = precioTarifaBaseCoche + minutosDiferencia * tarifaReducidaCoche; // Si en cambio ha estado aparcado más tiempo, calcula el precio a partir de la primera hora y se lo suma al precio de la primera hora
            printf("El precio es de:%f pesos",Precio);
         } // Y muestra en pantalla el importe a pagar
     }
     if (tipoVehiculo == 2) // Si es una moto...
     {
         if (minutosEstancia <= minutosCambio) // Ídem coche
         {
            Precio = minutosEstancia * tarifaNormalMoto + precioEntrada;
            printf("El precio es de:%f pesos",Precio);
         }
         else 
         {
            Precio = precioTarifaBaseMoto + minutosDiferencia * tarifaReducidaMoto;
            printf("El precio es de:%f pesos",Precio);
         }
     }
     if (tipoVehiculo == 3)
     {
         if (minutosEstancia <= minutosCambio) // Ídem coche
         {
            Precio = minutosEstancia * tarifaNormalCamion + precioEntrada;
            printf("El precio es de:%f pesos",Precio);
         }
         else 
         {
            Precio = precioTarifaBaseCamion + minutosDiferencia * tarifaReducidaCamion;
            printf("El precio es de:%f pesos",Precio);
         }
     }
}

void menu()
{
   printf("\nPulse en la opcion deseada o 0 para salir...\n");
   printf("1. Iniciar programa del estacionamiento\n");
   printf("2. Imprimir mapa del estacionamiento\n");
   printf("3. Ocupar lugar\n");
   printf("4. Salir del cajon\n");
   printf("0. Salir del programa, para iniciar cobro\n");
   printf("Elije una opcion: ");
}

void iniciar(uint32 s[X][Y]) 
{
   uint32 i, j;

   for(i=0;i<X;i++) 
   {
	for(j=0;j<Y;j++) 
	{
	   s[i][j] = 0;
	}
   }
}

void imprimir(uint32 s[X][Y]) 
{
   uint32 i, j;
   uint32 libres=0, ocupada=0, libretotal=0, ocupadatotal=0;
   
   printf("\nCajon\t1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25");
   for(i=0;i<X;i++) 
   {
	printf("\nFila %d\t", i+1);
    for(j=0;j<Y;j++) 
    {
       if (s[i][j] == 1) 
       {
		if (j > 9)
		   printf(" X ");
		else
		   printf("X ");
		ocupada++;
		ocupadatotal++;
	   } else{
		if (j > 9)
	 	   printf(" . ");
		else
		   printf(". ");
		libres++;
		libretotal++;
	   }
    }
	printf (" -> Libres %d / Ocupados %d", libres, ocupada);
	libres=0;
	ocupada=0;
   }
   printf("\nTotal de cajones ocupados: %d \t Total de cajones libres: %d\n", ocupadatotal, libretotal);
} 

void ocupar(uint32 s[X][Y]) 
{
   uint32 i, j;
   uint32 reserva[X][Y];
   iniciar(reserva);
   imprimir(s);

   printf("\nElija la fila y cajón que quiera ocupar, para parar de reservar introduzca un 0 en la fila...\n");
   
do {
   	printf("Fila: ");
   	scanf("%d",&i);
	if (i != 0)
	{
   	   fflush(stdin);
   	   printf("Cajon: ");
   	   scanf("%d", &j);
   	   fflush(stdin);
	   if (reserva[i-1][j-1] == 0 && s[i-1][j-1] == 0)
		reserva[i-1][j-1] = 1;
	   else
		printf("\nEl cajon %d de la fila %d esta ocupado, reserve otro lugar...\n", j, i);
	}
   } while(i != 0);   

   for (i=0;i<X;i++) 
   {
	for(j=0;j<Y;j++) 
	{
	   if (reserva[i][j] == 1) 
	   {
		s[i][j] = 1;
	   }		
	}
   }
   printf("\nYa ha reservado su lugar, gracias.\n");
}

void cancelar(uint32 s[X][Y]) 
{
   uint32 i, j;
   uint32 reserva[X][Y];

   iniciar(reserva);
   imprimir(s);

   printf("\nElija la fila y cajon del quiera salir, para parar de salir introduzca un 0 en la fila...\n");

   do {
        printf("Fila: ");
        scanf("%d",&i);
        if (i != 0) 
        {
           fflush(stdin);
           printf("Butaca: ");
           scanf("%d", &j);
           fflush(stdin);
           if (s[i-1][j-1] == 1)
		s[i-1][j-1] = 0;
        else
            printf("\nEl cajon %d de la fila %d ya no esta ocupado, cancele otro lugar...\n", j, i);
        }
   } while(i != 0);


   printf("\nYa ha cancelado su espacio, gracias.\n");
}