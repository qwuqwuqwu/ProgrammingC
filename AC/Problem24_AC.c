// problem 24
//pD - Distrait

#include <stdio.h>
#include <stdbool.h>

bool g_bPicked[ 5 ][ 5 ];
int g_nMatrix[ 5 ][ 5 ];

void PickANumber( const int p )
{
    for( int i = 0; i < 5; i++ ) {
        for( int j = 0; j < 5; j++ ) {
            if( g_nMatrix[ i ][ j ] == p ) {
                g_bPicked[ i ][ j ] = true;
                return;
            }
        }
    }
}

bool isBingo( void )
{
    // row bingo
    for( int i = 0; i < 5; i++ ) {
        if( g_bPicked[ i ][ 0 ] &&
            g_bPicked[ i ][ 1 ] &&
            g_bPicked[ i ][ 2 ] &&
            g_bPicked[ i ][ 3 ] &&
            g_bPicked[ i ][ 4 ] ) {
                return true;
            }
    }
    // column bingo
    for( int i = 0; i < 5; i++ ) {
        if( g_bPicked[ 0 ][ i ] &&
            g_bPicked[ 1 ][ i ] &&
            g_bPicked[ 2 ][ i ] &&
            g_bPicked[ 3 ][ i ] &&
            g_bPicked[ 4 ][ i ] ) {
                return true;
            }
    }
    
    // incline bingo
    if( g_bPicked[ 0 ][ 0 ] &&
        g_bPicked[ 1 ][ 1 ] &&
        g_bPicked[ 2 ][ 2 ] &&
        g_bPicked[ 3 ][ 3 ] &&
        g_bPicked[ 4 ][ 4 ] ) {
            return true;
        }
    if( g_bPicked[ 0 ][ 4 ] &&
        g_bPicked[ 1 ][ 3 ] &&
        g_bPicked[ 2 ][ 2 ] &&
        g_bPicked[ 3 ][ 1 ] &&
        g_bPicked[ 4 ][ 0 ] ) {
            return true;
        }
    return false;
}

void initPickMatrix( void )
{
    for( int i = 0; i < 5; i++ ) {
        for( int j = 0; j < 5; j++ ) {
            g_bPicked[ i ][ j ] = false;
        }
    }
}

int main( void )
{
    // get matrix
    for( int i = 0; i < 5; i++ ) {
        for( int j = 0; j < 5; j++ ) {
            scanf( "%d", &g_nMatrix[ i ][ j ] );
        }
    }

    int nT = 0;
    scanf( "%d", &nT );
    for( int i = 0; i < nT; i++ ) {
        // each test case
        // pick number
        int nN = 0;
        scanf( "%d", &nN );
        bool bBingo = false;
        initPickMatrix();
        for( int j = 0; j < nN; j++ ) {
            // decide position
            int nP = 0;
            scanf( "%d", &nP );
            PickANumber( nP );
            if( bBingo == false && j >= 4 ) { // remember not to printf again if already bingo
                if( isBingo() ) {
                    bBingo = true;
                    printf( "Case #%d: %d\n", i + 1, j + 1 );
                }
            }
        }
        if( bBingo == false ) {
            printf( "Case #%d: Not yet \\(^o^)\/\n", i + 1 );
        }
    }
    return 0;
}