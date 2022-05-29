// Problem 85
// XOR
#include <stdio.h>
#include <limits.h>

// #define MAX ( 10 )
#define MAX ( 100000 )

unsigned int g_nA[ MAX ];
int g_nN;

void calc( void )
{
    unsigned long long result = ULLONG_MAX;

    for( int j = 1; j < g_nN; j++ ) {

        unsigned long long temp = 0;
        for( int i = 0; i < g_nN; i++ ) {
            temp += g_nA[ j ] ^ g_nA[ i ];
        }
        if( temp < result ) {
            result = temp;
        }
    }

    printf( "%llu\n", result );
}

int main( void )
{
    scanf( "%d", &g_nN );

    if( g_nN == 1 ) {
        printf( "0\n" );
        return 0;
    }

    for( int i = 0; i < g_nN; i++ ) {
        scanf( "%d", &g_nA[ i ] );
    }

    calc();
    return 0;
}