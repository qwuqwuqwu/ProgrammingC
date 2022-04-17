// problem 11
// Change the Cap

// method: recursion

#include <stdio.h>
#define MAX ( 10000 )

int g_nTotal[ MAX + 1 ];

void Change( int nBottles, int nCaps, int *pTotalDrunk )
// use recursively method to calculate how many total drunk bottles if nBottles bought originally
// g_nTotal[ 1 ] = total bottles you can get if you just buy 1 bottle
{
    if( nBottles == 0 && ( nCaps / 3 == 0 ) ) {
        return;
    }
    int nNewCaps = nBottles;
    *pTotalDrunk += nNewCaps;
    int nBonusBottles = ( nNewCaps + nCaps ) / 3; // drink bonus bottles next round
    int nRemainCaps = ( nNewCaps + nCaps ) % 3;
    Change( nBonusBottles, nRemainCaps, pTotalDrunk );
}

int main( void )
{
    // calculate if 1~MAX bottles you bought , how many bottles you will get
    for( int i = 1; i <= MAX; i++ ) {
        Change( i, 0, &g_nTotal[ i ] );
    }
    int nN = 0;
    scanf( "%d", &nN );
    for( int i = 1; i <= MAX; i++ ) {
        if( g_nTotal[ i ] >= nN ) { // >= is required because may not exist nN in g_nTotal
            printf( "%d\n", i );
            break; // remember to break here
        }
    }
    return 0;
}