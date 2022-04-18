// problem 58
// simple integer sorting

// method: sorting

#include <stdio.h>
#include <string.h>

#define MAXSIZE ( 10000 )

int g_nArray[ MAXSIZE ];

void BubbleSort( int *pnArray, int nLength )
{
    // M1: max, M2: second max
    // X    X   X   X   X   M1
    // X    X   X   X   M2
    // X    X   X   M3

    for( int i = nLength - 2; i >= 0; i-- ) {
        // move the max to the end idx( i + 1 )
        for( int j = 0; j <= i; j++ ) {
            if( pnArray[ j ] > pnArray[ j + 1 ] ) {
                int nTemp = pnArray[ j ];
                pnArray[ j ] = pnArray[ j + 1 ];
                pnArray[ j + 1 ] = nTemp;
            }
        }
    }
}

// try merge sort

int main( void )
{
    int nT = 0;
    scanf( "%d", &nT );
    for( int i = 0; i < nT; i++ ) {
        // initialize every test case
        int nN = 0;
        scanf( "%d", &nN );
        memset( g_nArray, 0, sizeof( int ) * MAXSIZE );
        for( int j = 0; j < nN; j++ ) {
            scanf( "%d", &g_nArray[ j ] );
        }

        // sorting
        // simple bubble sort
        BubbleSort( g_nArray, nN );

        int j = 0;
        for( j = 0; j < nN - 1; j++ ) {
            printf( "%d ", g_nArray[ j ] );
        }
        printf( "%d\n", g_nArray[ j ] );
    }
    return 0;
}