// Problem 49
// Cat-Toast Crisis
#include <stdio.h>

#define MAX ( 1000 )

int visited[ MAX ];
int g_nN = 0;
int g_nR = 0;

int x[ MAX ];
int y[ MAX ];
int g_nCount = 0;

int connect( int a, int b )
{
    // todo distance
    // do not use sqrt
    // because floating point will produce error
    if( ( ( x[ a ] - x[ b ] ) * ( x[ a ] - x[ b ] ) + ( y[ a ] - y[ b ] ) * ( y[ a ] - y[ b ] ) ) <= ( g_nR * g_nR ) ) {
        return 1;
    }

    return 0;
}

void dfs( int now )
// recursive dfs
{
    // pass the visited node
    if( visited[ now ] == 1 ) return;

    // visit now
    visited[ now ] = 1;
    g_nCount++;

    for( int i = 0; i < g_nN; i++ ) {
        
        if( i == now ) continue; // pass the same node
        if( visited[ i ] == 1 ) continue; // pass visited node

        // check unvisited note
        if( connect( now, i ) == 1 ) {
            dfs( i );
        }
    }
}

int main( void )
{
    scanf( "%d%d", &g_nN, &g_nR );

    for( int i = 0; i < g_nN; i++ ) {
        scanf( "%d%d", &x[ i ], &y[ i ] );
    }

    int group = 0;
    int alone = 0;

    for( int i = 0; i < g_nN; i++ ) {
        g_nCount = 0;
        dfs( i );
        if( g_nCount == 1 ) {
            alone++;
        } 
        else if( g_nCount != 0 ) {
            group++;
        }
    }
    printf( "%d %d\n", alone, group );
    return 0;
}