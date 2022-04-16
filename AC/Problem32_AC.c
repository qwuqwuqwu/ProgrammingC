// problem 32
// HA HA HA

#include <stdio.h>

#define MAX_SIZEOF_ARRAY    ( 10001 )

int gcd( int a, int b );
int main(void)
{
    int nN = 0;
    scanf( "%d", &nN );
    int nA[ MAX_SIZEOF_ARRAY ];
    int nTempGCD = 0;
    int nMaxGCD = 0;

    // get An
    for( int i = 0; i < nN; i++ ) {
        scanf( "%d", &nA[ i ] );
    }
    
    // find max gcd
    for( int i = 0; i < nN - 1; i++ ) {
        for( int j = i + 1; j < nN; j++ ) {
            nTempGCD = gcd( nA[ i ], nA[ j ] );
            if( nTempGCD > nMaxGCD ) {
                nMaxGCD = nTempGCD;
            }
        }
    }
    
    printf( "%d\n", nMaxGCD );
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
