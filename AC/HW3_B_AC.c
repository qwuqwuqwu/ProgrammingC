#include "stdio.h"
#include "stdlib.h"

#define MAXSIZE ( 200000 )


int main( void )
{
    int nW = 0;
    int *pnA = NULL;
    int *pnB = NULL;
    int *pnC = NULL;

    scanf( "%d", &nW );
    //pnA = malloc( sizeof( int ) * nW );
    //pnB = malloc( sizeof( int ) * nW );
    //pnC = malloc( sizeof( int ) * nW );
    int nA[ MAXSIZE ];
    int nB[ MAXSIZE ];
    int nC[ MAXSIZE ] = { 0 };

    pnA = &nA[ 0 ];
    pnB = &nB[ 0 ];
    pnC = &nC[ 0 ];

    for( int i = 0; i < nW; i++ ) {
        scanf( "%d", &pnA[ i ] );
    }
    for( int i = 0; i < nW; i++ ) {
        scanf( "%d", &pnB[ i ] );
    }

    // start calculating
    int nTemp = -1;
    int j = 0;
    int k = 0;
    int FoundInC = 0;
    for( int i = 0; i < nW; i++ ) {
        int nWanted = pnB[ i ];
        FoundInC = 0;

        if( pnC[ nWanted ] == 1 ) {
            if( i == ( nW - 1 ) ) {
                printf( "0" );
            }
            else {
                printf( "0 " );
            }
            FoundInC = 1;
        }
        // for( int l = 0; l < k; l++ ) {
        //     if( pnC[ l ] == nWanted ) {
        //         if( i == ( nW - 1 ) ) {
        //             printf( "0" );
        //         }
        //         else {
        //             printf( "0 " );
        //         }
        //         FoundInC = 1;
        //         pnC[ l ] = pnC[ k - 1 ];
        //         k--;
        //         break;
        //     }
        // }

        if( FoundInC == 0 ) {
            for( ; j < nW; j++ ) {
                if( nWanted == pnA[ j ] ) {
                    if( i == ( nW - 1 ) ) {
                        printf( "%d", ( j - nTemp ) );
                    }
                    else {
                        printf( "%d ", ( j - nTemp ) );
                    }
                    
                    nTemp = j;
                    break;
                }
                else {
                    pnC[ pnA[ j ] ] = 1;
                }
            }
        }
    }

    printf( "\n" );

    //free( pnA );
    // free( pnB );
    // free( pnC );
    return 0;
}