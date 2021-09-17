#ifndef TIMER0_Config_h
#define TIMER0_Config_h

#define System_Freq                    16000000
#define Timer_Resolution               8
#define Clk_Prescaler                  256

#define Tick_Time 0.000016 // 1/System_Freq
#define Overflow_Time 0.004096 //(2^Timer_Resolution)*(Clk_Prescaler/System_Freq)


#define SIGNAL_MODE                    Normal_Mode
#define COMPARE_OUTPUT_MODE            OC0_DISCONNECTED
#define CLOCK_Prescaler                Clk_256

/*
 
 SIGNAL_MODE CHOICES:-
 -----------------------
 Normal_Mode
 PWM_PhaseCorrect
 CTC
 Fast_PWM
 
 COMPARE_OUTPUT_MODE CHOICES:-
 ------------------------------
 
 OC0_DISCONNECTED
 OC0_TOGGLE_ON_COMPARE_MATCH
 OC0_CLEAR_ON_COMPARE_MATCH
 OC0_SET_ON_COMPARE_MATCH
 
 CLOCK_TYPES_Prescalers CHOICES :-
 ----------------------------------
 No_Clock_Stop
 ClkIo
 Clk_8
 Clk_64
 Clk_256
 Clk_1024
 Ext_clk_FallingEdge
 Ext_clk_RisingEdge
 
 */



#endif
