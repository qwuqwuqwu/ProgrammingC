// problem 55
// Skate Shoes Sliding
#include <stdio.h>

int main( void )
{
    int nN = 0;
    char cTemp = '\0';
    int nLCount = 0;
    int nRCount = 0;
    scanf( "%d", &nN );
    for( int i = 0; i < nN; i++ ) {
        scanf( "%c", &cTemp );
        if( cTemp == 'L' ) {
            nLCount++;
        }
        else {
            nRCount++;
        }
    }
    printf( "%d\n", nLCount + nRCount + 1 );
    return 0;
}