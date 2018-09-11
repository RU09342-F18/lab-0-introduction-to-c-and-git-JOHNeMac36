/**
 * @file test_cli.c
 * @author John McAvoy
 * @date 8 Sep 2018
 */

#include <stdio.h> // printf, fprintf
#include <stdlib.h> // strtol
#include <string.h> // strcmp
#include "math.h" // custom math function

// @define default return value for success
#define EXIT_SUCCESS 0
// @define default return value for failure
#define EXIT_FAILURE 1

/**
 * Parses radix of integer value from string
 * string entered based on format:
 *  binary: "0b..."
 *  hex: "0x..."
 *  decimal: anything else
 * @param intStr integer entered as string
 * @return radix: 2, 10, or 16
 */
unsigned short parseRadix(const char* intStr);

/**
 * Parses string argument representing a either a
 * binary, decimal, or hexadecimal integer
 * @param arg string in the form "0b...","0x..", or any base-10 integer
 * @returns the corresponding signed integer value
 */
int parseArgInt(const char* arg);

/**
 * Function demo cli
 * @param argc argument count passed from the shell
 * @param argv array of argument strings passed from the shell
 * @return EXIT_SUCCESS if correct number of args are passed or EXIT_FAILURE otherwise
 */
int main(int argc, char *argv[]) {
    // correct number of args are passed from the shell
    if(argc == 4) {

        // parses lhs integer from second arg
        const int lhs = parseArgInt(argv[1]);
        // sets operator equal to first character of thrid arg
        const char op = *argv[2];
        // parses rhs integer from fourth arg
        const int rhs = parseArgInt(argv[3]);

        // performs math operation on the parsed values
        const int result = math(lhs, rhs, op);

        // prints result in decimal
        printf("Dec:\t%-10d %c %-10d = %-10d\n", lhs, op, rhs, result);
        // prints result in hexadecimal
        printf("Hex:\t0x%-8x %c 0x%-8x = 0x%-8x\n", lhs, op, rhs, result);

        return EXIT_SUCCESS; // success
    }
    // incorrect number of args are passed from the shell
    else {

        // print error message to stderr
        fprintf(stderr, "math testbench -- performs basic bitwise operations on two signed integers\n");
        fprintf(stderr, "usage: math [<lhs>:integer] [<op>:operator] [<rhs>:integer]\n");
        fprintf(stderr, "\tintegers:\n");
        fprintf(stderr, "\t\tbinary:  ex: 0b1, 0b10, 0b1101, ...\n");
        fprintf(stderr, "\t\tdecimal: ex: 1, 7, -99, ...\n");
        fprintf(stderr, "\t\thex:     ex: 0x1, 0x1f, 0xfffffa4f, ...\n");
        fprintf(stderr, "\toperators:\n");
        fprintf(stderr, "\t\t+, -, *, /, %, <, >, &, |, ^, ~\n");

        return EXIT_FAILURE; // failure
    }
}

unsigned short parseRadix(const char* intStr) {
    unsigned short radix; // declare radix
    const char prefix[] = {intStr[0], intStr[1]}; // prefix the first two characters

    if(strcmp(prefix,"0x") == 0){
        // if intStr starts with "0x", radix is hexadecimal
        radix = 16;
    }
    else if(strcmp(prefix,"0b") == 0){
        // if intStr starts with "0b", radix is binary
        radix = 2;
    }
    else
        // else, radix is decimal
        radix = 10;

    return radix; // returns radix
}

int parseArgInt(const char* arg) {
    const unsigned short radix = parseRadix(arg); // parses the radix

    // numStr is the "number part" of an integer string.
    // i.e the part after "0x" or "0b" for hex and binary
    // or just entire string for base-10
    const char *numStr = radix == 10 ? &arg[0] : &arg[2];

    // converts string to long based on radix, then casts to int
    // @see strol
    return (int) strtol(numStr, NULL, radix); // returns parsed int
}
