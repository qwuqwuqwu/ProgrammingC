// problem 8
// The number of occurrences

// method: character compare

#include <stdio.h>
#include "string.h"
#include <stdbool.h>

#define MAX_LEN_A   ( 4 ) 
#define MAX_LEN_B   ( 9 )

int main( void )
{
    char A[ MAX_LEN_A ];
    char B[ MAX_LEN_B ];
    int nN = 0;
    scanf( "%s", A );
    scanf( "%d", &nN );
    
    int nLenA = strlen( A );
    int nMax = 0;

    for( int i = 0; i < nN; i++ ) {
        // count time in one string
        scanf( "%s", B );
        int nLenB = strlen( B );
        int nCount = 0;
        bool bMatch = true;

        // check each idx in B
        for( int j = 0; j < nLenB; j++ ) {
            bMatch = true;
            
            // check each character in A
            for( int k = 0; k < nLenA; k++ ) {
                if( A[ k ] != B[ j + k ] ) {
                    bMatch = false;
                    continue;
                }
            }
            if( bMatch == true ) {
                nCount++;
            }
        }

        // update max count in nN test case
        if( nCount > nMax ) {
            nMax = nCount;
        }
    }
    printf( "%d", nMax );

    return 0;
}