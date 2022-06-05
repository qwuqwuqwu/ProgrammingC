#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAX ( ( long long int )1e18 )

// log2(1e18) = 59
#define MAX2    ( 59 )
long long int g_n2Power[ MAX2 + 1 ];

// #define MAX ( 1000000000 )
// #define MAX ( 1000 )

int main( void )
{
    // create 2 power array
    g_n2Power[ 0 ] = 1;
    for( int i = 1; i <= MAX2; i++ ) {
        g_n2Power[ i ] = g_n2Power[ i - 1 ] * 2;
    }

    int nQ = 0;
    scanf( "%d", &nQ );
    for( int i = 0; i < nQ; i++ ) {
        long long int nTarget = 0;
        scanf( "%lld", &nTarget );

        //
        bool bFound1 = false;
        long long int ans1 = 0;

        // check power of 2
        long long int nTempTarget = nTarget + 1;
        long long int nTempBase = 1;

        long long int l = 0;
        long long int m = l;
        long long int r = MAX2;
        while( l <= r ) {
            m = l + ( r - l ) / 2;
            long long int nTempBase = g_n2Power[ m ];
            // look after
            if( nTempBase < nTempTarget ) {
                l = m + 1;
            }
            // look before
            else if( nTempBase > nTempTarget ) {
                r = m - 1;
            }
            else {
                bFound1 = true;
                ans1 = nTempBase;
                break;
            }
        }

        //
        bool bFound2 = false;
        long long int ans2 = 0;

        long long int nOdd = 3;
        while( bFound2 == false ) {
            long long int nOddGameBase = nOdd * ( nOdd - 1 ) / 2;
            if( nOddGameBase > MAX ) {
                break;
            }
            if( nOddGameBase == nTarget ) {
                ans2 = nOdd;
                bFound2 = true;
                break;
            }
            if( nOddGameBase > nTarget ) {
                break;
            }
            long long int nTempTarget = nTarget - nOddGameBase;
            long long int nTempBase = nOdd;
            
            //
            if( nTempTarget % nOdd == 0 ) {
                nTempTarget /= nOdd;
                nTempTarget += 1;

                long long int l = 0;
                long long int m = l;
                long long int r = MAX2;
                while( l <= r ) {
                    m = l + ( r - l ) / 2;
                    long long int nTempBase = g_n2Power[ m ];
                    // look after
                    if( nTempBase < nTempTarget ) {
                        l = m + 1;
                    }
                    // look before
                    else if( nTempBase > nTempTarget ) {
                        r = m - 1;
                    }
                    else {
                        bFound2 = true;
                        ans2 = nTempBase * nOdd;
                        break;
                    }
                }
            }
            if( bFound2 == true ) {
                break;
            }
            nOdd += 2; // next odd
        }

        if( bFound1 && bFound2 ) {
            if( ans1 < ans2 ) {
                printf( "%lld\n", ans1 );
            }
            else {
                printf( "%lld\n", ans2 );
            }
        }
        else if( bFound1 == true ) {
            printf( "%lld\n", ans1 );
        }
        else if( bFound2 == true ) {
            printf( "%lld\n", ans2 );
        }
        else {
            printf( "-1\n" );
        }
    }
    
    return 0;
}