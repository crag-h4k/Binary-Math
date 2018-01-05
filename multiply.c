#include <stdio.h>

int main(void)
{
    /* We are to write C expressions that multiply integer variable x
       by various values of K using only +, -, and << operators, and
       no more than 3 operators total. */

    int x = 10;
    int K;
    int result1;
    int result2;
    
    /* Example: K = 9 */
    K = 9;
    printf("x=%i, K=%i:", x, K);
    result1 = (x << 3) + x;  /* you create expressions like this one */
    result2 = K * x;         /* compute using multiply to compare */
    printf("    +-<< result = %d,    * result = %d\n",result1, result2);
    
    /* Part A */
    K = 33;
    printf("x=%i, K=%i:", x, K);
    result1 = (x << 5) + x;   /* replace this 0 with your C expression */
    result2 = K * x;
    printf("   +-<< result = %d,   * result = %d\n", result1, result2);
    
    /* Part B */
    K = -15;
    printf("x=%i, K=%i:", x, K);
    result1 = x - (x << 4);   /* replace this 0 with your C expression */
    result2 = K * x;
    printf("  +-<< result = %d,  * result = %d\n", result1, result2);
    
    /* Part C */
    K = 24;
    printf("x=%i, K=%i:", x, K);
    result1 = (x << 4) + (x << 3);   /* replace this 0 with your C expression */
    result2 = K * x;
    printf("   +-<< result = %d,   * result = %d\n", result1, result2);
    
    /* Part D */
    K = -132;
    printf("x=%i, K=%i:", x, K);
    result1 = -(x << 7) - (x << 2);   /* replace this 0 with your C expression */
    result2 = K * x;
    printf(" +-<< result = %d, * result = %d\n", result1, result2);
    
    
}