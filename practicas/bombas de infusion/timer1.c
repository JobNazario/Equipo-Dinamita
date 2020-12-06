#include <timer.h>
#include <stdio.h>
#include <windows.h> // SLEEP()

int AdjustableTime()
{
    // EL USUARIO DIGITARA EN QUE HORA,MINUTO,SEGUNDO
    int tipo;

    printf("1. Horas");
    printf("\n2. Minutos");
    printf("\n3. Segundos");
    printf("\nEscriba el tiempo de funcionamiento de la bomba: ");
    scanf("%i", &tipo);
 
    // EL USUARIO DIGITARA LA CANTIDAD DE HORAS MINUTOS O SEGUNDOS
    int cantidad;
    printf("\nInserte la cantidad de tiempo deseada ( Un maximo de 25 min.): ");
    scanf("%i" , &cantidad);
 
    // CREAMOS LAS VARIABLES PARA LAS HORAS , MINUTOS , SEGUNDOS
    int hora,minuto,segundo;
 
 
    // 3 BUCLES ANIDADOS DE TIPO FOR , 3 = HORAS ,MINUTOS,SEGUNDOS
    for (hora=0; hora<=24; hora++ )
    {
        for (minuto=0; minuto<60; minuto++ )
 
    {
        for (segundo=0; segundo<60; segundo++ )
        {
            // AGREGAMOS UN INTERVALO DE 1000 MS = 1 SEGUNDO
            Sleep(1000);
 
 
            // IMPRIME EL CRONOMETRO
            printf("\r %.2i : %.2i : %i " , hora , minuto , segundo );
 
            // CONDICIONAL PARA LAS HORAS
            if (tipo == 1 && cantidad <= hora)
            {
                printf("\nBomba detenida");
                return 0;
            }
 
            // CONDICIONAL PARA LOS MINUTOS
            else if (tipo == 2 && cantidad <= minuto)
            {
                printf("\nBomba detenida");
                return 0;
            }
            // CONDICIONAL PARA LOS SEGUNDOS
            else if (tipo == 3 && cantidad <= segundo)
            {
                printf("\nBomba detenida");
                return 0;
            }
 
        }
    }
    }

    return 0;
}