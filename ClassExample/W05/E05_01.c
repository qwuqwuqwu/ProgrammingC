// E05_01
// my own scanf( "%d" )

#include <stdio.h>
#include <ctype.h>
#include <math.h>

int SCANF_D( void )
{
    char c;
    int nInt = 0;   
    while( ( c = getchar() ) && isdigit( c ) ) {
        nInt = nInt * 10 + ( int )( c - '0' );
    }
    
    return nInt;
}

int SCANF_X( void )
{
    char c;
    int nInt = 0;   
    while( ( c = getchar() ) && isxdigit( c ) ) {
        // 0~9
        if( isdigit( c ) ) {
            nInt = nInt * 16 + ( int )( c - '0' );    
        }
        // ABCDEF
        else {
            nInt = nInt * 16 + ( int )( toupper( c ) - 'A' + 10 );
        }
    }
    
    return nInt;
}

void PRINTF_D( int nInt )
{
    printf( "My PRINTF_D => \n" );
    // get length
    int nTemp = nInt;
    int nLen = 1;
    while( ( nTemp / 10 ) != 0 ) {
        nLen++;
        nTemp /= 10;
    }
    //printf("Len = %d\n", nLen);
    int nLenLen = nLen;
    
    for( int i = 0; i < nLenLen; i++ ) {
        if( nInt == 0 ) {
            putchar( '0' );
        }
        else {
            putchar( ( nInt / ( ( int )pow( 10, ( nLen - 1 ) ) ) ) + '0' );
        }
        
        nInt %= ( ( int )pow( 10, ( nLen - 1 ) ) );
        //printf("nInt = %d\n", nInt);
        nLen--;
    }
}

void PRINTF_X( int nInt )
{
    printf( "My PRINTF_X => \n" );
    // get length
    int nTemp = nInt;
    int nLen = 1;
    while( ( nTemp / 16 ) != 0 ) {
        nLen++;
        nTemp /= 16;
    }
    //printf("Len = %d\n", nLen);
    int nLenLen = nLen;
    
    int nD;
    for( int i = 0; i < nLenLen; i++ ) {
        if( nInt == 0 ) {
            putchar( '0' );
        }
        else {
            nD = ( nInt / ( ( int )pow( 16, ( nLen - 1 ) ) ) );
            if( nD >= 10 ) {
                putchar( nD - 10 + 'A' );
            }
            else {
                putchar( nD + '0' );
            }
        }
        
        nInt %= ( ( int )pow( 16, ( nLen - 1 ) ) );
        //printf("nInt = %d\n", nInt);
        nLen--;
    }
}

int main()
{
    // scanf_d, printf_d
    int a = SCANF_D();
    // printf( "Your inputer is %d\n", a );
    PRINTF_D( a );
    putchar('\n');
    
    // scanf_x, printf_x
    int b = SCANF_X();
    printf( "Yout input integer is %d\n", b );
    PRINTF_X( b );
    putchar('\n');
    return 0;
}