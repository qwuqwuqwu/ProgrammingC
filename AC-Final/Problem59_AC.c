// Problem 59
// Flattening the Tree
#include <stdio.h>
#include <stdlib.h>
#define MAX_COUNT   ( 1025 )

int g_nN;
int *g_pBST;

void visit( const int nID ) {
    // check nID first
    if( nID > g_nN ) {
        return;
    }

    // visit left child
    visit( 2 * nID );

    // print myself
    if( nID == g_nN ) {
        printf( "%d\n", g_pBST[ nID ] );
    }
    else {
        printf( "%d ", g_pBST[ nID ] );
    }

    // visit right child
    visit( 2 * nID + 1 );
}

int main( void )
{
    scanf( "%d", &g_nN );
    g_pBST = ( int* )( malloc( sizeof( int ) * ( g_nN + 1 ) ) );
    for( int i = 1; i <= g_nN; i++ ) {
        scanf( "%d", &g_pBST[ i ] );
    }

    // flatten
    visit( 1 );

    free( g_pBST );
    return 0;
}