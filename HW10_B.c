#include <stdio.h>

float x;

int main( void )
{
    float x = 0.0;
    while( scanf( "%f", &x ) != EOF ) {
        int a = *( ( int* )&x );
        for( int i = 31; i >= 0; i-- ) {
            if( ( a & ( 1 << i ) ) != 0 ) {
                printf( "1" );
            }
            else {
                printf( "0" );
            }
        }

        printf( "\n" );
    }
    return 0;
}