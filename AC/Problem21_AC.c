// problem 21
// pA - Arranging a Sequence

#include <stdio.h>
#include <stdbool.h>

// method: array to store old info

//#define MAX_N   ( 20 )
//#define MAX_M   ( 10 )

#define MAX_N   ( 2000000 )
#define MAX_M   ( 1000000 )

int g_nArr[ MAX_M ]; // g_nArr[ 1 ] = 3, means 2( 0, 1 ) request pick element 3, and 3 is stored in this array temporarily.
int g_nPick[ MAX_N ]; // g_nPick[ 3 ] = 1, means element 3 is picked in the 2( 0, 1 ) request

int main( void )
{
    int nN = 0;
    int nM = 0;
    scanf( "%d%d", &nN, &nM );

    int i = 0;
    int nTemp = 0;
    // initialize
    for( i = 0; i < nN; i++ ) {
        g_nPick[ i ] = -1;
    }

    // handle request
    for( i = 0; i < nM; i++ ) {
        // check if it is picked before
        scanf( "%d", &nTemp );
        // picked before
        if( g_nPick[ nTemp - 1 ] >= 0 ) {
            g_nArr[ g_nPick[ nTemp - 1 ] ] = -1; // clear buffer
        }
        g_nArr[ i ] = nTemp;
        g_nPick[ nTemp - 1 ] = i; // record last index
    }
    i--;

    // print picked array first( picked one are moved to head )
    for( ; i >= 0; i-- ) {
        // if element is picked several times, Buffer = -1
        if( g_nArr[ i ] > 0 ) {
            printf( "%d\n", g_nArr[ i ] );
        }
    }

    for( i = 0; i < nN; i++ ) {
        // check if it is picked before
        // if element is never picked before, initial value is -1
        // if it is picked before, index is record in nPick
        if( g_nPick[ i ] > -1 ) { 
            continue;
        }
        
        // not picked before
        printf( "%d\n", i + 1 );
    }

    return 0;
}