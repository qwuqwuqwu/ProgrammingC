// problem 11
// Change the Cap

#include <stdio.h>
#define MAX ( 10000 )

int g_nTotal[ MAX + 1 ];

void Change( int nBottles, int nCaps, int *pTotalDrunk )
{
    if( nBottles == 0 && ( nCaps / 3 == 0 ) ) {
        return;
    }
    int nNewCaps = nBottles;
    *pTotalDrunk += nNewCaps;
    int nBonusBottles = ( nNewCaps + nCaps ) / 3;
    int nRemainCaps = ( nNewCaps + nCaps ) % 3;
    Change( nBonusBottles, nRemainCaps, pTotalDrunk );
}

int main( void )
{
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