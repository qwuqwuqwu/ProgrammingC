// Problem 84
// F - Bipartite Graph
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX ( 1001 )

typedef enum _EColor {
    EC_Red = 0,
    EC_Black = 1,
    EC_Num = 2
} EColor;

int visited[ MAX ];
int g_group[ MAX ];
int g_nN = 0;
int g_nM = 0;

int x[ MAX ];
int y[ MAX ];
int g_nCount = 0;
int g_nGroupCount = 0;

bool g_bAdjMat[ MAX ][ MAX ];
int g_nAdjEdgesCount[ MAX ];
EColor g_Color[ MAX ];

int connect( int a, int b )
{
    if( g_bAdjMat[ a ][ b ] == true ) {
        return 1;
    }
    return 0;
}

bool dfs( int now, EColor color )
{
    if( visited[ now ] == 1 ) {
        if( g_Color[ now ] != color ) {
            return false;
        }
    }

    visited[ now ] = 1;
    g_Color[ now ] = color;
    g_nCount++;
    color = ( color + 1 ) % EC_Num;
    for( int i = 1; i <= g_nN; i++ ) {
        
        if( i == now ) continue;

        if( connect( now, i ) == 1 ) {
            if( visited[ i ] == 1 ) {
                if( g_Color[ i ] != color ) {
                    return false;
                }
                else {
                    continue;
                }
            }

            // dfs i
            if( dfs( i, color ) == false ) {
                return false;
            }
        }
    }
    return true;
}

int main( void )
{
    int nT = 0;
    scanf( "%d", &nT );

    int nK = 0;
    for( int j = 0; j < nT; j++ ) {
        g_nGroupCount = 0;
        memset( visited, 0, sizeof( int ) * MAX );
        memset( g_bAdjMat, 0, sizeof( bool ) * MAX * MAX );
        memset( g_Color, 0, sizeof( EColor ) * MAX );

        scanf( "\n" );
        scanf( "%d%d", &g_nN, &g_nM );


        // scan edges
        for( int i = 0; i < g_nM; i++ ) {
            int a, b;
            scanf( "%d%d", &a, &b );
            g_bAdjMat[ a ][ b ] = true;
            g_bAdjMat[ b ][ a ] = true;
        }

        // it is a connected graph
        bool bResult = false;
        bResult = dfs( 1, EC_Red );
        if( bResult == true ) {
            printf( "Yes\n" );
        }
        else {
            printf( "No\n" );
        }
    }
    
    return 0;
}