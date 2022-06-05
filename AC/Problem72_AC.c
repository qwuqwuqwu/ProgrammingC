#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} Point;

Point * ones_vec_1(int length)
{
    /// Please implement
    /// 1. Malloc memory for point array
    /// 2. Read values into point array
    /// 3. Return the address of the first element in the array
    // 1.
    Point *p = ( Point * )malloc( sizeof( Point ) * length );

    // 2.
    for( int i = 0; i < length; i++ ) {
        scanf( "%d%d", &p[ i ].x, &p[ i ].y );
    }

    // 3.
    return p;
}

float compute_distance(Point* a, int first_id, int second_id)
{
    float ans;
    // Point first_p, second_p;

    /// Please implement
    /// 1. Get two point from function argument
    /// 2. Compute 2D distance and return ans

    // 1.
    Point first_p = { a[ first_id ].x, a[ first_id ].y };
    Point second_p = { a[ second_id ].x, a[ second_id ].y };

    // 
    ans = sqrt( ( second_p.x - first_p.x ) * ( second_p.x - first_p.x ) +
                ( second_p.y - first_p.y ) * ( second_p.y - first_p.y ) );

    return ans;
}

int g_nM;
int g_nN;
int main( void ) {
    scanf( "%d", &g_nM );
    Point *pP = ones_vec_1( g_nM );

    scanf( "%d", &g_nN );
    int nFirstIdx = -1;
    int nSecondidx = -1;
    float dis = 0.0;
    for( int i = 0; i < g_nN; i++ ) {
        scanf( "%d%d", &nFirstIdx, &nSecondidx );
        dis = compute_distance( pP, nFirstIdx, nSecondidx );
        printf( "%.3f\n", dis );
    }
}