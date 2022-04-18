// problem 40
// the three number

// method: basic math
#include <stdio.h>
int main( void )
{
    int a;
    int b;
    int c;
    int A;
    int B;
    int C;
    scanf( "%d%d%d", &A, &B, &C );
    // A = a + b, B = b + c, C = c + a
    int sum = ( A + B + C ) / 2;
    c = sum - A;
    a = sum - B;
    b = sum - C;
    printf( "%d %d %d\n", a, b, c ); 
    return 0;
}