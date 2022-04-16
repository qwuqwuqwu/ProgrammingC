#include <stdio.h>
#include <stdlib.h>
#define MAXN 1000000

int A[MAXN], buffer[MAXN];
void merge(int starta, int lena, int startb, int lenb)
// merge A[starta], A[startb] into buffer
{
    int i = 0, j = 0, k = 0;
    while( i < lena && j < lenb ) {
        if( A[ starta + i ] < A[ startb + j ] ) {
            buffer[ k++ ] = A[ starta + i++ ];
        }
        else {
            buffer[ k++ ] = A[ startb + j++ ];
        }
    }
    while( i < lena ) {
        buffer[ k++ ] = A[ starta + i++ ];
    }
    while( j < lenb ) {
        buffer[ k++ ] = A[ startb + j++ ];
    }
}

void merge_sort(int left, int right)
{
    int i, mid;
    if ( left >= right ) return; 
    mid = left + ( right - left ) / 2;   
    merge_sort( left, mid ); // A[left...mid] is sorted
    merge_sort( mid + 1, right ); // A[mid+1...right] is sorted

    merge( left, mid - left + 1, mid + 1, right - mid ); 
    // copy back buffer to A
    for( i = 0; i < right - left + 1; i++ ){  	
        A[ left + i ] = buffer[ i ];
    }
}

int main(){
    int n, i;
    /*
    scanf("%d", &n);
    for(i=0; i<n; i++){
      scanf("%d", &A[i]);
    }*/
    n = 500000;
    for (i=0; i<n; i++) {
      A[i] = rand()%n;
    }    
    printf("Before sorting: ");
    for (i=10000; i<10010; ++i) {
      printf("%d ", A[i]);
    }

    merge_sort(0, n-1);
    printf("\nAfter sorting: ");
    for (i=10000; i<10010; ++i) {
      printf("%d ", A[i]);
    }

    for (i=1; i<n; ++i) {
      if (A[i-1]>A[i]) {
        printf("\nWrong!\n");
      }
    }
    printf("\nCorrect.\n");

    return 0;
}