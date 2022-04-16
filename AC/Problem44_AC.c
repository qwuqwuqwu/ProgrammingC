// problem 44
// the night's watch

#include <stdio.h>
#define MAX 1e9+7

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
        for( i = 0; i <= nK; i++  ) {
            // pick head i count
            
            // find minimum after nN
            nTempResult = MAX;
            for( int j = 0; j <= ( nM - nK - 1 ); j++ ) {

                nMax = Max( nA[ i + j ], nA[ nN - nM + i + j ] );
                nTempResult = Min( nMax, nTempResult );
                //printf("nL_L2 = %d, nR_L2 = %d, Max = %d, Min = %d\n", nL_Level2, nR_Level2, nMax, nResult_Level2 );
            }

            nResult = Max( nTempResult, nResult );
        }
        return nResult;
    }
    // nM < nK
    else {
        //printf("nM < nK\n");
        nResult = -1;
        for( int j = 0; j <= ( nM - 1 ); j++ ) {
            //printf("nL_L2 = %d, nR_L2 = %d\n", nL_Level2, nR_Level2 );

            nMax = Max( nA[ j ], nA[ nN - nM + j ] );
            nResult = Max( nMax, nResult );
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