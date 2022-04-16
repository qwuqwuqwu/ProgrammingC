// problem 18
// Easy Palindrome

#include <stdio.h>

#define LEN ( 3 )

int main( void )
{
    int a = 0;
    int b = 0;
    int N = 0;
    int M = 0;
    float Sum = 0.0;

    // six-digit floating point
    scanf( "%d.%3d", &a, &b );
    N = 1000 * a + b;
    int nTemp_front = a;
    int nTemp_hind = b;

    // get M (by reverse N)
    int Array_front[ LEN ];
    int Array_hind[ LEN ];

    for( int i = 0; i < LEN; i++ ) {
        Array_front[ i ] = nTemp_front % 10;
        nTemp_front /= 10;
    }
    for( int i = 0; i < LEN; i++ ) {
        Array_hind[ i ] = nTemp_hind % 10;
        nTemp_hind /= 10;
    }

    // reverse
    int M_front = 0;
    int M_hind = 0;
    for( int i = 0; i < LEN; i++ ) {
        M_front = M_front * 10 + Array_front[ i ];
    }
    for( int i = 0; i < LEN; i++ ) {
        M_hind = M_hind * 10 + Array_hind[ i ];
    }

    M = M_front * 1000 + M_hind;
    Sum = ( float )N + ( float )M;
    Sum /= 1000;

    printf( "%.3f", Sum );

    return 0;
}