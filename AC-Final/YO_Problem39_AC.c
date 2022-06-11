// Problem 39
// Too Many Things to Buy
#include <stdio.h>
#include <stdlib.h>

#define MAX ( 100000 )

typedef struct price {
    int day1;
    int day2;
} price_t;

price_t price[ MAX ];

int diff[ MAX ];

int day1_cheap;
long long result;
int cmpfunc(const void *a, const void * b)
{
   return *(int*)a - *(int*)b;
}

int main(void)
{
    int num, at_least_buy;
    scanf( "%d%d", &num, &at_least_buy );

    // scan day1 price
    for( int i = 0; i < num; i++ ) {
        scanf( "%d", &price[ i ].day1 );
    }

    // scan day2 price
    for( int i = 0; i < num; i++ ) {
        scanf( "%d", &price[ i ].day2 );

        diff[ i ] = price[ i ].day1 - price[ i ].day2;
        if( diff[ i ] < 0 ) {
            day1_cheap++;
            result += price[ i ].day1;
        }
        else {
            result += price[ i ].day2;
        }
    }

    // you should pick some items in day1 although they are more expensive in day1
    // so you should pick less expensive items first
    if( day1_cheap < at_least_buy ) {
        qsort( diff, num, sizeof( int ), cmpfunc );
        for( int i = day1_cheap; i < at_least_buy; i++ ) {
            result += diff[ i ]; // these itmes you buy them on day1 although they are cheaper on day2
            // day2 price are already in result, so you just need to add diff(>0)
        }
    }
    printf("%lld\n", result);
    return 0;
}