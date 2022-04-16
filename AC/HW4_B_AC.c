#include <stdio.h>

long long g_nBuffer[ 1000001 ] = { 0 };
long long g_nBuffer2[ 1000001 ] = { 0 };

int g_nMax = 0;

long long Algorithm( int a, int b )
{
    int temp = b;
    long long nCount = 0;
    int nStart = 1;

    if( b < g_nMax ) {
        return ( g_nBuffer2[ b ] - g_nBuffer2[ a - 1 ] );
    }

    // find start
    if( a < g_nMax ) {
        nStart = a;
    }
    else {
        nStart = g_nMax + 1;
    }
    
    for( int i = nStart; i <= b; i++ ) {
        temp = i;
        nCount = 0;
        while( temp >= 1 ) {
            if( temp % 10 == 1 ) {
                nCount++;
            }
            temp /= 10;
        }
        g_nBuffer[ i ] = nCount;
    }

    g_nBuffer2[ 1 ] = g_nBuffer[ 1 ];
    for( int i = 2; i <= b; i++ ) {
        g_nBuffer2[ i ] = g_nBuffer2[ i - 1 ] + g_nBuffer[ i ];
    }

    if( b > g_nMax ) {
        g_nMax = b;
    }

    return ( g_nBuffer2[ b ] - g_nBuffer2[ a - 1 ] );
}

int main( void ) {

    int t = 0;
    int a = 0;
    int b = 0;

    scanf( "%d", &t );

    for( int i = 0; i < t; i++ ) {
        scanf( "%d %d", &a, &b );
        printf( "%lld\n", Algorithm( a, b ) );
    }
    return 0;
}