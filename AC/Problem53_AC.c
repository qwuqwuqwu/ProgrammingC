// Problem 53
// Fill containers with water
#include <stdio.h>
#include <limits.h>
#define MAXNV ( 5 )

int liter[ MAXNV ];
int n,total;
int ans[ MAXNV ];
int tmp[ MAXNV ];
int g_nMinCount = INT_MAX;

void show( int nv )
{
    printf( "(%d", ans[ 0 ] );
    for( int i = 1; i < nv; i++ ) {
        printf( ",%d", ans[ i ] );
    }
    printf( ")\n" );
}

void fill( int amount, int cur, int nv )
{
    int nTempCount = 0;
    if( cur < nv ){
        // filled
        if( amount == 0 ){
            for( int i = 0; i < nv; i++ ) {
                nTempCount += tmp[ i ];
            }
            // update by lower count
            if( nTempCount < g_nMinCount ) {
                for( int i = 0; i < nv; i++ ) {
                    ans[ i ] = tmp[ i ];
                }
                g_nMinCount = nTempCount;
            }
        }
        // recursive part
        // still exist some space
        else if( amount > 0 ){
            // do not use this liter
            fill( amount, cur + 1, nv );

            // use this liter
			tmp[ cur ]++;
			fill( amount - liter[ cur ], cur, nv );
			tmp[ cur ]--;
        }
        // if amount < 0
        // do nothing and recursion stop
    }
}

int main( void )
{
    scanf( "%d", &n );
    for(int i = 0; i < n; i++ ) {
        scanf( "%d", &liter[ i ] );
    }
    scanf( "%d", &total );
    fill( total, 0, n );
  	show( n );
    return 0;
}


// #include <stdlib.h>
// #include <stdbool.h>
// #include <limits.h>
// #include <memory.h>

// #include <stdio.h>
// #define MAXNV 5
// int DONE = 0;
// int liters[MAXNV];
// int numbers[MAXNV];
// void show(int nv);
// void filling(int amount, int cur, int nv);
// int j=0;
// int water;
// int min=100;
// int min_numbers[MAXNV]={0};
// int main(void)
// {
//     int nv, i;

// scanf("%d", &nv);
// for (i=0; i < nv; i++) {
//     scanf("%d", &liters[i]);
// }
// scanf("%d", &water);
// filling(water, 0, nv);

// for(i=0;i < nv;i++)
//     numbers[i]=min_numbers[i];
// show(nv);
// return 0;

// }

// void show(int nv)
// {
//     int i;
//     printf("(%d", numbers[0]);
//     for (i=1; i<nv; i++) {
//         printf(",%d", numbers[i]);
//     }
//     printf(")\n");
// }

// void filling(int amount, int cur, int nv)
// {
//     /* your code */
//     int *p = ( int* )malloc( sizeof( int ) * ( amount + 1 ) );
//     memset( p, 0, sizeof( int ) * ( amount + 1 ) );
//     int **pChoose = ( int** )malloc( sizeof( int* ) * ( amount + 1 ) );
//     for( int i = 0; i <= amount; i++ ) {
//         pChoose[ i ] = ( int* )malloc( sizeof( int ) * nv );
//         memset( pChoose[ i ], 0, sizeof( int ) * nv );
//     }

//     int nMinLiters = liters[ nv - 1 ];
//     bool bLiter = false;
//     for( int TryAmount = nMinLiters; TryAmount <= amount; TryAmount++ ) {
//         int nMinCount = INT_MAX;
//         int nMinTryLiterIdx = -1;
//         int nTempCount = 0;
//         bLiter = false;

//         // liters equals to TryAmount
//         for( int TryLiterIdx = 0; TryLiterIdx < nv; TryLiterIdx++ ) {   
//             if( liters[ TryLiterIdx ] == TryAmount ) {
//                 p[ TryAmount ] = 1;
//                 pChoose[ TryAmount ][ TryLiterIdx ]++;
//                 bLiter = true;
//                 break;
//             }
//         }
//         if( bLiter == true ) {
//             continue;
//         }

//         for( int TryLiterIdx = nv - 1; TryLiterIdx >= 0; TryLiterIdx-- ) {
//             if( ( TryAmount - liters[ TryLiterIdx ] > 0 ) && ( p[ TryAmount - liters[ TryLiterIdx ] ] != 0 ) ) {
//                 nTempCount = p[ TryAmount - liters[ TryLiterIdx ] ] + 1;
//                 if( nTempCount < nMinCount ) {
//                     nMinCount = nTempCount;
//                     p[ TryAmount ] = nMinCount;
//                     nMinTryLiterIdx = TryLiterIdx;
//                 }
//             }
//         }
//         memcpy( pChoose[ TryAmount ], pChoose[ TryAmount - liters[ nMinTryLiterIdx ] ], sizeof( int ) * nv );
//         pChoose[ TryAmount ][ nMinTryLiterIdx ]++;
//     }

//     int nAns = p[ amount ];
//     for( int i = 0; i < nv; i++ ) {
//         min_numbers[ i ] = pChoose[ amount ][ i ];
//     }

//     int a = 0;
//     free( p );
//     for( int i = 0; i <= amount; i++ ) {
//         free( pChoose[ i ] );
//     }
//     free( pChoose );
// }