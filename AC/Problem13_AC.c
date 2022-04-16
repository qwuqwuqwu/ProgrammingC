// problem 13
// Hexadecimal to Binary

#include <stdio.h>

#define MAX_LENOF_BITARRAY  ( 1000 )


int main( void )
{
    int nA = 0;
    int nB = 0;
    int nC = 0;
    scanf( "%x%x", &nA, &nB );
    nC = nA + nB;
    int nBitArray[ MAX_LENOF_BITARRAY ];
    int nBitLen = 0;

    // nC to binary
    while( nC > 0 ) {
        nBitArray[ nBitLen ] = nC % 2; // bit
        nC /= 2;
        nBitLen++;
    }

    for( int i = 0; i < nBitLen; i++ ) {
        printf( "%d", nBitArray[ nBitLen - i - 1 ] );
    }
    printf( "\n" );

    return 0;
}