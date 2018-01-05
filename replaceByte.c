#include <stdio.h>
unsigned replacebyte(unsigned, int, unsigned);

int main()
{
    unsigned x, b, result;
    int i;
    int done;

    done = 0;
    printf("Enter zeroes for x, i, b to quit\n");
    while (!done)
    {
	// output prompt and get value of x
	printf("\nInput (hex) value of x: ");
	scanf("%x",&x);
	printf("Input (decimal) value of i: ");
	scanf("%d",&i);
	printf("Input (hex) value of b: ");
	scanf("%x",&b);
	result = replacebyte(x, i, b);

	// now output result
	printf("Result = 0x%.8x [Input values were 0x%.8x (x), %d (i) and 0x%.1x (b)]\n",
	       result,x, i, b);
	if (x == 0 && i == 0 && b==0)
	    done = 1;
    }
}

unsigned replacebyte(unsigned x, int i, unsigned b)
{
		//integers are 4bytes, therefore the shift must be 8 bytes
        int m = i << 3;
        int MK = 0xFF << m;
        int shift = b << m;
        return (x & ~MK) | (shift << m);
}
