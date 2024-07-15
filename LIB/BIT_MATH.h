/*
 * BIT_MATH.h
 *
 *  Created on: Sep 19, 2023
 *      Author: Elyabanya
 */

#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_

#define SET_BIT(REG,BIT)  (REG |= (1<<BIT))
#define CLR_BIT(REG,BIT)  (REG &=~(1<<BIT))
#define TOGGLE_BIT(REG,BIT)  (REG ^= (1<<BIT))
#define GET_BIT(REG,BIT)   ((REG>>BIT) & 0x01)
#endif /* LIB_BIT_MATH_H_ */
