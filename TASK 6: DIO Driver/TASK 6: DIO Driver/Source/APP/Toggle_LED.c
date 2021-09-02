#include "../MCAL/DIO/DIO.c"
#include "../HAL/Button.c"
#include "../HAL/LED.c"

void Toggle_LED_Init(void)
{
    Led_Init();
    Button_Init();
}

uint8_t State = 0;

void Toggle_LED_Update(void)
{
    if(Button_State() == HIGH)
    {
        State = !State;
    }
    
    if(State == 1)
    {
        Led_Power(HIGH);
    }
    else
    {
        Led_Power(LOW);
    }
}
