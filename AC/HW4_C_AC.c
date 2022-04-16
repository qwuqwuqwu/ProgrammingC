#include <stdio.h>

#define MIN( a, b ) ( ( a ) < ( b ) ? ( a ) : ( b ) )

enum ERGB {
    ERGB_R = 0,
    ERGB_G = 1,
    ERGB_B = 2,
    ERGB_NUM = 3,
};

long long Algorithm( int nRGB[ 3 ] )
{
    long long nCount = 0;
    int nSpecialCase = 0;

    // find minimum
    int nMinIdx = 0;
    for( int i = 1; i <= 2; i++ ) {
        if( nRGB[ i ] < nRGB[ nMinIdx ] ) {
            nMinIdx = i;
        }
    }

    // find maximum
    int nIdxArray[ 2 ] = { 0 };
    int j = 0;
    for( int i = 0; i < 3; i++ ) {
        if( i == nMinIdx ) {
            continue;
        }
        nIdxArray[ j ] = i;
        j++;
    }

    int nMaxIdx = 0;
    int nMiddleIdx = 0;
    if( nRGB[ nIdxArray[ 0 ] ] > nRGB[ nIdxArray[ 1 ] ] ) {
        nMaxIdx = nIdxArray[ 0 ];
        nMiddleIdx = nIdxArray[ 1 ];
    }
    else {
        nMaxIdx = nIdxArray[ 1 ];
        nMiddleIdx = nIdxArray[ 0 ];
    }
    
    //
    long long temp = ( nRGB[ nMaxIdx ] + nRGB[ nMiddleIdx ] - nRGB[ nMinIdx ] ) / 2;
    nCount = MIN( temp, nRGB[ nMiddleIdx ] );
    nCount += nRGB[ nMinIdx ];
    //return MIN( ( nRGB[ nMaxIdx ] + nRGB[ nMiddleIdx ] - nRGB[ nMinIdx ] ) / 2, nRGB[ nMiddleIdx ] ) + nRGB[ nMinIdx ];
    return nCount;
    nCount = ( long long )nRGB[ nMinIdx ];
    if( nSpecialCase == 0 ) {
        // case normal: max - min
        nRGB[ nMaxIdx ] -= nRGB[ nMinIdx ];
    }
    else if( nSpecialCase == 1 ) {
        // case special 1
        if( nRGB[ nMinIdx ] % 2 == 1 ) {
            nRGB[ nMaxIdx ] -= ( nRGB[ nMinIdx ] / 2 );
            nRGB[ nMiddleIdx ] -= ( nRGB[ nMinIdx ] / 2 );
            nRGB[ nMiddleIdx ] -= 1;
        }
        else {
            nRGB[ nMaxIdx ] -= ( nRGB[ nMinIdx ] / 2 );
            nRGB[ nMiddleIdx ] -= ( nRGB[ nMinIdx ] / 2 );
        }
    }
    else if( nSpecialCase == 2 ) {
        return nCount;
    }

    // second - min
    if( nRGB[ nMaxIdx ] > nRGB[ nMiddleIdx ] ) {
        nCount += ( long long )( nRGB[ nMiddleIdx ] );
    }
    else {
        nCount += ( long long )( nRGB[ nMaxIdx ] );
    }

    return nCount;
}

int main( void ) {
    int t = 0;
    int nRGB[ 3 ] = { 0 };

    scanf( "%d", &t );

    for( int i = 0; i < t; i++ ) {
        scanf( "%d%d%d", &nRGB[ 0 ], &nRGB[ 1 ], &nRGB[ 2 ] );
        printf( "%lld\n", Algorithm( nRGB ) );
    }
    return 0;
}