#include <stdio.h>
#include "string.h"

#define MAX_LENOFBIGSTRING  ( 1000 )
#define MAX_LENOFSUBSTRING  ( 1000 )

char g_BigString[ MAX_LENOFBIGSTRING + 1 ];
char g_SubString[ MAX_LENOFSUBSTRING + 1 ];
int g_nSubStringCount[ MAX_LENOFBIGSTRING + 1 ];

void TraverseAll( void )
{
    int nLenBigString = strlen( g_BigString );
    int nLenSubString = strlen( g_SubString );
    int nMaxBigStringIdx = nLenBigString - nLenSubString;
    int i = 0;

    for( i = 0; i < nLenSubString - 1; i++ ) {
        g_nSubStringCount[ i ] = 0;
    }

    for( i = nLenSubString - 1; i < nLenBigString; i++ ) {
        // use strncmp rather than strcmp
        if( strncmp( &g_BigString[ i - nLenSubString + 1 ], g_SubString, nLenSubString ) == 0 ) {
            g_nSubStringCount[ i ] = g_nSubStringCount[ i - 1 ] + 1;
        }
        else {
            g_nSubStringCount[ i ] = g_nSubStringCount[ i - 1 ];
        }
    }
}

int Algorithm( int nL, int nR )
{
    int nLenSubString = strlen( g_SubString );
    nL = nL - 1 + nLenSubString - 1 - 1; // 1 for ID to index, 1 for Len - 1, 1 for last presum
    nR = nR - 1; // 1 for ID to index

    if( nL > nR ) {
        return 0;
    }

    return ( g_nSubStringCount[ nR ] - g_nSubStringCount[ nL ] );
}

int main( void )
{
    int nRequestCount = 0;
    scanf( "%s%s", g_BigString, g_SubString );
    scanf( "%d", &nRequestCount );
    TraverseAll();

    for( int i = 0; i < nRequestCount; i++ ) {
        int nL = 0;
        int nR = 0;
        int nAns = 0;
        scanf( "%d%d", &nL, &nR );
        nAns = Algorithm( nL, nR );
        printf( "%d\n", nAns );
    }
    return 0;
}


// #include <stdio.h>
// #include<string.h>
// char S[1005];
// char sub[1005];
// int sum[1005]={0};
// int main(){
//   scanf("%s",S);
//   scanf("%s",sub);
//   int t;
//   scanf("%d",&t);
//   for(int i =0;i<=strlen(S)-strlen(sub);i++) {
//     for(int j=0;j<strlen(sub);j++){
//       if (S[i+j]!=sub[j])
//         break;
//       else if(j == strlen(sub)-1)
//         sum[i]++;
//     }
//   }
//   while(t--){
//     int l,r;
//     scanf("%d%d",&l,&r);
//     l--;
//     r--;
//     int ans = 0;
//     while(l <= r-strlen(sub)+1){
//       if(sum[l]==1){
//         ans++;
//         l += strlen(sub);
//       }
//       else
//         l++;
//     }
//     printf("%d\n",ans);
//   }
// }