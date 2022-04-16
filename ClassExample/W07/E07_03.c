// Four queens
// ^ ^ ^
//  \|/
// <-Q->
//  /|\
// v v v

#include <stdio.h>
#include "stdbool.h"

#define MAX_SIZE    ( 10 )

int g_nPos[ MAX_SIZE + 1 ];
int g_nLegalCount = 0;

void show( int nSize )
{
    for( int i = 1; i <= nSize; i++ ) {
        for( int j = 1; j <= nSize; j++ ) {
            if( g_nPos[ i ] == j ) {
                printf( "Q" );
            }
            else {
                printf( "_" );
            }
        }
        printf("\n");
    }
    printf("=======\n");
}

bool isValid( int nSize, int nRow, int nCol )
{
    for( int j = nRow - 1; j >= 1; j-- ) {
        // same col
        if( g_nPos[ j ] == nCol ) {
            return false;
        }
        
        // 
        if( nCol - g_nPos[ j ] == nRow - j  ) {
            return false;
        }
        
        if( nCol - g_nPos[ j ] == -( nRow - j )  ) {
            return false;
        }
    }
    return true;
}

void calc( int nSize, int nRow )
{
    if( nRow == nSize + 1 ) {
        g_nLegalCount++;
        show( nSize );
        return;
    }
    else {
        for( int nCol = 1; nCol <= nSize; nCol++ ) {
            // check valid
            if( isValid( nSize, nRow, nCol ) == true ) {
                // place this queens
                g_nPos[ nRow ] = nCol;
                
                calc( nSize, nRow + 1 );
                
                // pick up this queens
                g_nPos[ nRow ] = 0;
            }
        }
    }
}

int main( void )
{
    int nSize = 0;
    scanf( "%d", &nSize );
    calc( nSize, 1 );
    printf( "Total legal count = %d\n", g_nLegalCount );
    return 0;
}
