// problem 22
// No, I don't know the way, but....

// method: printf %.3f

#include <stdio.h>

int main( void )
{
    float a;
    float b;
    scanf( "%f%f", &a, &b );
    printf( "%.3f\n", a + b );

    return 0;
}