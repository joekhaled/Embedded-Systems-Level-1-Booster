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

typedef struct ST_AccountBalance_t
{
    uint8_t PAN[20];
    float Balance;
}ST_AccountBalance_t;

typedef struct ST_CardData_t
{
    uint8_t Holder_Name[25];
    uint8_t PAN[20];
    uint8_t Expiration_Date[5];
}ST_CardData_t;

typedef struct ST_TerminalData_t
{
    float Transaction_Amount;
    uint8_t Transaction_Date[11];
    float Max_Transaction_Amount;
}ST_TerminalData_t;

typedef enum EN_TransStat_t
{
    DECLINED,
    APPROVED
    
}EN_TransStat_t;

typedef struct ST_transaction_t
{
    ST_CardData_t Card_Holder_Data;
    ST_TerminalData_t Transaction_Data;
    EN_TransStat_t Transaction_State;
}ST_Transaction_t;

#endif
