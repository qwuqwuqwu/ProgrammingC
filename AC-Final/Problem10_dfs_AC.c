// Problem 10
// knuckle's name
#include <stdio.h>
#include <string.h>

#define MAX ( 2000 )

// #define MAX ( 10 )

int visited[ MAX ];
int g_nN = 0;

int g_nCount = 0;

int g_arr[ MAX ][ 26 ]; // 26 english letters

int connect( int a, int b )
{
    //
    for( int i = 0; i < 26; i++ ) {
        if( g_arr[ a ][ i ] != 0 && g_arr[ b ][ i ] != 0 ) {
            return 1;
        }
    }

    return 0;
}

void dfs( int now )
// recursive dfs
{
    // pass visited
    if( visited[ now ] == 1 ) return;

    // visit now
    visited[ now ] = 1;
    g_nCount++;

    for( int i = 0; i < g_nN; i++ ) {
        
        if( i == now ) continue; // pass same node
        if( visited[ i ] == 1 ) continue; // pass visited node

        // check unlimited node
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
        memset( visited, 0, sizeof( int ) * MAX );
        // remember to clean global variable!
        for( int i = 0; i < g_nN; i++ ) {
            memset( g_arr[ i ], 0, sizeof( int ) * 26 );
        }

        scanf( "%d", &g_nN );
        
        for( int i = 0; i < g_nN; i++ ) {
            char str[ 1001 ];
            scanf( "%s", str );
            for( char *ptr = str; *ptr; ptr++ ) {
                g_arr[ i ][ *ptr - 'a' ]++;
            }
        }

        int group = 0;
        // int alone = 0;
        for( int i = 0; i < g_nN; i++ ) {
            g_nCount = 0;
            dfs( i );

            if( g_nCount == 1 ) {
                group++;
            }
            else if( g_nCount > 1 ) {
                group++;
            }
            // g_nCount == 0
            else {
                // do nothing
            }
        }

        printf( "%d\n", group );
    }
    
    return 0;
}