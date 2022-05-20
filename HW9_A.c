#include <stdio.h>
#include "string.h"
#include <stdbool.h>

// #define MAX ( 100 )
#define MAX ( 1000000 )

long long g_nA[ MAX ];
long long g_nTemp[ MAX ];

int BinarySearch( long long *pArr, int nStartIdx, int nEndIdx, long long nTarget )
{
    if( nEndIdx < nStartIdx ) {
        return -1;
    }
    else if( nEndIdx == nStartIdx ) {
        if( nTarget <= pArr[ nStartIdx ] ) {
            return nStartIdx;
        }
        else {
            return nStartIdx + 1;
        }
    }

    int nMidIdx = nStartIdx + ( ( nEndIdx - nStartIdx ) / 2 );
    if( nTarget < pArr[ nMidIdx ] ) {
        int nTemp = BinarySearch( pArr, nStartIdx, nMidIdx - 1, nTarget );
        if( nTemp == -1 ) {
            return nMidIdx;
        }
        else {
            return nTemp;
        }
    }
    else if( nTarget > pArr[ nMidIdx ] ){
        int nTemp = BinarySearch( pArr, nMidIdx + 1, nEndIdx, nTarget );
        if( nTemp == -1 ) {
            return nMidIdx + 1;
        }
        else {
            return nTemp;
        }
    }
    else {
        return nMidIdx;
    }
}

int main( void )
{
    int nN = 0;
    int nK = 0;
    int nQ = 0;
    
    scanf( "%d%d%d", &nN, &nK, &nQ );
    for( int i = 0; i < nN; i++ ) {
        scanf( "%lld", &g_nA[ i ] );
    }

    // swap k number
    memcpy( g_nTemp, g_nA, sizeof( long long ) * nK );
    memcpy( g_nA, &g_nA[ nK ], sizeof( long long ) * ( nN - nK ) );
    memcpy( &g_nA[ nN - nK ], g_nTemp, sizeof( long long ) * nK );

    // 
    for( int i = 0; i < nQ; i++ ) {
        long long nF = 0;
        scanf( "%lld", &nF );
        bool bA = true;
        bool bB = true;
        // search in first segment
        int a = BinarySearch( g_nA, 0, ( nN - nK - 1 ), nF );

        if( a < 0 || a > ( nN - nK - 1 ) ) {
            bA = false;
        }

        // search in second segment
        int b = BinarySearch( g_nA, nN - nK, nN - 1, nF );

        if( b < ( nN - nK ) || b > ( nN - 1 ) ) {
            bB = false;
        }
        
        if( bA && bB ) {
            if( g_nA[ a ] == g_nA[ b ] ) {
                if( b < a ) {
                    printf( "%d\n", b + 1 );
                }
                else {
                    printf( "%d\n", a + 1 );
                }
            }
            else if( g_nA[ a ] - nF < g_nA[ b ] - nF ) {
                printf( "%d\n", a + 1 );
            }
            else {
                printf( "%d\n", b + 1 );
            }
        }
        else if( bA && !bB ) {
            printf( "%d\n", a + 1 );
        }
        else if( !bA && bB ) {
            printf( "%d\n", b + 1 );
        }
        else {
            printf( "gan ni nya sai bau\n" );
        }
    }

    return 0;
}