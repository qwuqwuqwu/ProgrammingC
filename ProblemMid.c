#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_COUNTOF_TARGET ( 10 )
#define MAX_LENOF_TARGET    ( 26 )
#define MAX_LENOF_PUZZLE    ( 100 )

int g_nTargetCount;

int g_nPuzzleCount;
int g_nTarget[ MAX_COUNTOF_TARGET ][ 26 ];
int g_nPuzzle[ 26 ];
int g_nScore[ 26 ];
int g_nMaxScore = 0;
bool g_bPick[ MAX_COUNTOF_TARGET ];

void recursive( int nNowScore, int nRemainPuzzleCount, int nPuzzle[ 26 ], int nCurTarget, int nTargetCount )
{
    // check still has puzzle
    if( nRemainPuzzleCount < 0 ) {
        return;
    }
    if( nCurTarget == nTargetCount ) {
        if( nNowScore > g_nMaxScore ) {
            g_nMaxScore = nNowScore;
        }
        return;
    }

    // recursive part
    // choose or not to choose current target
    // choose
    int nTempPuzzle[ 26 ];
    int nTempRemainPuzzleCount = nRemainPuzzleCount;
    int nTempNowScore = nNowScore;
    memcpy( nTempPuzzle, nPuzzle, sizeof( int ) * 26 );
    bool bSuccess = true;

    for( int i = 0; i < 26; i++ ) {
        if( nTempPuzzle[ i ] < g_nTarget[ nCurTarget ][ i ] ) {
            bSuccess = false;
            break;
        }
    }

    if( bSuccess == true ) {
        // pick
        g_bPick[ nCurTarget ] = true;
        for( int i = 0; i < 26; i++ ) {
            nTempPuzzle[ i ] -= g_nTarget[ nCurTarget ][ i ];
            nTempRemainPuzzleCount -= g_nTarget[ nCurTarget ][ i ];
            nTempNowScore += g_nScore[ i ] * g_nTarget[ nCurTarget ][ i ];
        }

        // next recursive
        recursive( nTempNowScore, nTempRemainPuzzleCount, nTempPuzzle, nCurTarget + 1, nTargetCount );
        g_bPick[ nCurTarget ] = false;
    }

    // not to pick current target
    recursive( nNowScore, nRemainPuzzleCount, nPuzzle, nCurTarget + 1, nTargetCount );
}

void helper( void )
{
    recursive( 0, g_nPuzzleCount, g_nPuzzle, 0, g_nTargetCount );
    printf( "%d\n", g_nMaxScore );
}

int main( void ) 
{
    while( scanf( "%d%d", &g_nTargetCount, &g_nPuzzleCount ) != EOF ) {
        memset( g_nTarget, 0, sizeof( int ) * MAX_COUNTOF_TARGET * 26 );
        memset( g_nPuzzle, 0, sizeof( int ) * 26 );
        memset( g_bPick, 0, sizeof( bool ) * MAX_COUNTOF_TARGET );
        g_nMaxScore = 0;

        for( int i = 0; i < g_nTargetCount; i++ ) {
            char c[MAX_LENOF_TARGET ];
            int nLen = 0;
            scanf( "%s", c );
            nLen = strlen( c );
            for( int j = 0; j < nLen; j++ ) {
                g_nTarget[ i ][ c[ j ] - 'a' ]++;
            }
        }
        char c[ MAX_LENOF_PUZZLE ];
        scanf( "%s", c );
        int nLen = strlen( c );
        for( int j = 0; j < nLen; j++ ) {
            g_nPuzzle[ c[ j ] - 'a' ]++;
        }

        for( int i = 0; i < 26; i++ ) {
            scanf( "%d", &g_nScore[ i ] );
        }

        helper();
    }
    return 0;
}