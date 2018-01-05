#if 0
/*

RULE:
You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

*/
#endif
/*
 * bitAnd - x&y using only ~ and |
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */

//Q1
int bitAnd(int x, int y) {
 //simple deMorgan of x*y;
  return ~(~x | ~y);
}
/*
 * bitNor - ~(x|y) using only ~ and &
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
 //Q2
int bitNor(int x, int y) {
//same as above, simple demorgan
 return (~x & ~y);

}
/*
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
 //Q3
int copyLSB(int x) {
  //shifts to get rid of all bits to the left of lsb,
  //then shifts right to copy lsb
  return ((x<<31)>>31);
}
/*
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
 //Q4
int evenBits(void) {
//this one was super easy, just
//create an even bit number 0101 0r 5;
// then shift it onto 32bit number giving
// 0x55555555
  int x = 0x55;
  int y = (x+(x<<8)+(x<<16)+(x<<24));
  //return ~(~x);
  return y;
}
/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
 //Q5

int logicalShift(int x, int n) {
 //shift x to the right of n, then x AND shift 1 all the way to left
 //then push N back to right 1 in to the left
  return (x>>n) ^(((x&(1<<31)) >>n) <<1);
}
/*
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
 //Q6
int bang(int x) {
  //invert x, Only value for x would be zero,  then add one to it.
	//ms OR x, then shift right 31, making MSB the value of B(0 or 1)
  int mx = ~x+1;
  int b = (mx |x) >> 31;
  return b + 1;
}
/*
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
 //Q7
int leastBitPos(int x) {
  //x and logical negation of x return the mask we want
  return x &(~x + 1);
}
/*
 * isNotEqual - return 0 if x == y, and 1 otherwise
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
 //Q8
int isNotEqual(int x, int y) {
  //XOR can used to show equality, the !! makes the comparison more simple
  return !!(x ^ y);
}
/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
 //Q9
int negate(int x) {
  //simply just return the invert of x
  // before add 1 it was always off by one number, so what the heck?!
  return ~x + 1;
}
/*
 * isPositive - return 1 if x > 0, return 0 otherwise
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
 //Q10
int isPositive(int x) {
  //shift MSB over, then OR with logical
  //not to check if it's 0, not just negative

  return !(x>>31|!x);
}
/*
 * isNonNegative - return 1 if x >= 0, return 0 otherwise
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
 //Q11
int isNonNegative(int x) {
  //>> is checking the MSB, then negate to return a simple 0(false) or 1(true)
  return !(x>>31);
}
/*
 * rotateLeft - Rotate x to the left by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateLeft(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 */
 //Q12
int rotateLeft(int x, int n) {
  int low_mask, high_mask, save, mshift;
  mshift = 33 + ~n;

  //saves the bits that come to front after shift
  high_mask = ~0  << mshift;

  //takes care of MSB
  low_mask = ~(~0 << n);

  //saves the bits saved after shift, then moves then, AND takes care of MSB
  save = ((x & high_mask) >> mshift) & low_mask;
  //returns the shifted number with wraparound bits
  return (x << n) | save;
}
/*
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1,
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
 //Q13
int addOK(int x, int y) {

//get signs of x and y
  int xMSB = x >> 31;
  int yMSB = y >> 31;
 //must make sure the sum of x and y signs are not the same
  int MSB_sum = (x+y) >>31;
//invert XOR to show its one or the other
  //AND XOR x with sum of XY
  //then not whole thing to return proper result
  return !(~(xMSB ^ yMSB) & (xMSB ^ MSB_sum));
}
/*
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
 //Q14
int absVal(int x) {
  //x + or -
  int xMSB = x >> 31;
  //returns x when positive and 2s comp when -x
  return((x^xMSB) + (1 +(~xMSB)));
}
/*
 * isNonZero - Check whether x is nonzero using
 *              the legal operators except !
 *   Examples: isNonZero(3) = 1, isNonZero(0) = 0
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
 //Q15


 //The following
int isNonZero(int x) {
	//can't simply negate 0 to check
	//OR then shift MSB to LSB then return it AND 1 to check
  return ((x | (~x +1)) >> 31) & 0x01;
}

int any_bit_zero(int x) {
    // Fill in code for part B here.	
	// Any bit of x = 0
	//the same as the function above, just need to flip
	return !!~x;
}

int lsb_one(int x) {
    // Fill in code for part C here.
    // return true when Any least significant byte of x = 1
    return !!(x & 0xFF);
    // & 0xFF leaves only the least significant byte,
    // need to combine any_bit_one() to give least significant
    // byte if x=1
}

int msb_zero(int x) {
    // Fill in code for part D here.
    // return true when Any most significant byte of x = 0
    int y = (sizeof(x)-1) << 3;
    //y - 8;
    return !!(~x & (0xFF<<y));

}
