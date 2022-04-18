// problem 77
// Salary thief

// method: basic math, string operation

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN     ( 1000001 )
#define MAXIDX  ( LEN - 2 )
#define MOD     ( 1000000000 + 7 )

char g_cInput[ LEN ];

int Do( const int nX )
{
    int nAdd = 0;
    int nLeft = 0;
    int nTailLen = 0;
    char Temp[ LEN ];
    int nL = strlen( g_cInput ); // nL is the string length calculated in "length part", nL may exceed MOD, but it will be mod.
    int nTempLen = nL; // nTempLen is the string length calculated in "string part", the max of nTempLen is nX

    // nX cut times
    for( int i = 1; i <= nX; i++ ) {
        // length part
        nLeft = ( g_cInput[ i - 1 ] - '0' ); // nL is multiply times
        nAdd = ( ( ( nL - i ) % MOD ) * ( ( nLeft - 1 ) % MOD ) ) % MOD; // 
        nL = ( nL + nAdd ) % MOD; // nAdd, nL is mod before, so we only need to do mod one time

        if( nL < 0 ) {
            nL += MOD;
        }

        // string part
        // deal with string within nX
        if( nTempLen < nX && nLeft > 1 ) {
            nTailLen = nTempLen - i; // get tail len

            memcpy( Temp, &g_cInput[ i ], nTailLen * sizeof( char ) );
            Temp[ nTailLen ] = '\0';

            // do the copy
            for( int j = 0; j < ( nLeft - 1 ); j++ ) {
                // exceed nX
                if( nTempLen + nTailLen > nX ) {
                    memcpy( &g_cInput[ nTempLen ], Temp, ( nX - nTempLen ) * sizeof( char ) );
                    nTempLen = nX;
                    break;
                }
                // within nX
                else {
                    memcpy( &g_cInput[ nTempLen ], Temp, nTailLen * sizeof( char ) );
                    nTempLen += nTailLen;
                }
            }
        }
    }
    return nL;
}

int main( void ) {
    int nT;
    scanf( "%d", &nT );

    for( int i = 0; i < nT; i++ ) {
        int nX = 0;
        int nLength = 0;
        scanf( "%d", &nX );
        scanf( "%s", g_cInput );
        int nResult = 0;
        nResult = Do( nX );
        printf( "%d\n", nResult );
    }
    return 0;
}