// problem 17
// money money

#include <stdio.h>

int main( void )
{
    int Jay;
    int Jolin;
    int JJ;

    int X; // Jay + Jolin
    int Y; // Jolin + JJ
    int Z; // Jay + JJ

    int Sum;
    scanf( "%d%d%d", &X, &Y, &Z );
    Sum = ( X + Y + Z ) / 2;
    Jay = Sum - Y;
    Jolin = Sum - Z;
    JJ = Sum - X;

    printf( "%d %d %d", Jay, Jolin, JJ ); // Jay, Jolin, JJ
    return 0;
}