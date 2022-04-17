// problem 23
// too many watermelons

// method: array to store old info
#include <stdio.h>
#include <stdbool.h>

#define MAX ( 200000 )

int g_A[ MAX ];
int g_B[ MAX ];
bool g_Buffer[ MAX + 1 ];

int main( void ) 
{
    int nN = 0;
    int nSearchIdx = 0;
    int nAdvanceCount = 0;
    scanf( "%d", &nN );
    for( int i = 0; i < nN; i++ ) {
        scanf( "%d", &g_A[ i ] );
    }
    for( int i = 0; i < nN; i++ ) {
        scanf( "%d", &g_B[ i ] );
    }

    for( int i = 0; i < nN; i++ ) {
        // find g_B[ i ]

        nAdvanceCount = 1;
        // search in Buffer first
        if( g_Buffer[ g_B[ i ] ] == true ) {
            if( i == nN - 1 ) {
                printf( "0" );
            }
            else {
                printf( "0 " );
            }
        }
        // not in the buffer, then it is still in A
        else {
            while( true ) {
                if( nSearchIdx == nN ) {
                    break;
                }
                // hit
                if( g_B[ i ] == g_A[ nSearchIdx ] ) {
                    nSearchIdx++;
                    if( i == nN - 1 ) {
                        printf( "%d", nAdvanceCount );
                    }
                    else {
                        printf( "%d ", nAdvanceCount );
                    }
                    break;
                }
                // not hit, then store in buffer
                else {
                    g_Buffer[ g_A[ nSearchIdx ] ] = true;
                    nSearchIdx++;
                    nAdvanceCount++;
                }
            }
        }
    }
    printf( "\n" );
    return 0;
}