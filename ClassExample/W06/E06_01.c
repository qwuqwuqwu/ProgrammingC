// tower of honoi

#include <stdio.h>

int g_nMoves = 0;

void Move( int nLevel, char cFrom, char cTo, char cBuffer )
{
    if( nLevel <= 1 ) {
        g_nMoves++;
        return;
    }
    else {
        // move nLevel - 1 to buffer
        printf( "Move Level-1 to buffer %c, ", cBuffer );
        Move( nLevel - 1, cFrom, cBuffer, cTo );
        
        // move nLevel to target
        printf( "Move base to target %c, ", cTo );
        g_nMoves++;
        
        // move buffer to target
        printf( "Move level - 1 to target %c, ", cTo );
        Move( nLevel - 1, cBuffer, cTo, cFrom );
        
        printf("nLevel: %d, cFrom: %c, cTo: %c, cBuffer: %c\n", nLevel, cFrom, cTo, cBuffer );
    }
}

int main( void )
{
    // level of honoi tower
    int nMaxLevel = 0;
    scanf( "%d", &nMaxLevel );
    
    Move( nMaxLevel, 'a', 'b', 'c' );
    
    printf( "Total moves count is %d\n", g_nMoves );
    return 0;
}

