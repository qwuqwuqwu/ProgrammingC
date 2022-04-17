// Money exchange

#include <stdio.h>

#define MAX_CoinValueCount  ( 10 )

int g_nCoinValueCount = 0;
int g_nCoinValue[ MAX_CoinValueCount + 1 ];
int g_nSuccessCount = 0;
int g_nValueCount[ MAX_CoinValueCount + 1 ];

void show( void )
{
    for( int i = 0; i < g_nCoinValueCount; i++ ) {
        printf( "%d ", g_nValueCount[ i + 1 ] );
    }
    printf( "\n=======\n" );
}

void TryExchange( int nAmount, int nMiniValueIdx )
{
    if( nAmount == 0 ) {
        show();
        g_nSuccessCount++;
    }
    else if( nAmount < 0 ) {
        return;
    }
    else {
        if( nMiniValueIdx > g_nCoinValueCount ) {
            return;
        }
        // use one minivalue money
        g_nValueCount[ nMiniValueIdx ]++;
        TryExchange( nAmount - g_nCoinValue[ nMiniValueIdx ], nMiniValueIdx );
        g_nValueCount[ nMiniValueIdx ]--;
        
        // do not use one minivalue money, and enhance idx
        TryExchange( nAmount, nMiniValueIdx + 1 );
    }
}

int main( void )
{
    scanf( "%d", &g_nCoinValueCount );
    
    for( int i = 0; i < g_nCoinValueCount; i++ ) {
        scanf( "%d", &g_nCoinValue[ i + 1 ] );
    }
    
    int nAmount = 0;
    scanf( "%d", &nAmount );
    
    TryExchange( nAmount, 1 ); // MiniValue Idx = 1
    printf( "Total success count = %d", g_nSuccessCount );
    return 0;
}
