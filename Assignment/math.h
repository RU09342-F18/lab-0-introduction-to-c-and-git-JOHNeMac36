/**
 * @file math.h
 * @author John McAvoy
 * @date 8 Sep 2018
 */

#ifndef MATH_H_
#define MATH_H_

/**
 * Performs bitwise arithmetic on two signed integers
 * '+' Add (lhs + rhs)
 * '-' Subtract (lhs - rhs)
 * '*' Multiply (lhs * rhs)
 * '/' Divide (lhs / rhs)
 * '%' Modulus (lhs % rhs)
 * '<' Left Shift (lhs << rhs)
 * '>' Right Shift (lhs >> rhs)
 * '&' Bitwise AND (lhs & rhs)
 * '|' Bitwise OR (lhs | rhs)
 * '^' Bitwise XOR (lhs ^ rhs)
 * '~' Bitwise Inverse (~lhs) for this operation, lhs and rhs are still needed
 * @param lhs left-hand sided integer
 * @param rhs right-hand sided integer
 * @param op operator
 * @return integer result of the operation
 */
int math(int lhs, int rhs, char op);

#endif /* MATH_H_ */
