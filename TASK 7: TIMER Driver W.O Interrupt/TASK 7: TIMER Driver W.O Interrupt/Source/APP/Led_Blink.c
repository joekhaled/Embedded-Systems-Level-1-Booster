#include "../HAL/LED.c"
#include "../MCAL/TIMER0/TIMER0.c"

void Blink_LED_Init(void)
{
    TIMER0_Init();
    Led_Init();
}

void Delay(uint32_t Time_in_Seconds)
{
    
    uint32_t No_of_Required_Overflows = Time_in_Seconds/Overflow_Time;
    uint32_t No_of_Current_Overflows = 0;
    
    Reset_TIMER0();
    
    while(No_of_Current_Overflows < No_of_Required_Overflows)
    {
        if(TIMER0_Check_Overflow())
        {
            No_of_Current_Overflows++;
            Reset_TIMER0();
        }
    }
}

void Blink_LED(void)
{
    Led_Power(LOW);
    Delay(5);
    Led_Power(HIGH);
    Delay(5);
}
