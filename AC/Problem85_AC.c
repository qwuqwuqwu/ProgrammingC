// Problem 85
// XOR
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

// #define MAX ( 10 )
#define MAX ( 100000 )

unsigned int g_nA[ MAX ];
int g_nN;
int g_nBitCount[ 32 ];

int main( void )
{
    scanf( "%d", &g_nN );

    for( int i = 0; i < g_nN; i++ ) {
        scanf( "%u", &g_nA[ i ] );
        for( int j = 0; j < 32; j++ ) {
            if( ( 1 << j ) & g_nA[ i ] ) {
                g_nBitCount[ j ]++;
            }
        }
    }

    unsigned int nTest = 0;
    for( int i = 0; i < 32; i++ ) {
        if( g_nBitCount[ i ] >= ( g_nN / 2 ) ) {
            nTest += ( 1 << i );
        }
    }

    long long ans = 0;
    for( int i = 0; i < g_nN; i++ ) {
        ans += ( long long )( g_nA[ i ] ^ nTest );
    }
    printf( "%lld\n", ans );

    return 0;
}