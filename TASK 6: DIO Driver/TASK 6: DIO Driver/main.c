#include "Source/APP/Toggle_LED.c"

int main(void)
{
    Toggle_LED_Init();
        
	while (1)
    {
        Toggle_LED_Update();
	}
}
