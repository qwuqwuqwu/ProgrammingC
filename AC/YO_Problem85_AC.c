// 85
#include<stdio.h>
#include<math.h>
int dec[32],want[32];
unsigned int ans[(int)1e5+10];
int n,k;
long long sum;
int main (void){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%u",&ans[i]);
        for(int j=0;j<32;j++){
            if((1<<j)&ans[i]) dec[j]+=1;
        }
    }
    for(int i=0;i<32;i++){
        if(dec[i]>=n/2) want[i]=1;
    }
    for(int i=0;i<32;i++){
        k+=want[i]*pow(2,i);
    }
    for(int i=0;i<n;i++){
        sum+=(ans[i]^k);
    }
    printf("%lld",sum);
    return 0;
}