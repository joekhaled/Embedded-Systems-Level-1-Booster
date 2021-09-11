#include "DIO.h"
#include "DIO_Registers.h"
#include "../../LIB/Bit_Math.h"

//Function to Set Port Direction
void DIO_SetPortDirection (DIO_Port_Type Port_Id, DIO_Direction Port_Direction)
{
    /* Check if Port Direction is Output */
    if(DIO_Output == Port_Direction )
    {
        /* Set direction register for selected Port */
        switch(Port_Id)
        {
            /* DDR Register = 0b 1111 1111 --> all pins in port are output */
            case    PORTA: DDRA_Reg = 0xFF; break;
            case    PORTB: DDRB_Reg = 0xFF; break;
            case    PORTC: DDRC_Reg = 0xFF; break;
            case    PORTD: DDRD_Reg = 0xFF; break;
            default: /* Wrong Port selected */ break;
        }
    }
    /* Check if Port Direction is Input */
    else if (DIO_Input == Port_Direction)
    {
        /* Set direction register for selected Port */
        switch(Port_Id)
        {
            /* DDR register = 0b 0000 0000 --> all pins in port are input */
            case PORTA: DDRA_Reg = 0x00;        break;
            case PORTC: DDRC_Reg = 0x00;        break;
            case PORTB: DDRB_Reg = 0x00;        break;
            case PORTD: DDRD_Reg = 0x00;        break;
            default: /* Wrong Port selected */  break;
        }
    }
}

// Function to Set the Value of a Port Pins Directly
void DIO_SetPortValue (DIO_Port_Type Port_Id, uint8_t Port_Value)
{
    switch(Port_Id)
    {
        // PORT Register = Port Value --> Change Value of port pins
        case PORTA: PORTA_Reg = Port_Value; break;
        case PORTB: PORTB_Reg = Port_Value; break;
        case PORTC: PORTC_Reg = Port_Value; break;
        case PORTD: PORTD_Reg = Port_Value; break;
        default: /* Wrong Port selected */  break;
    }
}

// Function to Set Direction of Specific Pin in a Port
void DIO_SetPinDirection (DIO_Port_Type Port_Id, DIO_Pin_Number Pin_Id, DIO_Direction Pin_Direction)
{
    if((Port_Id <= PORTD) && (Port_Id <= Pin7))
    {
        if(DIO_Output == Pin_Direction)
        {
            switch(Port_Id)
            {
                case PORTA: SET_BIT(DDRA_Reg, Pin_Id); break;
                case PORTB: SET_BIT(DDRB_Reg, Pin_Id); break;
                case PORTC: SET_BIT(DDRC_Reg, Pin_Id); break;
                case PORTD: SET_BIT(DDRD_Reg, Pin_Id); break;
            }
        }
        else if (DIO_Input == Pin_Direction)
        {
            switch(Port_Id)
            {
                case PORTA: CLEAR_BIT(DDRA_Reg, Pin_Id); break;
                case PORTB: CLEAR_BIT(DDRB_Reg, Pin_Id); break;
                case PORTC: CLEAR_BIT(DDRC_Reg, Pin_Id); break;
                case PORTD: CLEAR_BIT(DDRD_Reg, Pin_Id); break;
            }
        }
        else
        {
            //Wrong Value
        }
    }
    else
    {
        // Wrong Port or Pin Selection
    }
}

// Function to Set Value of Specific Pin in a Port
void DIO_SetPinValue (DIO_Port_Type Port_Id, DIO_Pin_Number Pin_Id, DIO_State Pin_Value)
{
    if((Port_Id <= PORTD) && (Pin_Id <= Pin7))
    {
        if(HIGH == Pin_Value)
        {
            switch(Port_Id)
            {
                case PORTA: SET_BIT(PORTA_Reg, Pin_Id); break;
                case PORTB: SET_BIT(PORTB_Reg, Pin_Id); break;
                case PORTC: SET_BIT(PORTC_Reg, Pin_Id); break;
                case PORTD: SET_BIT(PORTD_Reg, Pin_Id); break;
            }
        }
        else if (LOW == Pin_Value)
        {
            switch(Port_Id)
            {
                case PORTA: CLEAR_BIT(PORTA_Reg, Pin_Id); break;
                case PORTB: CLEAR_BIT(PORTB_Reg, Pin_Id); break;
                case PORTC: CLEAR_BIT(PORTC_Reg, Pin_Id); break;
                case PORTD: CLEAR_BIT(PORTD_Reg, Pin_Id); break;
            }
        }
        else
        {
            //Wrong Value
        }
    }
    else
    {
        //Wrong Port or Pin Selection
    }
}

// Function to Read Value of Pin in a Port
DIO_State DIO_GetPinValue (DIO_Port_Type Port_Id, DIO_Pin_Number Pin_Id)
{
    uint8_t Pin_Value = 0;
    
    if((Port_Id <= PORTD) && (Pin_Id <= Pin7))
    {
        switch(Port_Id)
        {
            case PORTA: Pin_Value = READ_BIT(PINA_Reg, Pin_Id); break;
            case PORTB: Pin_Value = READ_BIT(PINB_Reg, Pin_Id); break;
            case PORTC: Pin_Value = READ_BIT(PINC_Reg, Pin_Id); break;
            case PORTD: Pin_Value = READ_BIT(PIND_Reg, Pin_Id); break;
        }
    }
    else
    {
        Pin_Value = 0xFF; //Wrong Port or Pin Selection -> Set Value of 1
    }

    return Pin_Value;
}
