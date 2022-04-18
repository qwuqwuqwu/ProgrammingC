// problem 44
// the night's watch

// method: bruteforce

#include <stdio.h>
#define MAX ( 1e9+7 )

const int Min( const int a, const int b )
{
    if( a < b ) {
        return a;
    }
    else {
        return b;
    }
}

const int Max( const int a, const int b )
{
    if( a > b ) {
        return a;
    }
    else {
        return b;
    }
}

int Algorithm_BruteForce( int nN, int nM, int nK, int nA[] )
{
    int i = 0;

    int nMax = 0;
    int nTempResult = MAX;
    int nResult = 0;

    if( nM >= ( nK + 1 ) ) {
        // nK people you can determine
        // i : i people choose front
        // ( nK - i ) : rest of the people among nK choose tail
        // i = 0 ~ nK
        for( i = 0; i <= nK; i++  ) {

            // find minimum after nN
            nTempResult = MAX;
            
            // nM - 1 - nK people you cannot determine
            // j : j people choose front
            // ( nM - 1 - nK - j ): rest of the people among ( nM - 1 - nK ) choose tail
            // j = 0 ~ ( nM - 1 - nK )
            for( int j = 0; j <= ( nM - nK - 1 ); j++ ) {

                // head idx = i + j
                // tail idx = ( nN - 1 ) - ( nK - i ) - ( nM - 1 - nK - j ) = nN - nM + i + j
                nMax = Max( nA[ i + j ], nA[ nN - nM + i + j ] ); // find MAX between head, tail
                nTempResult = Min( nMax, nTempResult ); // find min in all j test cases, you cannot determine

                //printf("nL_L2 = %d, nR_L2 = %d, Max = %d, Min = %d\n", nL_Level2, nR_Level2, nMax, nResult_Level2 );
            }

            nResult = Max( nTempResult, nResult ); // find max in all i test cases, you can determine
        }
        return nResult;
    }
    // nM < nK
    // you can determine all things
    else {
        //printf("nM < nK\n");

        nResult = -1;
        // j: j people choose front
        // ( nM - 1 ) - j: rest of the people among nM - 1 choose tail
        // j = 0 ~ ( nM - 1 )
        for( int j = 0; j <= ( nM - 1 ); j++ ) {
            //printf("nL_L2 = %d, nR_L2 = %d\n", nL_Level2, nR_Level2 );

            // choose max between head and tail
            nMax = Max( nA[ j ], nA[ nN - nM + j ] ); // nN - 1 - ( ( nM - 1 ) - j ) = nN - nM + j

            nResult = Max( nMax, nResult ); // find max in all j test cases, you can determine
        }
        return nResult;
    }
}

int main( void ) {
    int nT = 0; // total number of test cases
    scanf( "%d", &nT );

    int nN = 0; // 1 <= n <= 5000
    int nM = 0; // 1 <= m <= n
    int nK = 0; // 0 <= k <= n - 1
    int nAnswer = 0;

    for( int i = 0; i < nT; i++ ) {
        scanf( "%d%d%d", &nN, &nM, &nK );
        int nA[ 5005 ];

        for( int j = 0; j < nN; j++ ) {
            scanf( "%d", &nA[ j ] );
        }

        nAnswer = Algorithm_BruteForce( nN, nM, nK, nA );
        printf( "%d\n", nAnswer );
    }
    return 0;
}