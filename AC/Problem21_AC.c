// problem 21
// pA - Arranging a Sequence

#include <stdio.h>
#include <stdbool.h>

//#define MAX_N   ( 20 )
//#define MAX_M   ( 10 )

#define MAX_N   ( 2000000 )
#define MAX_M   ( 1000000 )

int g_nArr[ MAX_M ];
int g_nPick[ MAX_N ];

int main( void )
{
    int nN = 0;
    int nM = 0;
    scanf( "%d%d", &nN, &nM );

    int i = 0;
    int nTemp = 0;
    for( i = 0; i < nN; i++ ) {
        g_nPick[ i ] = -1;
    }
    for( i = 0; i < nM; i++ ) {
        // check if it is picked before
        scanf( "%d", &nTemp );
        // picked before
        if( g_nPick[ nTemp - 1 ] >= 0 ) {
            g_nArr[ g_nPick[ nTemp - 1 ] ] = -1; // clear buffer
        }
        g_nArr[ i ] = nTemp;
        g_nPick[ g_nArr[ i ] - 1 ] = i; // record last index
    }
    i--;
    for( ; i >= 0; i-- ) {
        // if element is pickec several times, Buffer = -1
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