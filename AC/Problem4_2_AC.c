#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char g_cInput[ 2001 ] = "\0";
int g_nLength = 0;

// pE - Exquisite Substrings
bool CheckLeftRight_Odd( const int nCenter, const int nArmLength )
{
    if( ( nCenter + nArmLength ) > g_nLength || ( nCenter - nArmLength ) < 1 ) {
        return false;
    }

    if( g_cInput[ nCenter + nArmLength ] == g_cInput[ nCenter - nArmLength ] ) {
        return true;
    }
    return false;
}

bool CheckLeftRight_Even( const int nCenterLeft, const int nArmLength )
{
    if( ( nCenterLeft + 1 + nArmLength ) > g_nLength || ( nCenterLeft - nArmLength ) < 1 ) {
        return false;
    }

    if( g_cInput[ nCenterLeft + 1 + nArmLength ] == g_cInput[ nCenterLeft - nArmLength ] ) {
        return true;
    }
    return false;
}

int main( void )
{
    char *pTempInput = &g_cInput[ 1 ];
    int nLength = 0;
    int i = 0;
    int j = 0;
    int tempi = 0;
    int tempj = 0;
    bool bExquisite = false;
    unsigned int nCount = 0;
    
    while( scanf( "%s", pTempInput ) != EOF ) {
        bExquisite = false;
        g_nLength = strlen( pTempInput );
        nCount = 0;

        bool bTest = CheckLeftRight_Odd( 3, 1 );
        // odd form
        for( i = 1; i <= g_nLength; i++ ) {
            j = 1;
            while( CheckLeftRight_Odd( i, j ) == true ) {
                // ++
                j++;
                nCount++;
            }
        }
        // even form
        for( i = 1; i <= g_nLength; i++ ) {
            j = 0;
            while( CheckLeftRight_Even( i, j ) == true ) {
                // ++
                j++;
                nCount++;
            }
        }
        printf( "%u\n", nCount );
        nCount = 0;
        memset( g_cInput, 0, sizeof( char ) * 2001 );
    }
    return 0;
}