#include <stdio.h>

int main( void ) {
    char Temp = '\0';
    while( scanf( "%c", &Temp ) != EOF ) {
        printf( "%c", Temp );
    }
    return 0;
}