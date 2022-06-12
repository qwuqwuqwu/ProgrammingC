// Problem 47
// youbike racer
// HW9_C
#include <stdio.h>

#define MAX ( 100000 )
// #define MAX ( 100 )

unsigned int g_Check[ MAX ];

int main( void )
{
    int nN = 0;
    unsigned int nK = 0;
    scanf( "%d%u", &nN, &nK );

    for( int i = 0; i < nN; i++ ) {
        scanf( "%u", &g_Check[ i ] );
    }

    // 
    unsigned int nDeadIdx = nK;
    int nBattery = nK;
    int nRechargeCount = 0;
    int nLastIdx = 0;

    if( nN == 1 ) {
        // success
        if( g_Check[ 0 ] <= nK ) {
            printf( "0\n" );
        }
        else {
            printf("The Legend Falls.\n");
        }
        return 0;
    }

    // check index 0 ~ nN - 2
    for( int idx = 0; idx <= nN - 2; idx++ ) {
        // recharge
        if( g_Check[ idx ] > nDeadIdx ) {
            // recharge in last index
            nRechargeCount++;
            nDeadIdx = g_Check[ idx - 1 ] + nK;
        }
        else if( g_Check[ idx ] == nDeadIdx ) {
            nRechargeCount++;
            nDeadIdx = g_Check[ idx ] + nK;
        }

        // check again after recharge
        // if still not pass, means distance between idx and idx + 1 is too large
        if( g_Check[ idx ] > nDeadIdx ) {
            printf( "The Legend Falls.\n" );
            return 0;
        }
    }

    // check last index
    // because g_Check[ nN - 1 ] - g_Check[ nN - 2 ] <= nK
    // recharge in nN - 2 must success to reach nN - 1
    if( g_Check[ nN - 1 ] - g_Check[ nN - 2 ] <= nK ) {
        if( g_Check[ nN - 1 ] > nDeadIdx ) {
            nRechargeCount++;
        }
    }
    else {
        printf( "The Legend Falls.\n" );
        return 0;   
    }

    printf( "%d\n", nRechargeCount );
    return 0;
}