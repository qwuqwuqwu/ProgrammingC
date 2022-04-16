#include <stdio.h>

void test1( void )
{
    int i, j, k;
    scanf( "%d%d", &i, &j ); 

    for(; i; i--) { 
        for(k=j; k;k--) { 
            printf("*");
        }
        printf("\n");
    }
}

void test2()
{
    int i, j;
    scanf( "%d%d", &i, &j );

    for(; i; i--) { 
        for(; j;) { 
            printf("*");
        }
        printf("\n");
    }
}

int main(void)
{
    test2();     

    return 0;
}