// Problem 46
// Johnny's sugar

#include <stdio.h>
#include <string.h>
#include "stdbool.h"

#define MAX ( 1000 )

int g_Matrix[ MAX + 1 ][ MAX + 1 ];

int find( int* pArr, int nLength, bool bMax )
{
    int nTemp = pArr[ 1 ];
    for( int i = 2; i <= nLength; i++ ) {
        if( bMax == true ) {
            if( pArr[ i ] > nTemp ) {
                nTemp = pArr[ i ];
            }
        }
        else {
            if( pArr[ i ] < nTemp ) {
                nTemp = pArr[ i ];
            }
        }
    }
    return nTemp;
}

int main( void )
{
    int nN = 0;
    scanf( "%d", &nN );

    for( int row = 1; row <= nN; row++ ) {
        for( int col = 1; col <= nN; col++ ) {
            scanf( "%d", &g_Matrix[ row ][ col ] );
        }
    }

    int nArr[ MAX + 1 ];
    // row max
    for( int row = 1; row <= nN; row++ ) {
        memcpy( nArr, g_Matrix[ row ], sizeof( int ) * ( nN + 1 ) );
        if( row != nN ) {
            printf( "%d ", find( nArr, nN, true ) ); // find max
        }
        else {
            printf( "%d\n", find( nArr, nN, true ) ); // find max
        }
    }

    // col min
    for( int col = 1; col <= nN; col++ ) {
        for( int row = 1; row <= nN; row++ ) {
            nArr[ row ] = g_Matrix[ row ][ col ];
        }

        if( col != nN ) {
            printf( "%d ", find( nArr, nN, false ) ); // find min
        }
        else {
            printf( "%d\n", find( nArr, nN, false ) ); // find min
        }
    }

    return 0;
}