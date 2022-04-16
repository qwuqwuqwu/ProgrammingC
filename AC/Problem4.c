#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// pE - Exquisite Substrings

// this algorithm has efficiency problem
// try Problem4_2_AC method

int main( void )
{
    char input[ 2001 ];
    int nLength = 0;
    int i = 0;
    int j = 0;
    int tempi = 0;
    int tempj = 0;
    bool bExquisite = false;
    unsigned int nCount = 0;
    
    while( scanf( "%s", input ) != EOF ) {
        bExquisite = false;
        nLength = strlen( input );

        for( i = 0; i < nLength - 1; i++ ) {
            for( j = i + 1; j < nLength; j++ ) {
                bExquisite = false;

                if( input[ i ] != input[ j ] ) {
                    continue;
                }
                bExquisite = true;

                // traverse between i and j
                tempi = i;
                tempj = j;
                while( tempj >= tempi ) {
                    if( input[ tempi ] != input[ tempj ] ) {
                        bExquisite = false;
                        break;
                    }
                    tempi++;
                    tempj--;
                }

                if( bExquisite == true ) {
                    nCount++;
                }
            }
        }
        printf( "%u\n", nCount );
        nCount = 0;
        memset( input, 0, sizeof( input ) );
    }
    return 0;
}