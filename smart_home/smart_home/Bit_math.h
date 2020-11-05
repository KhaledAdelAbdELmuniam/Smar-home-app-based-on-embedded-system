/*
 * Bit_math.h
 *
 * Created: 17-Oct-20 1:40:59 PM
 *  Author: Khaled
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_
#define set_bit(Reg,Bit) (Reg |= (1<<Bit))
#define clear_bit(Reg,Bit) (Reg &=~ (1<<Bit))
#define toggle_bit(Reg,Bit) (Rreg ^= (1<<Bit))
#define get_bit(Reg,Bit) ((Reg>>Bit) & 1)
#endif /* BIT_MATH_H_ */