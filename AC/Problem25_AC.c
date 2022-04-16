// problem 25
// pB - Birthday Party

#include <stdio.h>
#include <stdbool.h>

long long gcd( long long lhs, long long rhs )
{
    if( rhs == 0 ) {
        return lhs;
    }
    else {
        return gcd( rhs, lhs % rhs );
    }
}

int main ( void )
{
    int nT = 0;
    scanf( "%d", &nT );

    for( int i = 0; i < nT; i++ ) {
        // each test case
        // initialize
        long long nN = 0;
        long long nX1 = 0;
        long long nX2 = 0;
        long long nX3 = 0;
        scanf( "%lld%lld%lld%lld", &nN, &nX1, &nX2, &nX3 );

        // count X1
        nX1 = gcd( nN, nX1 );

        // count X2
        nX2 = gcd( nN, nX2 );

        // count X3
        nX3 = gcd( nN, nX3 );

        // calculate first LCM
        long long nLCM = 1;
        long long nGCD = 1;

        nGCD = gcd( nX1, nX2 );
        nLCM = nX1 * ( nX2 / nGCD );
        // NOTICE!!!
        // ( nX2 /nGCD ) divide first then multiply nX1 * ()
        // because test data 5 consist of 10^18 input
        // if 10^18 * 10^18, out of long long range(2^31 - 1 about 10^18)

        // calculate second LCM
        // find LCM of nLCM & nX3
        nGCD = gcd( nLCM, nX3 );
        nLCM = nLCM * ( nX3 / nGCD );

        //printf( "LCM = %lld\n", nLCM );
        nLCM = gcd( nN, nLCM );

        // no remainder
        if( ( nN % nLCM ) == 0 ) {
            printf( "%lld\n", nN / nLCM );
        }
        else {
            printf( "%lld\n", nN );
        }
    }
    return 0;
}