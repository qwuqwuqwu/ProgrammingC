// Problem 82
// D - Determinant

#include <stdio.h>

#define MAX ( 8 )

long long g_M[ MAX ][ MAX ];
int g_nSize = 0;

long long det( long long M[][ MAX ], int nSize )
{
    if( nSize == 2 ) {
        return ( M[ 0 ][ 0 ] * M[ 1 ][ 1 ]
                -M[ 1 ][ 0 ] * M[ 0 ][ 1 ] );
    }

    // larger than size 2
    long long temp = 0;
    long long temp2 = 0;
    long long sign = 1;
    long long N[ MAX ][ MAX ];
    for( int i = 0; i < nSize; i++ ) {
        // prepare N
        for( int j = 1; j < nSize; j++ ) {
            int l = 0;
            for( int k = 0; k < nSize; k++ ) {
                if( k == i ) {
                    continue;
                }
                N[ j - 1 ][ l++ ] = M[ j ][ k ];
            }
        }

        // 
        temp2 = M[ 0 ][ i ] * det( N, nSize - 1  );

        // negative
        if( i % 2 == 1 ) {
            temp -= temp2;
        }
        else {
            temp += temp2;
        }
    }
    return temp;
}

int main( void )
{
    // get matrix
    scanf( "%d", &g_nSize );
    for( int i = 0; i < g_nSize; i++ ) {
        for( int j = 0; j < g_nSize; j++ ) {
            scanf( "%lld", &g_M[ i ][ j ] );
        }
    }

    // get det
    printf( "%lld\n", det( g_M, g_nSize ) );
    return 0;
}