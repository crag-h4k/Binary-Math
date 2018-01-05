#include <stdio.h>
#include <limits.h>
/* Determine whether arguments can be subtracted without overflow */
int tsub_ok (int, int);

int main() 
{
	int x, y, result;

	printf("Number of bits in an integer in this system = %lu\n\n",(sizeof(int))<<3);
	printf("\nInput value of x: ");
	scanf("%i",&x);
	printf("Input value of y: ");
	scanf("%i",&y);

	result = tsub_ok(x, y);
	printf("\nx=%i,  y=%i, x-y=%i, Result = %i \n", x, y, x-y, result);  // result: 1=No-overflow, 0=Overflow
}

/* Determine whether arguments can be subtacted without overflow
This function should return 1 if the computation of 
x-y does not overflow */

int tsub_ok(int x, int y)
{
	int overflow;   // 1=No-overflow, 0=Overflow
	//insert your code here to test whether x-y overflows

	int sum = x - y; 
	//this is a really simple way to show if the sum of 
	// x-y exceeds the max integer for our system
	// make sure negative numbers don't overflow
	if (sum > INT_MAX){
		overflow = 0;
	}
	
	//this is a really simple way to show if the sum of 
	// x-y exceeds the min integer for our system, this will
	// make sure negative numbers don't overflow
	else if (sum < INT_MIN){
		overflow = 0;
	}
	
	//since neither of those have overflow, return true
	else {
		overflow = 1;
	}
	
	return (overflow);
}




