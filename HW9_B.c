#include <stdio.h>
#include <stdbool.h>

int main( void )
{
    int nN;
    scanf( "%d", &nN );
    getchar();

    char cChar;
    bool bHit[ 26 ] = { false };

    int i = 0;
    int nIdx = -1;
    bool bHa = false;
    while( ( cChar = getchar() ) != EOF ) {
        nIdx = (int)( cChar - 'a' );
        if( bHit[ nIdx ] == true ) {
            bHa = true;
            break;
        }
        else {
            bHit[ nIdx ] = true;
            i++;
        }

        if( i == nN ) {
            break;
        }
    }

    if( i == 1 ) {
        bHa = true;
    }

    if( bHa == true ) {
        printf( "I'm the god of Knuckles!\n" );
    }
    else {
        printf( "Different makes perfect\n" );
    }
    return 0;
}