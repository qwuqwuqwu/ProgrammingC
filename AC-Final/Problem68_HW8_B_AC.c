// Problem 68
// Uncle Huang Points Tutor
#include <stdio.h>
#include "math.h"

unsigned long long calc( unsigned long long x, unsigned long long y, unsigned long long m )
{
    if( y == 0 ) {
        return 1;
    }

    unsigned long long temp = calc( x, ( y / 2 ), m );
    temp = ( ( temp % m ) * ( temp % m ) ) % m;

    if( y % 2 == 1 ) {
        temp = ( temp * ( x % m ) ) % m;
    }
    return temp;
}

int main( void )
{
    unsigned long long x;
    unsigned long long y;
    unsigned long long m;

    scanf( "%llu%llu%llu", &x, &y, &m );

    unsigned long long a = calc( x, y, m );

    // special case
    // if m == 1, x^y % 1 always equal 0
    if( m == 1 ) {
        printf( "0\n" );
        return 0;
    }
    printf( "%d\n", ( int )a );
    return 0;
}