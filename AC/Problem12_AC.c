#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int g_nN;
int g_nQ;
long long *g_pnTrash;
long long *g_pllSum;

// Tired janitor

void HandleInput( void )
{
    // n q part
    scanf( "%d %d", &g_nN, &g_nQ );

    // new Trash
    g_pnTrash = malloc( sizeof( long long ) * ( g_nN + 1 ) );
    g_pllSum = malloc( sizeof( long long ) * ( g_nN + 1 ) );

    // trash part
    char string[ 256 ];
    for( int i = 1; i <= g_nN; i++ ) {
        scanf( "%s", string ); //5(/`A`)/ 
        size_t Length =  strlen( string );

        for( size_t j = 0; j < Length; j++ ) {
            if( string[ j ] == '(' ) {
                string[ j ] = '\0';
                break;
            }
        }

        g_pnTrash[ i ] = atoll( string );
        scanf( "%s", string ); //~I__I
    }

    // sum all
    g_pllSum[ 0 ] = 0;
    g_pllSum[ 1 ] = g_pnTrash[ 1 ];
    for( int i = 1; i < g_nN; i++ ) {
        g_pllSum[ i + 1 ] = g_pllSum[ i ] + g_pnTrash[ i + 1 ];
    }

    // al ar part
    int al = 0;
    int ar = 0;
    long long llAnswer = 0;
    for( int j = 0; j < g_nQ; j++ ) {
        llAnswer = 0;
        scanf( "%d%d", &al, &ar );
        llAnswer = g_pllSum[ ar ] - g_pllSum[ al - 1 ];
        printf( "%lld\n", llAnswer );
    }
}

int main( void )
{
    HandleInput();
    free( g_pnTrash );
    free( g_pllSum );
    return 0;
}