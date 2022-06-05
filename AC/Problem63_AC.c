// Problem 63
// pC - Ponds
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX ( 1000 )

int g_nRow = 0;
int g_nCol = 0;

int visited[ MAX ][ MAX ];
bool g_bPond[ MAX ][ MAX ];

int g_nCount = 0;
int g_nGroupCount = 0;

int connect( int nowRow, int nowCol, int testRow, int testCol )
{
    // if neighbor is not a pond, no need to check
    if( g_bPond[ testRow ][ testCol ] == false ) {
        return 0;
    }

    // check
    //      ^
    //      |
    // <---now--->
    //      |
    //      v
    if( nowRow == testRow ) {
        if( ( ( nowCol - 1 ) <= testCol ) 
        && ( ( nowCol + 1 ) >= testCol ) 
        ) {
            return 1;
        }
    }
    else if( nowCol == testCol ) {
        if( ( ( nowRow - 1 ) <= testRow ) 
        && ( ( nowRow + 1 ) >= testRow ) 
        ) {
            return 1;
        }
    }

    return 0;
}

void dfs( int nowRow, int nowCol )
{
    if( visited[ nowRow ][ nowCol ] == 1 ) return;

    visited[ nowRow ][ nowCol ] = 1;
    // if now is pond, dfs neighborhood
    if( g_bPond[ nowRow ][ nowCol ] == true ) {
        g_nCount++;

        // only dfs the neighborhood
        for( int i = nowRow - 1; i <= nowRow + 1; i++ ) {
            for( int j = nowCol - 1; j <= nowCol + 1; j++ ) {
                if( i == nowRow && j == nowCol ) continue;
                if( i < 0 || i >= g_nRow ) continue; // clamp idx
                if( j < 0 || j >= g_nCol ) continue; // clamp idx
                if( visited[ i ][ j ] == 1 ) continue; // if neighborhoood is visited, do not check again

                if( connect( nowRow, nowCol, i, j ) == 1 ) {
                    dfs( i, j );
                }
            }
        }
    }
}

int main( void )
{
    g_nGroupCount = 0;
    scanf( "%d%d\n", &g_nRow, &g_nCol );

    for( int i = 0; i < g_nRow; i++ ) {
        for( int j = 0; j < g_nCol; j++ ) {
            char cTemp;
            scanf( "%c", &cTemp );
            if( cTemp == '~' ) {
                g_bPond[ i ][ j ] = true;
            }
            else {
                g_bPond[ i ][ j ] = false;
            }
        }
        scanf( "\n" );
    }

    // int group = 0;
    // int alone = 0;
    for( int i = 0; i < g_nRow; i++ ) {
        for( int j = 0; j < g_nCol; j++ ) {
            g_nCount = 0;
            dfs( i, j );

            if( g_nCount == 1 ) {
                // do nothing
                g_nGroupCount++;
            }
            else if( g_nCount > 1 ) {
                g_nGroupCount++;
            }
            // g_nCount == 0
            else {
                // do nothing
            }
        }
    }

    printf( "%d\n", g_nGroupCount );
    
    return 0;
}