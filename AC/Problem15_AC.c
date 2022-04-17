// problem 15
// Factor Counter

// method: basic math, prefix table

#include <stdio.h>
#include <math.h>

#define MAX ( 20000 )
int g_nFactorsCount[ MAX + 1 ];

void CountFactors( int i )
{
    g_nFactorsCount[ i ] = 0;
    int nSqrtNum = ( int )( sqrt( ( double )i ) );
    for( int j = 1; j <= nSqrtNum; j++ ) {
        if( ( i % j ) == 0 ) {
            if( j * j == i ) {
                g_nFactorsCount[ i ]++;
            }
            else {
                g_nFactorsCount[ i ] += 2;
            }
        }
    }
}

int main( void )
{
    // count factors count of each number
    g_nFactorsCount[ 0 ] = 0;
    for( int i = 1; i <= MAX; i++ ) {
        CountFactors( i );
    }

    int nT = 0;
    int nL = 0;
    int nR = 0;
    int nMaxCount = 0;
    int nMaxNumber = 0;
    scanf( "%d", &nT );
    for( int i = 0; i < nT; i++ ) {
        scanf( "%d%d", &nL, &nR );
        nMaxCount = 0;
        nMaxNumber = 0;
        // find max in count factors
        for( int j = nL; j <= nR; j++ ) {
            // only record larger not equal one
            if( g_nFactorsCount[ j ] > nMaxCount ) {
                nMaxNumber = j;
                nMaxCount = g_nFactorsCount[ j ];
            }
        }
        printf( "%d\n", nMaxNumber );
    }
    return 0;
}