// problem 77
// Salary thief

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
    int nL = strlen( g_cInput );
    int nTempLen = nL;
    // nX cut times
    for( int i = 1; i <= nX; i++ ) {
        // deal with length
        nLeft = ( g_cInput[ i - 1 ] - '0' );
        nAdd = ( ( ( nL - i ) % MOD ) * ( ( nLeft - 1 ) % MOD ) ) % MOD;
        nL = ( nL + nAdd ) % MOD;

        if( nL < 0 ) {
            nL += MOD;
        }

        // deal with string within nX
        if( nTempLen < nX && nLeft > 1 ) {
            nTailLen = nTempLen - i;
            //strncpy( Temp, &g_cInput[ i ], nTailLen );
            memcpy( Temp, &g_cInput[ i ], nTailLen * sizeof( char ) );
            Temp[ nTailLen ] = '\0';

            for( int j = 0; j < ( nLeft - 1 ); j++ ) {
                // memcpy( &g_cInput[ nTempLen ], Temp, nTailLen * sizeof( char ) );
                // nTempLen += nTailLen;
                // if( nTempLen >= nX ) {
                //     break;
                // }
                if( nTempLen + nTailLen > nX ) {
                    //strncpy( &g_cInput[ nTempLen ], Temp, nX - nTempLen );
                    memcpy( &g_cInput[ nTempLen ], Temp, ( nX - nTempLen ) * sizeof( char ) );
                    nTempLen = nX;
                    break;
                }
                else {
                    //strncpy( &g_cInput[ nTempLen ], Temp, nTailLen );
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