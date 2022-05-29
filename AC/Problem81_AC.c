// Problem 81
// Stable sort

#include <stdio.h>
#include <stdlib.h>

#define MAX_CHARARRAY   ( 21 )
#define MAX_PEOPLE      ( 100000 )

// #define MAX_PEOPLE      ( 10 )

typedef struct person {
    char cName[ MAX_CHARARRAY ];
    int nScore;
} Person;

Person g_P[ MAX_PEOPLE ];

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

int main( void )
{
    int nN = 0;
    scanf( "%d", &nN );
    for( int i = 0; i < nN; i++ ) {
        scanf( "%s%d", g_P[ i ].cName, &g_P[ i ].nScore );
    }

    qsort( g_P, nN, sizeof( Person ), CompPerson );

    for( int i = 0; i < nN; i++ ) {
        printf( "%s\n", g_P[ i ].cName );
    }
    return 0;
}