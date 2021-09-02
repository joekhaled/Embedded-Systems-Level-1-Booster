#ifndef Types_h
#define Types_h

typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed short int16_t;
typedef unsigned short uint16_t;
typedef signed int int32_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;
typedef signed long long int64_t;
typedef uint8_t* ptochar_t;
typedef uint16_t* ptoshort_t;

typedef enum
{
    DIO_Input, /* 0 */
    DIO_Output /* 1 */
} DIO_Direction;


typedef enum
{
    PORTA,
    PORTB,
    PORTC,
    PORTD
} DIO_Port_Type;

typedef enum
{
    Pin0,
    Pin1,
    Pin2,
    Pin3,
    Pin4,
    Pin5,
    Pin6,
    Pin7
} DIO_Pin_Number;

typedef enum
{
    LOW, /* 0 */
    HIGH /* 1 */
} DIO_State;

#endif
