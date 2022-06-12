#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX ( 500 )

int g_nN;
int g_nX;
int g_nY;

typedef struct _Factory {
    int nAProfit;
    int nBProfit;
    char cName[ 21 ];
} Factory;

typedef struct _Pro {
    int nProfit;
    int nID;
    char cName[ 21 ];
} Pro;

Factory g_F[ MAX ];
Pro g_A[ MAX ];
Pro g_B[ MAX ];

int CompName( const void *plhs, const void *prhs )
// B from small to big
{
    Factory *pLHS = ( Factory * )plhs;
    Factory *pRHS = ( Factory * )prhs;

    return strcmp( pLHS->cName, pRHS->cName );
}

int CompB( const void *plhs, const void *prhs )
// B from small to big
{
    Factory *pLHS = ( Factory * )plhs;
    Factory *pRHS = ( Factory * )prhs;

    if( pLHS->nBProfit < pRHS->nBProfit ) {
        return -1;
    }
    else if( pLHS->nBProfit > pRHS->nBProfit ) {
        return 1;
    }
    return 0;
}

int CompA( const void *plhs, const void *prhs )
// A from big to small
{
    Factory *pLHS = ( Factory * )plhs;
    Factory *pRHS = ( Factory * )prhs;

    if( pLHS->nAProfit > pRHS->nAProfit ) {
        return -1;
    }
    else if( pLHS->nAProfit < pRHS->nAProfit ) {
        return 1;
    }
    return 0;
}

int CompDiff( const void *plhs, const void *prhs )
{
    Factory *pLHS = ( Factory * )plhs;
    Factory *pRHS = ( Factory * )prhs; 
    int L = pLHS->nAProfit - pLHS->nBProfit;
    int R = pRHS->nAProfit - pRHS->nBProfit;

    if( L > R ) {
        return -1;
    }
    else if( L < R ) {
        return 1;
    }
    return 0;
}

int main( void )
{
    // get data
    scanf( "%d%d%d", &g_nN, &g_nX, &g_nY );
    for( int i = 0; i < g_nN; i++ ) {
        scanf( "%s%d%d", g_F[ i ].cName, &g_F[ i ].nAProfit, &g_F[ i ].nBProfit );
    }

    // pick k
    int nMaxProfit = 0;
    int nRecordK = 0;
    // use k diff larger as A
    // pick number x of A
    for( int k = 1; k < g_nN; k++ ) {
        // sort all n ( reset )
        qsort( g_F, g_nN, sizeof( Factory ), CompDiff );

        qsort( g_F, k, sizeof( Factory ), CompA );
        qsort( g_F + k, g_nN - k, sizeof( Factory ), CompB );
        // pick x, y
        int nProfit = 0;
        for( int i = 0; i < g_nX; i++ ) {
            nProfit += g_F[ i ].nAProfit;
        }
        for( int j = 0; j < g_nY; j++ ) {
            nProfit += g_F[ g_nN - 1 - j ].nBProfit;
        }
        if( nProfit > nMaxProfit ) {
            nMaxProfit = nProfit;
            nRecordK = k;
        }
    }

    // reproduce
    qsort( g_F, g_nN, sizeof( Factory ), CompDiff );
    qsort( g_F, nRecordK, sizeof( Factory ), CompA );
    qsort( g_F + nRecordK, g_nN - nRecordK, sizeof( Factory ), CompB );
    qsort( g_F, g_nX, sizeof( Factory ), CompName );
    for( int i = 0; i < g_nX; i++ ) {
        printf( "%s\n", g_F[ i ].cName );
    }

    return 0;
}