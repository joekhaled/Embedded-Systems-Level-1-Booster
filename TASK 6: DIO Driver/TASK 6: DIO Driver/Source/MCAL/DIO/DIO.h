#ifndef DIO_h
#define DIO_h

#include "../../LIB/Types.h"

//Function to Set Port Direction
void DIO_SetPortDirection (DIO_Port_Type Port_Id, DIO_Direction Port_Direction);

//Function to Set Port Value
void DIO_SetPortValue (DIO_Port_Type Port_Id, uint8_t Port_Value);


//Function to Set Pin Direction
void DIO_SetPinDirection (DIO_Port_Type Port_Id, DIO_Pin_Number PinId, DIO_Direction Pin_Direction);

//Function to Set Pin Value
void DIO_SetPinValue (DIO_Port_Type Port_Id, DIO_Pin_Number PinId, DIO_State Pin_Value);

//Function to Read Pin Value
DIO_State DIO_GetPinValue (DIO_Port_Type Port_Id, DIO_Pin_Number Pin_ID);

#endif
