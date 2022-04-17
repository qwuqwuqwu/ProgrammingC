// problem 26
// The Big Hammer Rise

// method: get double by two int, printf %04d

#include <stdio.h>

int main( void )
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    scanf( "%d.%2d %d.%2d", &a, &b, &c, &d );
    int A = 100 * a + b;
    int B = 100 * c + d;
    int C = A * B;
    printf( "%d.%04d\n", C / 10000, C % 10000 ); // 0 in 04 is needed 
    return 0;
}
