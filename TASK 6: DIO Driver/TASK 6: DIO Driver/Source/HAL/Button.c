#include "Button.h"

#define Button_Port PORTB
#define Button_Pin Pin4

void Button_Init(void)
{
    DIO_SetPinDirection(Button_Port , Button_Pin , DIO_Input);
}

DIO_State Button_State(void)
{
    if(DIO_GetPinValue (Button_Port , Button_Pin)) //Check If Button Pressed
    {
        return HIGH;
    }
    else
    {
        return LOW;
    }
}
