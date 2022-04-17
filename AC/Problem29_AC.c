// problem 29
// too many treasures

// method: prefix sum

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nN = 1;
    int nQ = 1;
    scanf( "%d%d", &nN, &nQ );
    
    long long *pnT = malloc( sizeof( long long ) * nN );
    for( int i = 0; i < nN; i++ ) {
        scanf( "%lld", pnT + i );
    }
    
    long long *pnTSum = malloc( sizeof( long long ) * ( nN ) );
    int nCutOffIdx = nN;
    long long nSum = 0;
    pnTSum[ 0 ] = 0;
    
    for( int i = 0; i < nN; i++ ) {
        if( pnT[ i ] <= 0 ) {
            nCutOffIdx = i;
            break;
        }
        nSum += pnT[ i ];
        pnTSum[ i + 1 ] = nSum;
    }
    
    int nL = 1;
    int nR = 1;
    int nM = 1;
    for( int i = 0; i < nQ; i++ ){
        scanf( "%d%d%d", &nL, &nR, &nM );
        nL -= 1;
        nR -= 1;
            
        nM = nL + nM;
        if( nCutOffIdx <= nL ) {
            printf( "0\n" );
        }
        else if( ( nL < nCutOffIdx ) && ( nCutOffIdx < nM ) ) {
            printf( "%lld\n", pnTSum[ nCutOffIdx ] - pnTSum[ nL ] );
        }
        else {
            printf( "%lld\n", pnTSum[ nM ] - pnTSum[ nL ] );
        }
    }
    free( pnT );
    free( pnTSum );

    return 0;
}
