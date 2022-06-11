// Problem 86
// Unlimited Triangle Work
#include <stdio.h>
#include <string.h>

#define MAX ( ( int )5e4 )
#define min( lhs, rhs ) ( ( lhs ) <= ( rhs ) ) ? ( lhs ) : ( rhs )

int g_k[ MAX + MAX + 1 ]; // be careful!
int g_a[ MAX + MAX + 1 ];

void helper( const int nA, const int nB, const int nC, const int nD )
// shortest edge: first
// medium edge: second
// longest edge: third
// len of first + len of second should > len of third
{
    // initialize global array
    memset( g_k, 0, sizeof( int ) * ( MAX + MAX + 1 ) ); // be careful!
    memset( g_a, 0, sizeof( int ) * ( MAX + MAX + 1 ) );
    
    // find a_xy( i )
    // prepare g_k
    for( int first = nA; first <= nB; first++ ) {
        g_k[ first + nB ]++;
        g_k[ first + nC + 1 ]--;
    }
    // prefix sum of g_k to get a_xy( i )
    for( int i = nA; i <= nB + nC; i++ ) {
        g_a[ i ] = g_a[ i - 1 ] + g_k[ i ];
    }

    /* // debug code to check g_a
    for( int i = 0; i <= nB + nC; i++ ) {
        printf( "%d %d\n", i, g_a[ i ] );
    }
    */
    
    // calc third
    // nC <= third < i <= nD
    long long int nCount = 0;
    int nThirdCount = 0;
    int j = 0;
    for( int i = nA + nB; i <= nB + nC; i++ ) {
        if( i <= nC ) {
            continue;
        }

        // if i exceed nD, only clamped third can be calculated
        if( i > nD ) {
            nThirdCount = nD + 1 - nC;
        }
        else {
            nThirdCount = i - nC;
        }
        
        //printf( "nThirdCount = %d, add = %d\n", nThirdCount, g_a[ i ] * nThirdCount );
        nCount += g_a[ i ] * nThirdCount;
    }
    printf( "%lld\n", nCount );
}

int main( void )
{
    int nT = 0;
    int nA = 0, nB = 0, nC = 0, nD = 0;
    scanf( "%d", &nT );
    for( int i = 0; i < nT; i++ ) {
        scanf( "%d%d%d%d", &nA, &nB, &nC, &nD );
        helper( nA, nB, nC, nD );
    }
    return 0;
}