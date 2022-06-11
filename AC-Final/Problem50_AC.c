// Problem 50
// de way to home
#include <stdio.h>
#include <stdbool.h>
#define MAX ( 1000000 )

int g_nN;
int g_nQ;
int g_nA[ MAX ];

bool BinarySearch( const int nTarget, const int nStartIdx, const int nEndIdx )
{
    // ending condition
    if( nEndIdx < nStartIdx ) {
        return false;
    }

    // middle
    int nMidIdx = nStartIdx + ( nEndIdx - nStartIdx ) / 2;

    if( g_nA[ nMidIdx ] == nTarget ) {
        return true;
    }
    // find before
    else if( g_nA[ nMidIdx ] > nTarget ) {
        return BinarySearch( nTarget, nStartIdx, nMidIdx - 1 );
    }
    // find after
    else {
        return BinarySearch( nTarget, nMidIdx + 1, nEndIdx );
    }
}

void search( const int nTarget )
{
    bool bFound = false;

    bFound = BinarySearch( nTarget, 0, g_nN - 1 );

    if( bFound == true ) {
        printf( "I know de way to your home.\n" );
    }
    else {
        printf( "Wake up, you homeless poor.\n" );
    }
}

int main( void )
{
    scanf( "%d%d", &g_nN, &g_nQ );
    // a is in ascending order
    for( int i = 0; i < g_nN; i++ ) {
        scanf( "%d", &g_nA[ i ] );
    }

    for( int i = 0; i < g_nQ; i++ ) {
        int nTarget = 0;
        scanf( "%d", &nTarget );
        search( nTarget );
    }

    return 0;
}