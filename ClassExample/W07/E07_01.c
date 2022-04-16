// gcd greatest common divisor

#include <stdio.h>
int gcd( int a, int b );
int main( void )
{
	int x, y;
	scanf( "%d%d", &x, &y );
	printf( "gcd( %d, %d ) = %d\n", x, y, gcd( x, y ) );
    return 0;
}

int gcd( int a, int b )
{
	if( b == 0 ) {
		return a;
	}
    else { 
		return gcd( b, a % b );
	} 
}