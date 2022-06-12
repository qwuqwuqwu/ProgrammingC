#include <stdio.h>

#define ROWS ( 3 )
#define COLS ( 4 )

//int sum2d( int a[][COLS], int rows )
int sum2d( int ( *a )[COLS], int rows ) // 也可以用這種寫法, 表示a為一個指標變數, 指向int[ COLS ]
{
   int r, c;
   int total = 0;

    for( r = 0; r < rows; r++ ) {
        for( c = 0; c < COLS; c++ ) {
            total += a[ r ][ c ];
        }
    }

   return total;
}

int main(void)
{
   int z[4]   [2] = {{1,2}, {3,4}, {5,6}, {7,8}};
   
/*
 a[i] ⟺ *(a+i)
&a[i] ⟺ (a+i)
*/

   printf("       z: %p\n", z);
   printf("   &z[0]: %p\n", &z[0]); // &z[0] => z+0 => z
   printf("    z[0]: %p\n", z[0]);  // (z[0]+0) => & z[0][0]
   printf("&z[0][0]: %p\n", &z[0][0]); 
   printf(" z[0][0]: %d\n", z[0][0]);
   printf("\n"); 
   printf("     z+1: %p\n", z+1); 
   printf("   &z[1]: %p\n", &z[1]); // &z[1] => z+1
   printf("  z[0]+1: %p\n", z[0]+1); // (z[0]+1) => &z[0][1]
   printf("&z[0][1]: %p\n", &z[0][1]); // address of 2
   printf("\n"); 
   printf("      *z: %p\n", *z);  // *z => *(z+0) => z[0] => &z[0][0]
   printf("    z[0]: %p\n", z[0]); // z[0] => &z[0][0]
   printf("   *z[0]: %d\n", *z[0]); // *z[0] => *(z[0] + 0) => z[0][0]
   printf(" z[0][0]: %d\n", z[0][0]); 
   printf("     **z: %d\n", **z); // **z => * *(z+0) => * z[0] => z[0][0]

   int ab[ 2 ] = { 100, 200 };
   printf( "ab = %p, &ab = %p\n", ab, &ab );

   //
   int ( *py )[ 2 ]; // py是一個指標變數, 他指向一個int array, 而int array的大小為2
   int *px[ 3 ]; // px為一個陣列, 大小為3, 陣列的內容為int*



   int arr2[ ROWS ][ COLS ] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };
   printf("Sum = %d\n", sum2d( arr2, ROWS ) );
   
   return 0; 
}