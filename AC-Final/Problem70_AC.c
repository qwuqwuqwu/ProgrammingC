// Problem 70(56)
// N queens problem

// method: recursion

#include <stdio.h>

#define MAX ( 20 )

/* q[i] 記錄的是在第 i 列 (row) 出現的皇后，要擺在第幾行 (column) */
/* 譬如，q[] 的內容如果是 {2, 0, 3, 1}，表示四個皇后分別放在棋盤的 (0,2), (1,0), (2,3), (3,1) 四個位置 */

int q[ MAX ] = {0};
int g_nSize = 0;
int g_nCount = 0;

void place( int row );
int valid( int row, int col );

int main(void)
{
    scanf( "%d", &g_nSize );

    place( 0 );

    printf( "%d\n", g_nCount );
	return 0;
}

/*
判斷目前的狀況下，如果在 row, col 位置放入新的皇后
是否會和之前的皇后衝突
如果是合法的放置方式 return 1;
如果有衝突 return 0;
*/
int valid( int row, int col )
{
	int i;
    // check all rows before
	for( i = 0; i <= row - 1; i++ ) {
        // q[ i ] == col => same col
        // row - i == col - q[ i ] => \
        // row - i == q[ i ] - col => /
		if( q[ i ] == col || row - i == col - q[ i ] || row - i == q[ i ] - col ) {
			return 0;
		}
	}
	return 1;
}

void place( int row )
{
	int j;
	if( row == g_nSize ) {
		g_nCount++;	// end recursion
	}
    else {
		// try to place each col
		for( j = 0; j < g_nSize; j++ ) {
			if( valid( row, j ) ) {
				q[ row ] = j;
				place( row + 1 ); // try next row
			}
		}
	}
}