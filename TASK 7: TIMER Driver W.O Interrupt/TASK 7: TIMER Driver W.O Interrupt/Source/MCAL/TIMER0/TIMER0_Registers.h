#ifndef TIMER0_Registers_h
#define TIMER0_Registers_h

#include "../../LIB/Types.h"

//Timer0 Registers
#define TCNT0_Reg      (*( (volatile uint8_t*) 0x52) ) //Timer0 Register
#define TCCR0_Reg      (*( (volatile uint8_t*) 0x53) ) //Timer0 Control Register
#define OCR0_Reg       (*( (volatile uint8_t*) 0x5C) ) //Timer0 Output Compare Register
#define TIFR_Reg       (*( (volatile uint8_t*) 0x58) ) //Timer0 Interrupt Flag Register
#define TIMSK_Reg      (*( (volatile uint8_t*) 0x59) ) //Timer0 Interrupt Mask Register


#endif
