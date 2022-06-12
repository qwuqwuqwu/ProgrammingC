#include <stdio.h>
#include <stdlib.h>

// int main( void ) {
//     int* a = malloc(sizeof(int));
//     int* b = a;
//     *a = 123;

//     free(a);
//     a = NULL;
//     printf( "%d\n", *b );

//     // b is a dangling pointer now !
//     // no error is produced! so be careful
//     return 0;
// }

int main(void)
{
    // string literal
    char*  str1[] = {"piece", "of", "cake"};

    // char array
    char str2[] [8] = {"piece", "of", "cake"};
 
    int i, j;

    printf( "str1\n" );
    for (i=0; i<3; i++) {
        for (j=0; j<8; j++)
            printf("(%c, %d) ", str1[i][j], str1[i][j]);
        printf("\n");
    }


    printf( "str2\n" );
    for (i=0; i<3; i++) {
        for (j=0; j<8; j++)
            printf("%c", str2[i][j]);
        printf("\n");
    }

    return 0; 
}
