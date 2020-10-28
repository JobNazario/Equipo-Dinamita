
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

typedef struct
{
	uint8 u8MaxSlots;
	uint8 u8AvailableSlots;
	uint8 u8NotAvailableSlots;
	uint32 u32MoneyEarn;
}tstParkingInfo;

typedef enum
{
	enSector0 = 0,
	enSector1 = 1,
	enSector2 = 2,
	enSector3 = 3,
	enSector4 = 4,
	enMaxSectors= 5
}tenParkingSectors;

#define SECTOR0_SLOTS		5
#define SECTOR1_SLOTS		10
#define SECTOR2_SLOTS		25
#define SECTOR3_SLOTS		7
#define SECTOR4_SLOTS		12

#define INIT_PARKING_SLOTS		\
{								\
	{SECTOR0_SLOTS,SECTOR0_SLOTS,0,0},					\
	{SECTOR1_SLOTS,SECTOR1_SLOTS,0,0},					\
	{SECTOR2_SLOTS,SECTOR2_SLOTS,0,0},					\
	{SECTOR3_SLOTS,SECTOR3_SLOTS,0,0},					\
	{SECTOR4_SLOTS,SECTOR4_SLOTS,0,0},					\
}


void ShowAvailableSlots ( tstParkingInfo enCurrentSector );
void ShowNotAvailableSlots ( tstParkingInfo enCurrentSector );
void ShowEarnedMoney ( tstParkingInfo enCurrentSector );
uint8 u8AddCarToSector( tstParkingInfo enCurrentSector );
uint8 u8RemoveCarFromSector( tstParkingInfo enCurrentSector );
void u8ImportPaymentOfSlot( tstParkingInfo enCurrentSector );
