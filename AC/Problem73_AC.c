#include <stdio.h>
#include <string.h>

#define MOD ( 1000000007 )

typedef struct _Tx {
    long long int m_data[ 2 ][ 2 ];
} Tx;

typedef struct _Vx {
    long long int m_data[ 2 ];
} Vx;

const Tx g_Tx = { 1, 1, 1, 0 };

Tx Identity( void ) {
    Tx Ans;
    memset( &Ans, 0, sizeof( Tx ) );
    for( int i = 0; i < 2; i++ ) {
        Ans.m_data[ i ][ i ] = 1;
    }
    return Ans;
}

Tx Multiply( Tx lhs, Tx rhs )
{
    Tx Ans;
    long long int Temp;
    for( int i = 0; i < 2; i++ ) {
        for( int j = 0; j < 2; j++ ) {
            // for NewTx[ i ][ j ] = row i of lhs * col j of rhs
            Temp = 0;
            for( int k = 0; k < 2; k++ ) {
                Temp = ( Temp + ( ( lhs.m_data[ i ][ k ] % MOD ) * ( rhs.m_data[ k ][ j ] % MOD ) ) % MOD ) % MOD;
                // becareful
                // += should MOD
            }
            Ans.m_data[ i ][ j ] = Temp;
        }
    }
    return Ans;
}

Vx MultiplyV( Tx lhs, Vx rhs )
{
    Vx Ans;
    long long int Temp;
    for( int i = 0; i < 2; i++ ) {
        for( int j = 0; j < 1; j++ ) {
            // for NewTx[ i ][ j ] = row i of lhs * col j of rhs
            Temp = 0;
            for( int k = 0; k < 2; k++ ) {
                Temp = ( Temp + ( ( lhs.m_data[ i ][ k ] % MOD ) * ( rhs.m_data[ k ] % MOD ) ) % MOD ) % MOD;
                // be careful
                // += should MOD
            }
            Ans.m_data[ i ] = Temp;
        }
    }
    return Ans;
}

Tx fpw( Tx TX, long long int pow )
{
    Tx Temp = Identity();
    if( pow == 1 ) {
        return TX;
    }
    else if( pow == 0 ) {
        return Temp;
    }

    // odd power
    if( pow % 2 == 1 ) {
        Temp = Multiply( Temp, g_Tx );
    }
    Tx Temp2 = fpw( TX, pow / 2 );
    
    Temp = Multiply( Temp, Temp2 ); // use temp2, rather than fpw() twice
    Temp = Multiply( Temp, Temp2 ); // use temp2, rather than fpw() twice

    return Temp;
}

int main( void )
{
    Vx F_21 = { 1, 1 };

    long long int nPow = 0;
    while( scanf( "%lld", &nPow ) != EOF ) {
        if( nPow == 1 || nPow == 2 ) {
            printf( "%lld\n", 1 );
        }
        else {
            Tx Temp = fpw( g_Tx, nPow - 2 );
            Vx Test = MultiplyV( Temp, F_21 );
            printf( "%lld\n", Test.m_data[ 0 ] );
        }
    }
    
    return 0;
}