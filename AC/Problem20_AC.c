#include <stdio.h>

int main( void )
{
    unsigned long nl = 0;
    unsigned long nr = 0;

    scanf( "%lu%lu", &nl, &nr );
    printf( "%lu %lu", nl, nl * 2 );
    return 0;
}