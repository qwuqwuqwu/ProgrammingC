// Problem 45
// I got a perfect body
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE ( 300000 )
// #define ARRAY_SIZE ( 10 )

int g_price[ARRAY_SIZE];
long long int DP[ARRAY_SIZE + 1];
int helper(long long int product, long long int dollar, long long int buy);

int cmpfunc(const void *a, const void *b)
// sort from cheaper to more expensive goods
{
    return (*(int *)a - *(int *)b);
}
int main(void)
{
    int testcase;
    scanf("%d", &testcase);

    long long int product, dollar, buy, result;

    for( int i = 0; i < testcase; i++ ) {

        scanf("%lld%lld%lld", &product, &dollar, &buy);
        
        for( int j = 0; j < product; j++ ) {
            scanf( "%d", &g_price[ j ]);
        }

        result = helper( product, dollar, buy );
        printf( "%lld\n", result );
    }
    return 0;
}

int helper( long long int product, long long int dollar, long long int buy )
{
    int result = 0;
    // sort price from smaller to larger
    qsort( g_price, product, sizeof( g_price[ 0 ] ), cmpfunc );

    // initialize DP
    memset( DP, 0, ( product + 1 ) * sizeof( DP[ 0 ] ) );

    // assume that you have unlimited budget, we will do with your budget latter
    // prefix sum
    // noted that DP record from 1 not 0
    for( int i = 1; i <= product; i++ ) {
        // you pick ( i - 1 ) ~ ( i - buy ) staff, this will only cost you g_price[ i - 1 ]
        DP[ i ] = g_price[ i - 1 ]; 

        if( i >= buy ) {
            // add buy step before DP
            // noted that you can copy this pattern to the end of goods
            DP[ i ] += DP[ i - buy ];
        }
        // before buy step
        // you can only buy the goods with sum of their price
        else {
            DP[ i ] += DP[ i - 1 ];
        }
    }

    // find max result under your budget
    for( int i = 1; i <= product; i++ ) {
        if( dollar >= DP[ i ] ) {
            result = i;
        }
    }
    return result;
}