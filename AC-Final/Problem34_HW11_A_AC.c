// Problem 34
// Ugandan Knuckles's code
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char g_c[ 1000 ][ 1001 ];

int comp( const void* lhs, const void* rhs )
{
    char *LHS = ( char * )lhs;
    char *RHS = ( char * )rhs;
    size_t nLLen = strlen( LHS );
    size_t nRLen = strlen( RHS );
    if( nLLen > nRLen ) {
        return 1;
    }
    else if( nLLen == nRLen ) {
        return 0;
    }
    else {
        return -1;
    }
}

int main( void )
{
    int nN = 0;
    scanf( "%d", &nN );
    for( int i = 0; i < nN; i++ ) {
        scanf( "%s", &g_c[ i ] );
    }

    // sort
    qsort( g_c, nN, sizeof( char ) * 1001, comp );

    // check substring
    bool bNo = false;
    for( int i = 0; i <= nN - 2; i++ ) {
        for( int j = i + 1; j <= nN - 1; j++ ) {
            if( strstr( g_c[ j ], g_c[ i ] ) == NULL ) {
                bNo = true;
                break;
            }
        }

        if( bNo == true ) {
            break;
        }
    }

    if( bNo == true ) {
        printf( "NO\n" );
    }
    else {
        printf( "YES\n" );
        for( int i = 0; i < nN; i++ ) {
            printf( "%s\n", g_c[ i ] );
        }
    }
    return 0;
}