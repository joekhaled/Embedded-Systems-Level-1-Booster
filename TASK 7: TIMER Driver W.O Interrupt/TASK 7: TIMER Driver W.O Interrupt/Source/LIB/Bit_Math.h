#ifndef Bit_Math_h
#define Bit_Math_h

#define SET_BIT(Byte,BIT_NO)     (Byte)  = (Byte) |  (1 << BIT_NO)   // Set bit Macro
#define CLEAR_BIT(Byte,BIT_NO)   (Byte)  = (Byte) & ~(1 << BIT_NO)   // Clear bit Macro
#define TOGGLE_BIT(Byte,BIT_NO)  (Byte)  = (Byte) ^  (1 << BIT_NO)   // Toggle bit Macro

#define READ_BIT(Byte,BIT_NO)    ((Byte)  &  (1 << BIT_NO) )         // Read bit Macro

#endif
