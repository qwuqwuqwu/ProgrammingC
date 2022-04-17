// problem 19
// too many words

// method: getchar

#include <stdio.h>

int main( void )
{
    char cTemp = '\0';
    while( 1 ) {
        cTemp = getchar();
        if( cTemp == EOF ) {
            break;
        }
        printf( "%c", cTemp );
    }
    return 0;
}