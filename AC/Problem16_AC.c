// problem 16
// carrying hotpot

// method: printf %.*lf

#include <stdio.h>
#include <math.h>

int main( void ) {
    double x;
    double y;
    int z; // 0 <= z <= 6
    double Base;

    scanf( "%lf%lf%d", &x, &y, &z );

    double mul = x * y; // XXX.OOOAAA

    Base = pow( 10.0, z );
    mul *= Base; // XXXOOO.AAA
    mul = floor( mul ); // XXXOOO
    mul /= Base; // XXX.OOO

    printf( "%.*lf\n", z, mul );
    
    return 0;
}