// Problem 68
// Uncle Huang Points Tutor

#include <stdio.h>
#include "math.h"

unsigned long long findCommon( unsigned long long nNum )
{
    unsigned long long nMid = sqrt( nNum );
    for( unsigned long long test = nMid; test >= 2; test-- ) {
        if( nNum % test == 0 ) {
            return test;
        }
    }
    return 1;
}

unsigned long long calc( unsigned long long base, unsigned long long nPow, unsigned long long nMod )
{
    if( nPow == 2 ) {
        unsigned long long temp = ( ( base % nMod ) * ( base % nMod ) ) % nMod;
        if( temp < 0 ) {
            temp += nMod;
        }
        return temp;
    }
    else if( nPow == 1 ) {
        unsigned long long temp = ( base % nMod );
        if( temp < 0 ) {
            temp += nMod;
        }
        return temp;
    }
    else if( nPow <= 0 ) {
        return 1 % nMod; // need to mod here, because 1 mod 1 = 0
    }

    base %= nMod;
    if( base < 0 ) {
        base += nMod;
    }

    
    unsigned long long nMidPow = findCommon( nPow );
    unsigned long long nRestPow = nPow / nMidPow;

    if( nMidPow == 1 ) {
        unsigned long long temp = ( ( base % nMod ) * ( calc( base, nRestPow - 1, nMod ) % nMod ) ) % nMod;
        if( temp < 0 ) {
            temp += nMod;
        }
        return temp;
    }

    // need to multiply
    unsigned long long temp = calc( base, nRestPow, nMod ) % nMod;
    if( temp < 0 ) {
        temp += nMod;
    }

    unsigned long long temp2 = calc( temp, nMidPow, nMod ) % nMod;
    if( temp2 < 0 ) {
        temp2 += nMod;
    }
    return temp2;
}

int main( void )
{
    unsigned long long x;
    unsigned long long y;
    unsigned long long m;

    scanf( "%llu%llu%llu", &x, &y, &m );

    unsigned long long a = calc( x, y, m );
    printf( "%d\n", ( int )a );
    return 0;
}