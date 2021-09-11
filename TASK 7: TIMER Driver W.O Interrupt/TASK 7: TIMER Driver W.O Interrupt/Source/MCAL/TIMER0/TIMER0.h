#ifndef TIMER0_h
#define TIMER0_h

void TIMER0_Init(void);

void TIMER0_Set_Compare_Value(uint8_t);

void TIMER0_SetTimerValue(uint8_t);

uint32_t TIMER0_Check_Overflow(void);

void Reset_TIMER0(void);

#endif
