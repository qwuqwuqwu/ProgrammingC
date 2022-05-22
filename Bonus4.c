#include <stdio.h>
#include <stdbool.h>
#define MAX ( 9 )

int g_nN = 0; // for queens
int g_nM = 0; // for castle
int g_nTotal = 0;

int g_QueensArray[ MAX + 1 ] = { 0 };
int g_CastleArray[ MAX + 1 ] = { 0 };

int g_nCount = 0;

bool checkQueens( int nRow, int nCol )
{
    if( g_nN <= 0 ) {
        return false;
    }

    // check queens
    for( int row = nRow - 1; row >= 1; row-- ) {
        if( g_QueensArray[ row ] == 0 ) {
            continue;
        }
        if( g_QueensArray[ row ] == nCol ) {
            return false;
        }
        if( ( nCol - g_QueensArray[ row ] ) == ( nRow - row ) ) {
            return false;
        }
        if( ( nCol - g_QueensArray[ row ] ) == -( nRow - row ) ) {
            return false;
        }
    }

    // check castles
    for( int row = nRow - 1; row >= 1; row-- ) {
        if( g_CastleArray[ row ] == 0 ) {
            continue;
        }
        if( g_CastleArray[ row ] == nCol ) {
            return false;
        }
        if( ( nCol - g_CastleArray[ row ] ) == ( nRow - row ) ) {
            return false;
        }
        if( ( nCol - g_CastleArray[ row ] ) == -( nRow - row ) ) {
            return false;
        }
    }

    return true;
}

bool checkCastles( int nRow, int nCol )
{
    if( g_nM <= 0 ) {
        return false;
    }
    // check queens
    for( int row = nRow - 1; row >= 1; row-- ) {
        if( g_QueensArray[ row ] == 0 ) {
            continue;
        }
        if( g_QueensArray[ row ] == nCol ) {
            return false;
        }
        if( ( nCol - g_QueensArray[ row ] ) == ( nRow - row ) ) {
            return false;
        }
        if( ( nCol - g_QueensArray[ row ] ) == -( nRow - row ) ) {
            return false;
        }
    }

    // check castles
    for( int row = nRow - 1; row >= 1; row-- ) {
        if( g_CastleArray[ row ] == 0 ) {
            continue;
        }
        if( g_CastleArray[ row ] == nCol ) {
            return false;
        }
    }

    return true;
}

void set( int nRow )
{
    // printf( "%d ", nRow );
    // if( nRow == 8 ) {
    //     printf( "\n" );
    // }
    if( nRow == ( g_nTotal + 1 ) ) {
        g_nCount++;
        return;
    }

    for( int i = 1; i <= g_nTotal; i++ ) {
        
        if( checkQueens( nRow, i ) == true ) {
            g_QueensArray[ nRow ] = i;
            g_nN--;
            set( nRow + 1 );
            g_nN++;
            g_QueensArray[ nRow ] = 0; // need to clear here, becuase in next if(), nRow index will be checked
        }

        if( checkCastles( nRow, i ) == true ) {
            g_CastleArray[ nRow ] = i;
            g_nM--;
            set( nRow + 1 );
            g_nM++;
            g_CastleArray[ nRow ] = 0;
        }
    }
}

int main( void )
{
    scanf( "%d%d", &g_nN, &g_nM );
    // nN for queens
    // nM for castles

    g_nTotal = g_nN + g_nM;
    
    set( 1 );
    printf( "%d\n", g_nCount );

    return 0;
}