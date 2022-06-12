// Problem 37
// AAAAAAAAAAAA~
#include <stdio.h>

#define MAX ( 200 )
// #define MAX ( 2000000 )

int g_B[ MAX + 1 ];

// This arr contains n numbers and start from index 0
// q is the query number which you nned to find the index
// n is the length of arr
int BS(int* arr, int q, int n)
{
    if( n <= 0 ) {
        return -1;
    }

    int nMid = n / 2;
    if( arr[ nMid ] == q ) {
        return nMid;
    }
    // find larger part
    else if( arr[ nMid ] < q ) {
        return nMid + 1 + BS( &arr[ nMid + 1 ], q, n - nMid - 1 );
    }
    // find smaller part
    else {
        return BS( arr, q, nMid );
    }
}

int find( int nStart, int nEnd, int nTarget )
{
    if( nEnd < nStart ) {
        return -1;
    }

    int nMid = ( nEnd - nStart ) / 2 + nStart;
    if( g_B[ nMid ] == nTarget ) {
        return nMid;
    }
    // find larger part
    else if( g_B[ nMid ] < nTarget ) {
        return find( nMid + 1, nEnd, nTarget );
    }
    // find smaller part
    else {
        return find( nStart, nMid - 1, nTarget );
    }
}

int main( void )
{
    int nN = 0;
    int nT = 0;
    scanf( "%d%d", &nN, &nT );

    for( int i = 0; i < nN ; i++ ) {
        scanf( "%d", &g_B[ i ] );
    }

    for( int i = 0; i < nT; i++ ) {
        int nTarget = 0;
        int nPos = 0;
        scanf( "%d", &nTarget );
        nPos = BS( g_B, nTarget, nN );
        // nPos = find( 1, nN, nTarget );
        printf( "%d is at index: %d\n", nTarget, nPos );
    }

    return 0;
}