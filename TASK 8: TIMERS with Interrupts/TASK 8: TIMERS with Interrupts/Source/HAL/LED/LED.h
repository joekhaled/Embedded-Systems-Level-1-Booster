#ifndef LED_h
#define LED_h

#include "../../LIB/Types.h"
#include "../../MCAL/DIO/DIO.c"

void Led_Init(void);

void Led_Power(DIO_State);

#endif
