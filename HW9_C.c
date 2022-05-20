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
        if( g_Check[ 0 ] <= nK ) {
            printf( "0\n" );
        }
        else {
            printf("The Legend Falls.\n");
        }
        return 0;
    }


    for( int idx = 0; idx < nN - 1; idx++ ) {
        unsigned int nDist = g_Check[ idx + 1 ] - g_Check[ idx ];
        if( nDist > nK ) {
            printf( "The Legend Falls.\n" );
            return 0;
        }

        // recharge
        if( g_Check[ idx ] > nDeadIdx && idx >= 1 ) {
            // recharge in last index
            nRechargeCount++;
            nDeadIdx = g_Check[ idx - 1 ] + nK;
        }
        else if( g_Check[ idx ] == nDeadIdx && idx >= 1 ) {
            nRechargeCount++;
            nDeadIdx = g_Check[ idx ] + nK;
        }
    }

    if( g_Check[ nN - 1 ] > nDeadIdx ) {
        nRechargeCount++;
    }

    printf( "%d\n", nRechargeCount );
    return 0;
}