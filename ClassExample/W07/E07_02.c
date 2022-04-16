// three castle problem

#include <stdio.h>
#include "stdbool.h"

#define MAX_ROW     ( 10 )
int g_nLegalCount = 0;
int g_nPos[ MAX_ROW + 1 ];

void show( void )
{
    printf( "===============\n" );
    for( int i = 1; i <= 3; i++ ) {
        printf( "%d ", g_nPos[ i ] );
    }
    printf( "\n" );
}

bool isValid( int nRow, int nCol )
{
    for( int i = nRow; i >= 1; i-- ) {
        if( g_nPos[ i ] == nCol ) {
            return false;
        }
    }
    return true;
}

void calc( int nRow )
{
    if( nRow == 4 ) {
        g_nLegalCount++;
        show();
    }
    else {
        for( int nCol = 1; nCol <= 3; nCol++ ) {
            if( isValid( nRow, nCol ) == true ) {
                // place this row and nCol
                g_nPos[ nRow ] = nCol;
                
                // check next row
                calc( nRow + 1 );
                
                // delte this pos
                g_nPos[ nRow ] = 0;
            }    
        }
    }
}


int main( void )
{
    calc( 1 );
    printf( "Total legal case count is %d", g_nLegalCount );
    return 0;
}
