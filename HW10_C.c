#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define MAX_N   ( 10 )
// #define MAX_Len ( 10 )

#define MAX_N   ( 100 )
#define MAX_Len ( 999 )

char g_C[ MAX_N ][ MAX_Len + 1 ];

int compare( const void * a, const void * b )
{
    char ab[ MAX_Len + MAX_Len + 1 ];
    char ba[ MAX_Len + MAX_Len + 1 ];

    // ab
    strcpy( ab, a );
    strcat( ab, b );
    
    // ba
    strcpy( ba, b );
    strcat( ba, a );
    return ( strcmp( ba, ab ) );
}

int main( void )
{
    int nN = 0;
    while( scanf( "%d", &nN ) != EOF ) {
        for( int i = 0; i < nN; i++ ) {
            scanf( "%s", &g_C[ i ][ 0 ] );
        }

        qsort( g_C, nN, sizeof( char[ MAX_Len + 1 ] ), compare );
        for( int i = 0; i < nN; i++ ) {
            printf( "%s", g_C[ i ] );
        }
        printf( "\n" );
    }
    return 0;
}