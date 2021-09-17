#include "../HAL/LED.c"
#include "../MCAL/TIMER0/TIMER0.c"

void Blink_LED_Init(void)
{
    TIMER0_Init();
    Led_Init();
}

void Delay_Milli(uint32_t Time_in_Milli_Seconds)
{
    
    uint64_t No_of_Required_Ticks = Time_in_Milli_Seconds / (Tick_Time * 1000);
    
    uint64_t No_of_Required_Overflows = Time_in_Milli_Seconds / (Overflow_Time*1000);
    
    uint32_t Remainder_Timer_Ticks = No_of_Required_Ticks - (No_of_Required_Overflows*256);
    
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
    
    if(Remainder_Timer_Ticks > 0)
    {
        TIMER0_SetTimerValue(256 - Remainder_Timer_Ticks);
        
        while(TIMER0_Check_Overflow());
    }
    
    
}

void Blink_LED(void)
{
    Led_Power(LOW);
    Delay_Milli(300);
    Led_Power(HIGH);
    Delay_Milli(400);
}
