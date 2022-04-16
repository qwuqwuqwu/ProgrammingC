// problem 31
// Ghoul Dawn

#include <stdio.h>

#define MAX_LENOF_ARRAY ( 5000 )

int g_nA[ MAX_LENOF_ARRAY ];
long long g_nPrefixSum[ MAX_LENOF_ARRAY + 1 ];

int main( void )
{
    // get data
    int nN = 0;
    int nK = 0;
    scanf( "%d%d", &nN, &nK );
    for( int i = 0; i < nN; i++ ) {
        scanf( "%d", &g_nA[ i ] );
    }

    // prefix sum of average
    g_nPrefixSum[ 0 ] = 0;
    for( int i = 1; i <= nN; i++ ) {
        g_nPrefixSum[ i ] = g_nPrefixSum[ i - 1 ] + g_nA[ i - 1 ];
    }

    // calculate max average
    double Temp = 0.0;
    double Temp2 = 0.0;
    double Max = 0.0;
    int nUpIdx;
    int nLowIdx;
    for( int i = 0; i <= nN; i++ ) {
        for( int j = nK; j <= nN; j++ ) {
            nLowIdx = i;
            nUpIdx = i + j;
            //printf( "nLowIdx:%d, nUpIdx:%d\n", nLowIdx, nUpIdx );

            if( nUpIdx > nN ) {
                // do nothing;
            }
            else {
                Temp = ( double )( g_nPrefixSum[ nUpIdx ] - g_nPrefixSum[ nLowIdx ] );
                Temp2 = Temp / j; // be careful!!!! float is not precise enough
                //printf( "a = %lld, b = %lld, Temp = %.3lf, Temp2 = %.3lf\n",g_nPrefixSum[ nUpIdx ], g_nPrefixSum[ nLowIdx ] , Temp, Temp2 );

                if( Temp2 > Max ) {
                    Max = Temp2;
                }
            }
        }
    }
    printf( "%.3lf\n", Max );

    return 0;
}