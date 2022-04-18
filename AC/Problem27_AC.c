// problem 27
// pC - Collinear

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZEOF_POINTS   ( 100 )
#define MAX_SIZEOF_SLOPES   ( MAX_SIZEOF_POINTS * ( MAX_SIZEOF_POINTS - 1 ) * ( MAX_SIZEOF_POINTS - 2 ) / 6 ) // C( MAX_SIZEOF_POINTS, 3 )

// basic math

// One line in ( x, y ) plane can be represented by this function
// Ax + By + C = 0
// assume two points ( x1, y1 ), ( x2, y2 ) are in this line, then
// A( x2 - x1 ) + B( y2 - y1 ) = 0
// DX = x2 - x1 ; DY = y2 - y1;
// A DX + B DY = 0;
// A : B = - DY : DX = - DY / GCD : DX / GCD = A / GCD : B / GCD = A' : B'
// C = -A * x1 + B * y1 => C' = -A' * x1 + B' * y1  

struct Point {
    int nX;
    int nY;
};

struct Slope {
    int DX;
    int DY;
    int nSign;
    int nIntercept;
};

struct Slope g_Slopes[ MAX_SIZEOF_SLOPES ];
int g_nSlopeCount = 0;

int gcd( int a, int b )
{
	if( b == 0 ) {
		return a;
	}
    else { 
		return gcd( b, a % b );
	} 
}

struct Slope CalcSlope( const struct Point j, const struct Point k )
{
    int DY = abs( k.nY - j.nY );
    int DX = abs( k.nX - j.nX );
    int GCD = gcd( DY, DX );
    struct Slope S;
    S.DX = DX / GCD;
    S.DY = DY / GCD;
    if( S.DX == 0 ) {
        S.nSign = 2;
        S.nIntercept = k.nX;
    }
    else if( S.DY == 0 ) {
        S.nSign = 3;
        S.nIntercept = k.nY;
    }
    else {
        S.nSign = ( k.nY - j.nY ) * ( k.nX - j.nX ) > 0 ? 1 : -1;
        S.nIntercept = ( -S.nSign * S.DY * k.nX + S.DX * k.nY );
    }
    // ( 0, 1 ), ( 1, 2 ) DX 1 DY 1 GCD 1  -1 * 1 * 1 + 1 * 2 = 1
    // ( 0, 1 ), ( 2, 3 ) DX 1 DY 1 GCD 2  -1 * 1 * 2 + 1 * 3 = 1 

    return S;
}

bool CompareSlope( const struct Slope S1, const struct Slope S2  )
{
    if( S2.nSign == 2 && S1.nSign == 2 && S1.nIntercept == S2.nIntercept ) {
        return true;
    }
    else if( S2.nSign == 3 && S1.nSign == 3 && S1.nIntercept == S2.nIntercept ) {
        return true;
    }
    else {
        if( S1.nSign == S2.nSign && S1.DX == S2.DX && S1.DY == S2.DY && S1.nIntercept == S2.nIntercept ) {
            return true;
        }
    }
    return false;
}

void isNewCollinear( const struct Point j, const struct Point k, const struct Point l )
{
    struct Slope S1 = CalcSlope( j, k );
    struct Slope S2 = CalcSlope( k, l );
    bool bCollinear = CompareSlope( S1, S2 );
    // record it
    if( bCollinear == true ) {
        for( int i = 0; i < g_nSlopeCount; i++ ) {
            if( CompareSlope( g_Slopes[ i ], S1 ) == true ) {
                return;
            }
        }
        g_Slopes[ g_nSlopeCount ] = S1;
        g_nSlopeCount++;
        return;
    }
}


int main( void )
{
    int nT = 0;
    int nN = 0;
    int nCount = 0;
    scanf( "%d", &nT );
    struct Point Points[ MAX_SIZEOF_POINTS ];
    
    for( int i = 0; i < nT; i++ ) {
        g_nSlopeCount = 0;

        scanf( "%d", &nN );
        // get points
        for( int j = 0; j < nN; j++ ) {
            scanf( "%d%d", &Points[ j ].nX, &Points[ j ].nY );
        }

        // calc collinear
        for( int j = 0; j <= nN - 3; j++ ) {
            for( int k = j + 1; k <= nN - 2 ; k++ ) {
                for( int l = k + 1; l <= nN - 1; l++ ) {
                    printf( "%d %d %d\n", j + 1, k + 1, l + 1 );
                    isNewCollinear( Points[ j ], Points[ k ], Points[ l ] );
                }
            }
        }
        printf( "%d\n", g_nSlopeCount );
        printf("---------------\n\n");
    }
    
    return 0;
}