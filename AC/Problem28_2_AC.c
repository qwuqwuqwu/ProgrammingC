// problem 28
// johny johny
// METHOD: count i + not count i

// get total counts of a_i sum equals k

// note that original method needs to create 2d table g_pTable[ nN ][ nK ]
// but this method will exceed memory limit of OJ system
// so I just use brute force method to count whether pick i or not repeatedly

#include <stdio.h>
#include <stdlib.h>

int *g_pnA = NULL;
int find( const int nN, const int nK )
{
    if( nK < 0 ) {
        return 0;
    }
    else if( nK == 0 ) {
        // g_pTable[ nN ][ nK ] = 0;
        return 0;
    }

    // if( g_pTable[ nN ][ nK ] != -1 ) {
    //     return g_pTable[ nN ][ nK ];
    // }

    if( nN == 1 ) {
        if( g_pnA[ nN ] == nK ) {
            return 1;
            // g_pTable[ nN ][ nK ] = 1;
        }
        else {
            return 0;
            // g_pTable[ nN ][ nK ] = 0;
        }
        // return g_pTable[ nN ][ nK ];
    }
    // nN > 1
    else {
        // pick nN
        int nA = 0;
        if( g_pnA[ nN ] == nK ) {
            nA = 1; // pick nN
        }
        else {
            nA = find( nN - 1, nK - g_pnA[ nN ] ); // pick nN and others
        }

        // do not pick nN
        int nB = find( nN - 1, nK );

        return nA + nB;
        // g_pTable[ nN ][ nK ] = nA + nB;
        // return g_pTable[ nN ][ nK ];
    }
}

int Algorithm_BruteFroce( const int nN, const int nK )
{
    return find( nN, nK );
}

int main( void ) {
    int nN;
    int nK;
    
    scanf( "%d%d", &nN, &nK );

    g_pnA = malloc( sizeof( int ) * ( nN + 1 ) );
    // g_pTable = malloc( sizeof( int * ) * ( nN + 1 ) );
    // for( int i = 0; i <= nN; i++ ) {
    //     g_pTable[ i ] = malloc( sizeof( int ) * ( nK + 1 ) );
    //     for( int j = 0; j <= nK; j++ ) {
    //         g_pTable[ i ][ j ] = -1;
    //     }
    // }

    for( int i = 1; i <= nN; i++ ) {
        scanf( "%d", &g_pnA[ i ] );
    }

    int nResult = Algorithm_BruteFroce( nN, nK );
   
    printf( "%d\n", nResult );

    free( g_pnA );
    // for( int i = 0; i <= nN; i++ ) {
    //     free( g_pTable[ i ] );
    // }
    // free( g_pTable );
    return 0;
}