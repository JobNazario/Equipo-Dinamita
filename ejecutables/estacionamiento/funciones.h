typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long long uint64;

// Se define en estas variables las filas y cajones que tenemos en el estacionamiento
// Para un ejemplo de 5 filas y 25 cajones definimos X a 5 y Y a 25
#define X 5
#define Y 25

//Delaración globales
#define precioTarifaBaseCoche 3.75 // Cantidad a abonar por 1 hora + entrada
#define precioTarifaBaseMoto 1.95 // Cantidad a abonar por 1 hora + entrada
#define precioTarifaBaseCamion 6.75 // Cantidad a abonar por 1 hora + entrada
#define precioEntrada 0.75 // Precio entrada
#define minutosCambio 60 // Minutos en los que se aplica la tarifa normal
#define tarifaNormalCoche 0.5 // Precio por minuto
#define tarifaReducidaCoche 0.3 // Precio por minuto al pasar 1 hora
#define tarifaNormalMoto 0.2 // Precio por minuto
#define tarifaReducidaMoto 0.1 // Precio por minuto al pasar 1 hora
#define tarifaNormalCamion 0.1 // Precio por minuto
#define tarifaReducidaCamion 0.5 // Precio por minuto al pasar 1 hora

void iniciar(uint32 s[X][Y]);
void imprimir(uint32 s[X][Y]);
void ocupar(uint32 s[X][Y]);
void cancelar(uint32 s[X][Y]);
void menu();