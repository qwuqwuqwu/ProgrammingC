#include <stdio.h>

int main( void ) {
    unsigned int A = 0; // a+b
    unsigned int B = 0; // b+c
    unsigned int C = 0; // c+a

    unsigned int a = 0;
    unsigned int b = 0;
    unsigned int c = 0;
    unsigned int Sum = 0; // a+b+c

    scanf( "%u%u%u", &A, &B, &C );

    Sum = ( A + B + C ) / 2;
    a = Sum - B;
    b = Sum - C;
    c = Sum - A;

    printf( "%u %u %u\n", a, b, c );
    return 0;
}