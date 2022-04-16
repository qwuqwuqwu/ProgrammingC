#include <stdio.h>

void binary( unsigned int i )
{
    if (i > 0) {
        binary(i/2); 
        printf("%u", i%2);
    }
}

void Hexadecimal( unsigned int i )
{
    if( i > 0 ) {
        Hexadecimal( i / 16 );
        if( i % 16 >= 10 ) {
            printf( "%c", ( i % 16 ) - 10 + 'A' );
        }
        else {
            printf( "%u", i % 16 );
        }
    }
}

int main( void )
{
    unsigned int n;
    scanf( "%u", &n );
    binary( n );
    printf( "\n" );
    Hexadecimal( n ); // this is my example
    return 0;
}