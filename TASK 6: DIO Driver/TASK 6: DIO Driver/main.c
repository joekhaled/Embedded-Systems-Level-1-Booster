#include "Source/MCAL/DIO/DIO.c"

#define Button_Port PORTB
#define Button_Pin Pin4

#define LED_Port PORTC
#define LED_Pin Pin7

int main(void)
{
    //Set Pins Directions
    DIO_SetPinDirection(Button_Port , Button_Pin , DIO_Input);
    DIO_SetPinDirection(LED_Port , LED_Pin , DIO_Output);
    
    uint32_t Flag = 0;
    
	while (1)
    {
        
        if(DIO_GetPinValue (Button_Port , Button_Pin)) //Check If Button Pressed
        {
            Flag = !Flag;
        }
        
        if(Flag == 1)
        {
            DIO_SetPinValue(LED_Port , LED_Pin , HIGH);
        }
        else
        {
            DIO_SetPinValue(LED_Port , LED_Pin , LOW);
        }
	}
}
