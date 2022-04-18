// problem 36
// binary addition

// method : binary representation

#include <stdio.h>
#include <stdbool.h>

int DecimalToBinary( const int nDecimal )
{
    int nTempDecimal = nDecimal;
    int nBase = 1;
    int nRemainder = 0;
    int nBinary = 0;

    while( nTempDecimal != 0 ) {
        nRemainder = nTempDecimal % 2;
        nBinary = nBase * nRemainder + nBinary;
        nTempDecimal = nTempDecimal / 2;
        nBase *= 10;
    }
    return nBinary;
}

int BinaryAdd( const int nBinaryA, const int nBinaryB, int *pAdvancedOneBitCount )
{
    int nBase = 1;
    int nTempA = nBinaryA;
    int nTempB = nBinaryB;
    int nRemainderA = 0;
    int nRemainderB = 0;
    int nBitAddResult = 0;
    bool bAdvancedOneBit = false;
    int nResult = 0;
    *pAdvancedOneBitCount = 0;

    while( ( nTempA != 0 ) || ( nTempB != 0 ) ) {
        nRemainderA = nTempA % 2;
        nRemainderB = nTempB % 2;

        if( nRemainderA && nRemainderB ) {
            nBitAddResult = 2;
        }
        else if( nRemainderA || nRemainderB ) {
            nBitAddResult = 1;
        }
        else {
            nBitAddResult = 0;
        }

        // consider advance one bit + Remainder addition
        if( bAdvancedOneBit ) {
            switch( nBitAddResult ) {
            case 0:
                nBitAddResult = 1;
                bAdvancedOneBit = false;
                break;

            case 1:
                nBitAddResult = 0;
                bAdvancedOneBit = true;
                break;

            case 2:
                nBitAddResult = 1;
                bAdvancedOneBit = true;
                break;
            }
        }
        else {
            switch( nBitAddResult ) {
            case 0:
                nBitAddResult = 0;
                bAdvancedOneBit = false;
                break;

            case 1:
                nBitAddResult = 1;
                bAdvancedOneBit = false;
                break;

            case 2:
                nBitAddResult = 0;
                bAdvancedOneBit = true;
                break;
            }

        }
        
        // mod
        nTempA = nTempA / 10;
        nTempB = nTempB / 10;

        nResult = nBase * nBitAddResult + nResult;
        // ++
        nBase *= 10;

        // count advanced one bit
        if( bAdvancedOneBit == true ) {
            *pAdvancedOneBitCount = *pAdvancedOneBitCount + 1;
        }
    }

    if( bAdvancedOneBit == true ) {
        nResult = nBase * 1 + nResult;
    }

    return nResult;
}

int main( void )
{
    int N = 0;
    scanf( "%d", &N );

    int nBinaryN = DecimalToBinary( N );
    int nAdvancedOneBitCount = 0;
    int nBinaryNPlusOne = BinaryAdd( nBinaryN, 1, &nAdvancedOneBitCount );

    printf( "%d %d", nBinaryNPlusOne, nAdvancedOneBitCount );
    return 0;
}
