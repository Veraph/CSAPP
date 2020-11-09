/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
    /* the trick here
     * is to firstly delete the common 1
     * and then delete the common 0
     * and do the & to get the different bits
     */
    return ~(x & y) & ~(~x & ~y);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
    /* As the tmin form is like 0b10000...
     * and the 8 bit tmin is 0x80,
     * hence we just create an int 0b1 and shift
     * left 31 postions.
     */
    return 0x1 << 31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
    /* The Tmax form is like 0b011111...
     * we know that the tmax is 0x7fff...
     * and the negate of tmax is 0x8000..
     * so we only need to check whether
     * the x + 1 == ~x
     *
     * and we should to be careful about the
     * extrem situation when x = 0xfffff..
     */
    return !(((x + 1) ^ ~x) + !(x + 1));


}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
    /* The key is firstly we shift right 1 bit to
     * let the 1st bit on the 0 bit position
     * and then we continuous to do & operations
     * with x >> 2, x >> 4, x >> 8, x >> 16
     * to store all 1's situation on the 1st bit
     * if there is any odd bit not equal to 1
     * the 1st bit will be 0
     */
    x = x >> 1;
    x &= x >> 2;
    x &= x >> 4;
    x &= x >> 8;
    x &= x >> 16;
    return x & 0x1;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
    /* We should read this carefully
     * we have to change the value itself
     * not only the first bit of the hex
     */
    return ~x + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
    /* The key point here is to
     * set a upper bound and lower bound
     * if x is bigger than 0x39, the upper bound
     * will be negative; if x is less than 0x30,
     * the lower bound will be negative.
     * Then we just need to check whether the sign in
     * one of the bounds is  negative,
     * then it is not ascii digit
     */

    int sign = 1 << 31;
    int upperbound = ~(sign | 0x39);
    int lowerbound = ~0x30;

    upperbound = sign & (upperbound + x) >> 31;
    lowerbound = sign & (lowerbound + x + 1) >> 31;

    return !(upperbound | lowerbound);
}

/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
    /* the logic is if x != 0
     * return y, else return z
     * to achieve this, we can first generate all x
     * bits to the first bit, like 0x01 or 0x00, and based
     * on this we could shift left 31 bit and shift right 31 bit
     * to generate 0xfff... or 0x000..as our mask and do the final
     * operation
     */
    int mask;
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    mask = x << 31 >> 31;
    /* same as (mask & y) | (mask ^ z); */
    return (mask & y) | (~mask & z);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
    /* the key is to use | >> for x and y respectively
     * to create form like 000..111..for x and y
     * if x is less or equal to y, then x has less
     * or equal 1s compared with y,
     * then we just do the ~ operation on y and do the 
     * & operation, if x <= y, the answer will be 0
     *
     *  NOT WORKING beacuse we can not use unsigned
     *  x |= x >> 1;
     *  x |= x >> 2;
     *  x |= x >> 4;
     *  x |= x >> 8;
     *  x |= x >> 16;

     *  y |= y >> 1;
     *  y |= y >> 2;
     *  y |= y >> 4;
     *  y |= y >> 8;
     *  y |= y >> 16;
     *  return !(x & ~y);
     */

    /* Below code uses the thinking of negate */
    int negX = ~x + 1;
    int addY = negX + y; /* if x <= y, the result will be non-negative */
    int checkSign = addY >> 31 & 1; /* will be 0 if x less or equal to y */

    /* we still need to deal with the situation when addY is excess the bound */
    int leftBit = 1 << 31;
    /* xLeft (yLeft) will be leftBit if they are negative */
    int xLeft = x & leftBit;
    int yLeft = y & leftBit;
    int xOrd = xLeft ^ yLeft; /* any of them have 1 will result in xOrd = 1*/
    xOrd = (xOrd >> 31) & 1;

    /* if xOrd, we will check it must be x have the negative
     * or it is wrong.
     * if not xOrd, then we know both of them are neg or pos,
     * we have to check the addY sign to make sure it is 0
     */
    return (xOrd & (xLeft >> 31)) | (!checkSign & !xOrd);
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
    /* The key is, for all value except 0
     * the ~x + 1 will get the sign bit different
     * than the x
     * 0 will get two zero.
     * we just need to shift this value 31 bits to the right
     * and add 1.
     * 0x00... + 1 will be 1 and 0xff... + 1 will be 0
     */
    return ((x | (~x + 1)) >> 31) + 1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
    /* the key here is to understand that the bit number
     * needed for non-negative and negative is the same
     * like:
     * 3 2 1 0 --- -1 -2 -3 -4
     * hence we can extract the sign bit and convert the
     * negative to non-negative to simpler the calculation
     *
     * then we could use | >> operation to convert the x into
     * the form like 000...111.., as there are 32 different 
     * represting way, hence we connect these represting ways with
     * the bit number
     *
     * and we could get a formular like 1 << (n-1) = known + 1
     * the question is how can we extract the only unknown n,
     * if we figure out this, then the n is the answer
     *
     * a beautiful solution is to use bit level shift to add all
     * bits needed to sum up the n we needed.
     */
    int mask, bit16, bit8, bit4, bit2, bit1, bit0;
    mask = x >> 31;
    x = x ^ mask;

    bit16 = !!(x >> 16) << 4;/* here the !! is the trick to perform x ? 1 : 0 to normalize */
    x = x >> bit16;

    bit8 = !!(x >> 8) << 3;
    x = x >> bit8;

    bit4 = !!(x >> 4) << 2;
    x = x >> bit4;

    bit2 = !!(x >> 2) << 1;
    x = x >> bit2;

    bit1 = !!(x >> 1);
    x = x >> bit1;

    bit0 = x;

    return bit16 + bit8 + bit4 + bit2 + bit1 + bit0 + 1; /* 1 here represent the sign */
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
    /* The key here
     * is to split the uf into unsigned, exp and frac
     * three parts.
     * then we discuss the result based on the status of exp.
     * if the result will be the normalised, we just do the
     * left shift on exp part;
     * when the argument is NaN, we just return argument.
     */
    unsigned sign, exp, frac;
    sign = uf >> 31;
    exp = uf >> 23 & 0xFF;
    frac = uf & 0x7FFFFF;

    if (exp == 0xFF)
	return uf;

    if (!exp)
	/* when it is denormalised */
	frac <<= 1;
    else if (exp == 0xFE) {
	/* when it will be nan */
	exp = 0xFF;
	frac = 0;
    } else
	exp += 1;


    return (sign << 31) | (exp << 23) | frac; 
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
    /* The same strategy as the previous one
     * but we split the float number into three parts,
     * deal with each part and assemble them together to
     * form an int;
     * we should be careful about the situation of overflow (return 0x80...)
     * and we should also be careful about the rounding issue
     */
    unsigned sign = uf >> 31;
    unsigned exp = uf >> 23 & 0xFF;
    unsigned frac = uf & 0x7FFFFF;
    unsigned bias = 0x7f;
    int num;

    if (bias > exp && exp >= 0)
	/* then we get num less than 1 */
	return 0;
    else if (exp >= 31 + bias)
	/* overflow, this include nan and infinity */
	return 0x80000000;
    else {
	unsigned E = exp - bias;
	unsigned M = frac | 0x800000; /* add the 1 as M = 1 + f */
	if (E > 23)
	    /* apart from the 23 bit in int, we have to left shift more */
	    num = M << (E - 23);
	else
	    num = M >> (23 - E);
    }

    return sign ? -num : num;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
    /* As we only need to calculate the 2 raised to power
     * x, so we only need to consider the exp part
     */
    int INF = 0xFF << 23;
    int exp = x + 127;
    if (exp <= 0)
	return 0;
    if (exp >= 255)
	return INF;
    return exp << 23;
}
