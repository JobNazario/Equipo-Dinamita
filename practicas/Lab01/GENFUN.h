/*Data Types*/
typedef unsigned char uint8;
typedef unsigned short unit16;
typedef unsigned int unit32;

/*prototypes*/
void GENFUN_vCapsOn (uint8 *pu8Src, uint8 u8SizeOfList) ;
void GENFUN_vCapsOff (uint8 *pu8Src, uint8 u8SizeOfList) ;

/*definitions*/
#define ASCCI_HIGH_THRESHOLD_CAPSON_TO_On	122
#define ASCCI_LOW_THRESHOLD_CAPSON_TO_On	97
#define ASCCI_HIGH_THRESHOLD_CAPSON_TO_OFF	90
#define ASCCI_LOW_THRESHOLD_CAPSON_TO_OFF	65
#define ASCCI_COVERTION_FACTOR				32