// problem 3
// Progression
// method: basic math

// determine input array is arithematic progression or geometric progression
// and output the fourth element

#include <stdio.h>

int main( void )
{
    // read 3 int
    int A[ 3 ];
    scanf( "%d%d%d", &A[ 0 ], &A[ 1 ], &A[ 2 ] );

    // determine arithematic progression or geometric progression
    // arithematic
    if( ( A[ 2 ] - A[ 1 ] ) == ( A[ 1 ] - A[ 0 ] ) ) {
        int d = A[ 2 ] - A[ 1 ];
        printf( "%d %d\n", A[ 0 ] - d, A[ 2 ] + d );
    }
    // geometric
    else {
        float r = A[ 1 ] / A[ 0 ];
        printf( "%d %d\n", ( int )( A[ 0 ] / r ), ( int )( A[ 2 ] * r ) );
    }
    return 0;
}