#include <stdio.h>
#include <math.h>
// carrying hot pot

int main( void ) {
    double x;
    double y;
    int z; // 0 <= z <= 6
    double Base;

    scanf( "%lf%lf%d", &x, &y, &z );

    double mul = x * y;

    Base = pow( 10.0, z );
    mul *= Base;
    mul = floor( mul );
    mul /= Base;
    printf( "%.*lf\n", z, mul );
    
    return 0;/*  */
}