/**
 * @file math.c
 * @author John McAvoy
 * @date 8 Sep 2018
 */

#include <stdio.h> // fprintf
#include "math.h"

// @define default return value if operator is invalid
#define INVALID_OPERATOR 0

int math(int lhs, int rhs, char op) {
    // selects operation based on op character
    switch(op) {
        case '+': return lhs + rhs; // add
        case '-': return lhs - rhs; // subtract
        case '*': return lhs * rhs; // multiply
        case '/': return lhs / rhs; // divide
        case '%': return lhs % rhs; // modulus
        case '<': return lhs << rhs; // left shift
        case '>': return lhs >> rhs; // right shift
        case '&': return lhs & rhs; // bitwise and
        case '|': return lhs | rhs; // bitwise or
        case '^': return lhs ^ rhs; // bitwise xor
        case '~': return ~lhs; // bitwise inverse

        // handles invalid operator character and prints to stderr
        default:
            fprintf(stderr, "Invalid Operator '%c'!\n", op);
            return INVALID_OPERATOR;
    }
}
