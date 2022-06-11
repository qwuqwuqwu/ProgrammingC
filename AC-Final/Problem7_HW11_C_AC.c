// Problem 7
// Airplane Shooter
// HW11_C
#include <stdio.h>
#include <stdlib.h>

#define MAX ( 100000 )
// #define MAX ( 10 )

struct Point {
    int nIndex;
    int nAdminLevel;
    int nLicenseNum;
};

struct Point g_Points[ MAX ];

int comp( const void *lhs, const void *rhs )
{
    struct Point LHS = *( struct Point * )lhs;
    struct Point RHS = *( struct Point * )rhs;
    if( LHS.nAdminLevel < RHS.nAdminLevel ) {
        return -1;
    }
    else if( LHS.nAdminLevel > RHS.nAdminLevel ){
        return 1;
    }
    else {
        if( LHS.nLicenseNum < RHS.nLicenseNum ) {
            return -1;
        }
        else if( LHS.nLicenseNum > RHS.nLicenseNum ) {
            return 1;
        }
        else {
            if( LHS.nIndex < RHS.nIndex ) {
                return -1;
            }
            else if( LHS.nIndex > RHS.nIndex ) {
                return 1;
            }
            else {
                return 0;
            }
        }
    }
}

int main( void )
{
    int nN = 0;
    scanf( "%d", &nN );

    for( int i = 0; i < nN; i++ ) {
        scanf( "%d%d", &g_Points[ i ].nAdminLevel, &g_Points[ i ].nLicenseNum );
        g_Points[ i ].nIndex = i + 1;
    }

    // sort
    qsort( g_Points, nN, sizeof( struct Point ), comp );

    for( int i = 0; i < nN - 1; i++ ) {
        printf( "%d ", g_Points[ i ].nIndex );
    }
    printf( "%d\n", g_Points[ nN - 1 ].nIndex );
    return 0;
}