#include "LED.h"

#define LED_Port PORTC
#define LED_Pin Pin7

void Led_Init(void)
{
    DIO_SetPinDirection(LED_Port , LED_Pin , DIO_Output);
}

void Led_Power(DIO_State State)
{
    if(State == 1)
    {
        DIO_SetPinValue(LED_Port , LED_Pin , HIGH);
    }
    else
    {
        DIO_SetPinValue(LED_Port , LED_Pin , LOW);
    }
}
