// Problem 75
// Thanos' Dilemma
// https://codertw.com/%E7%A8%8B%E5%BC%8F%E8%AA%9E%E8%A8%80/561648/

#include <stdio.h>

#define MOD ( 1000000007 )

typedef struct matrix {
    unsigned long long matrix[ 3 ][ 3 ];  
} matrix_t;

const matrix_t transition = {
    .matrix = {
        { 1, 2, 1 },
        { 1, 0, 0 },
        { 0, 1, 0 }
    }
};

const unsigned long long P[ 3 ] = { 1, 12, 13 };
void multiply( matrix_t *this, const matrix_t *multiplier );
unsigned long long helper( void );

unsigned long long fpw( int nBase, int nPow )
{
    unsigned long long result = 1;
    unsigned long long mul = ( unsigned long long )nBase;
    while( nPow ) {
        if( nPow & 1 ) {
            result *= mul;
        }

        mul = mul * mul;
        nPow >>= 1;
    }
    return result;
}

int main( void )
{
    // unsigned long long result = fpw( 3, 11 );
    int testcase;
    scanf( "%d", &testcase );
    for( int i = 0; i < testcase; i++ ) {
        unsigned long long result = helper();
        printf( "%llu\n", result );
    }
    return 0;
}

void multiply( matrix_t *this, const matrix_t *multiplier )
{
    // use temp matrix to do
    // temp = this * multiplier
    matrix_t temp;
    for( int i = 0; i < 3; i++ ) {
        for( int j = 0; j < 3; j++ ) {
            temp.matrix[ i ][ j ] = 0;
            for( int k = 0; k < 3; k++ ) {
                temp.matrix[ i ][ j ] = 
                ( temp.matrix[ i ][ j ] + ( ( this->matrix[ i ][ k ] % MOD) * ( multiplier->matrix[ k ][ j ] % MOD ) ) % MOD ) % MOD;
            }
        }
    }

    // copy temp to this
    for( int i = 0; i < 3; i++ ) {
        for(int j = 0; j < 3; j++ ) {
            this->matrix[ i ][ j ] = temp.matrix[ i ][ j ];
        }
    }
}

void matrix_identity( matrix_t *this )
{
    for( int i = 0 ; i < 3; i++ ) {
        for( int j = 0; j < 3; j++ ) {
            if( i != j ) {
                this->matrix[ i ][ j ] = 0;
            }
            else {
                this->matrix[ i ][ j ] = 1;
            }
        }
    }
}

unsigned long long helper( void )
{
    unsigned long long n;
    unsigned long long result;
    scanf( "%llu", &n );
    if( n <= 3 ) {
        return P[ n- 1 ];
    }

    n -= 3;
    matrix_t ans, multiplier;
    /* identity matrix */
    matrix_identity( &ans );

    /* init a as transition */
    matrix_identity( &multiplier );

    multiply( &multiplier, &transition );

    // fpw
    while( n ) {
        /* odd handle */
        if( n & 1 ) {
            multiply(&ans, &multiplier);
        }

        multiply( &multiplier, &multiplier );
        n >>= 1;
    }


    result = (
                (((ans.matrix[ 0 ][ 0 ] % MOD) * P[ 2 ]) % MOD) +
                (((ans.matrix[ 0 ][ 1 ] % MOD) * P[ 1 ]) % MOD) + 
                (((ans.matrix[ 0 ][ 2 ] % MOD) * P[ 0 ]) % MOD)
            ) % MOD;
    return result;
}