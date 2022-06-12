// Problem 9
// Nyan Cat Crisis
#include <stdio.h>
#include <string.h>

#define MAX ( 1000 )

int visited[ MAX ];
int g_group[ MAX ];
int g_nN = 0;
int g_nR = 0;

int x[ MAX ];
int y[ MAX ];
int g_nCount = 0;
int g_nGroupCount = 0;

int connect( int a, int b )
{
    // todo distance
    // do not use sqrt, because floating point may exist error
    if( ( ( x[ a ] - x[ b ] ) * ( x[ a ] - x[ b ] ) + ( y[ a ] - y[ b ] ) * ( y[ a ] - y[ b ] ) ) <= ( g_nR * g_nR ) ) {
        return 1;
    }

    return 0;
}

void dfs( int now )
// recursive dfs
{
    if( visited[ now ] == 1 ) return;

    // visit now
    visited[ now ] = 1;
    g_nCount++;
    
    // next level
    for( int i = 0; i < g_nN; i++ ) {
        
        if( i == now ) continue; // pass same node
        if( visited[ i ] == 1 ) continue; // pass visited node

        // check unvisited node
        if( connect( now, i ) == 1 ) {
            dfs( i );
        }
    }
}

int main( void )
{
    int nT = 0;
    scanf( "%d", &nT );

    int nK = 0;
    for( int j = 0; j < nT; j++ ) {
        // initialize global variable for different test cases
        g_nGroupCount = 0;
        memset( visited, 0, sizeof( int ) * MAX );

        scanf( "%d%d%d", &g_nN, &g_nR, &nK );

        for( int i = 0; i < g_nN; i++ ) {
            scanf( "%d%d", &x[ i ], &y[ i ] );
        }

        // int group = 0;
        // int alone = 0;
        // dfs all nodes
        for( int i = 0; i < g_nN; i++ ) {
            g_nCount = 0; // nodes count in this group
            dfs( i );

            if( g_nCount == 1 ) {
                g_group[ g_nGroupCount++ ] = 1;
            }
            else if( g_nCount > 1 ) {
                g_group[ g_nGroupCount++ ] = g_nCount;
            }
            // g_nCount == 0
            else {
                // do nothing
            }
        }

        // count each gorup's size
        int nSmaller = 0;
        for( int i = 0; i < g_nGroupCount; i++ ) {
            if( g_group[ i ] < nK ) {
                nSmaller++;
            }
        }
        // print samller grounp count, larger group count
        printf( "%d %d\n", nSmaller, ( g_nGroupCount - nSmaller ) );
    }
    
    return 0;
}