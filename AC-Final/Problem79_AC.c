#include <stdio.h>
#include <math.h>

#define MAX ( 5 )
#define EPSILON ( 1e-5 )

typedef struct _Vec {
    float m_data[ MAX ];
} Vec;

typedef struct _Mat {
    float m_data[ MAX ][ MAX ];
} Mat;

int g_nN;

Vec Multiply( const Mat lhs, const Vec rhs )
{
    Vec temp;
    for( int i = 0; i < g_nN; i++ ) {
        // ans[ i ] = row of lhs * col of rhs
        float entry = 0.0;
        for( int k = 0; k < g_nN; k++ ) {
            entry += lhs.m_data[ i ][ k ] * rhs.m_data[ k ];
        }
        temp.m_data[ i ] = entry;
    }
    return temp;
}

int helper( const Mat A, const Vec B, const int nTarget, const int nCount )
{
    if( B.m_data[ 0 ] <= nTarget ) {
        return nCount;
    }

    Vec C = Multiply( A, B );
    // https://ccjou.wordpress.com/2009/08/06/%E9%A6%AC%E5%8F%AF%E5%A4%AB%E9%81%8E%E7%A8%8B/
    // 馬可夫過程的性質
    // 會逐漸收斂到穩態
    // 而中間的過程也許會有震盪 但震盪會逐漸變小
    
    // increase
    // 如果反而變大了, 若超過1這個threshold 就認為它不會收斂(magical number)
    if( C.m_data[ 0 ] - B.m_data[ 0 ] > 1 ) { 
        return -1;
    }
    // 逐漸收斂的過程, 當變化輛小於EPSION時, 就算是收斂
    // 因為每次recursion一開始都會檢查是否<=nTarget
    // 跑到這個邏輯判斷表示還沒小於nTarget 但已經收斂了
    // 那就不可能< nTarget了
    else if( fabsf( C.m_data[ 0 ] - B.m_data[ 0 ] ) <= EPSILON ) {
        return -1;
    }

    helper( A, C, nTarget, nCount + 1 );
}

int main( void )
{
    int nQ = 0;
    scanf( "%d", &nQ );
    for( int q = 0; q < nQ; q++ ) {
        scanf( "\n" );
        Mat TempMat;
        scanf( "%d", &g_nN );
        for( int i = 0; i < g_nN; i++ ) {
            for( int j = 0; j < g_nN; j++ ) {
                scanf( "%f", &TempMat.m_data[ i ][ j ] );
            }
        }

        Vec TempVec;
        for( int i = 0; i < g_nN; i++ ) {
            int nTemp;
            scanf( "%d", &nTemp );
            TempVec.m_data[ i ] = ( float )nTemp;
        }

        int nTarget = 0;
        scanf( "%d", &nTarget );

        int ans = helper( TempMat, TempVec, nTarget, 0 );
        if( ans == -1 ) {
            printf( "Never\n" );
        }
        else {
            printf( "%d\n", ans );
        }
    }
    
    return 0;
}