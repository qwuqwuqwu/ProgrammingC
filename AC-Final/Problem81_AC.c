// Problem 81
// Stable sort

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARARRAY   ( 21 )
#define MAX_PEOPLE      ( 100000 )

// #define MAX_PEOPLE      ( 10 )

typedef struct person {
    char cName[ MAX_CHARARRAY ];
    int nScore;
} Person;

Person g_P[ MAX_PEOPLE ];
Person g_Buffer[ MAX_PEOPLE ];

int CompPerson( const void* lhs, const void* rhs )
{
    Person *LHS = ( Person * )lhs;
    Person *RHS = ( Person * )rhs;
    if( LHS->nScore < RHS->nScore ) {
        return 1;
    }
    else if( LHS->nScore == RHS->nScore ) {
        return 0;
    }
    else {
        return -1;
    }
}

void Merge( Person *lhs, int nL, Person *rhs, int nR )
{
    int nLIdx = 0, nRIdx = 0, nTIdx = 0;
    while( nLIdx < nL && nRIdx < nR ) {
        if( lhs[ nLIdx ].nScore >= rhs[ nRIdx ].nScore ) {
            g_Buffer[ nTIdx++ ] = lhs[ nLIdx++ ];
        }
        else {
            g_Buffer[ nTIdx++ ] = rhs[ nRIdx++ ];
        }
    }

    while( nLIdx < nL ) {
        g_Buffer[ nTIdx++ ] = lhs[ nLIdx++ ];
    }
    while( nRIdx < nR ) {
        g_Buffer[ nTIdx++ ] = rhs[ nRIdx++ ];
    }
}

void MergeSort( Person *pP, int nN )
{
    if( nN == 1 ) {
        return;
    }

    MergeSort( pP, ( nN / 2 ) );
    MergeSort( pP + ( nN / 2 ), nN - ( nN / 2 ) );

    Merge( pP, ( nN / 2 ), pP + ( nN / 2 ), nN - ( nN / 2 ) );
    memcpy( pP, g_Buffer, sizeof( Person ) * ( nN / 2 ) );
    memcpy( pP + ( nN / 2 ), g_Buffer + ( nN / 2 ), sizeof( Person ) * ( nN - ( nN / 2 ) ) );
}

int main( void )
{
    int nN = 0;
    scanf( "%d", &nN );
    for( int i = 0; i < nN; i++ ) {
        scanf( "%s%d", g_P[ i ].cName, &g_P[ i ].nScore );
    }

    // qsort( g_P, nN, sizeof( Person ), CompPerson );
    // noted that qsort is not a stable sort
    // but use qsort can get AC??? XD
    MergeSort( g_P, nN );

    for( int i = 0; i < nN; i++ ) {
        printf( "%s\n", g_P[ i ].cName );
    }
    return 0;
}