// Yes papa
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAXLEN  ( 10001 )

bool Algorithm( const char lhs[], const char rhs[] )
{
    // check string size
    int nLenlhs = strlen( lhs );
    int nLnerhs = strlen( rhs );
    if( nLenlhs != nLnerhs ) {
        return false;
    }

    if( ( nLenlhs % 2 ) == 1 ) { // % 2 for odd len
        if( strcmp( lhs, rhs ) == 0 ) {
            return true;
        }
        else {
            return false;
        }
    }

    // divid to sub string
    int nLenChild = nLenlhs / 2;
    char lhs_l[ MAXLEN ];
    char lhs_r[ MAXLEN ];
    char rhs_l[ MAXLEN ];
    char rhs_r[ MAXLEN ];

    strncpy( lhs_l, lhs, nLenChild );
    strncpy( lhs_r, &lhs[ nLenChild ], nLenChild );
    strncpy( rhs_l, rhs, nLenChild );
    strncpy( rhs_r, &rhs[ nLenChild ], nLenChild );

    if( Algorithm( lhs_l, rhs_l ) && Algorithm( lhs_r, rhs_r ) ) {
        return true;
    }
    if( Algorithm( lhs_l, rhs_r ) && Algorithm( lhs_r, rhs_l ) ) {
        return true;
    }
    return false;
}

int main( void )
{
    // read two string
    char lhs[ MAXLEN ];
    char rhs[ MAXLEN ];

    scanf( "%s%s", lhs, rhs );
    bool bYes = Algorithm( lhs, rhs );
    if( bYes == true ) {
        printf( "YES\n" );
    }
    else {
        printf( "NO\n" );
    }
    return 0;
}