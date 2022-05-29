// Problem 33
// HaSaKi~
#include<stdio.h>
#include<string.h>
char S[1200];
char s[1200];
long long int c[2400]; //用來存前綴和
long long int d[2400]; //紀錄字串相同的部分
#define max(a, b) ((a) > (b)? (a): (b))
int main(){
    long long int i=0,count=0,slen,Slen,counter=0;
    char a,b;
    long long int t,l,r,m=0;
    while((a=getchar())!='\n'){
            S[i]=a;
            i++;
    }
    i=0;
    while((b=getchar())!='\n'){
            s[i]=b;
            i++;
    }
    slen = strlen(s);
    Slen = strlen(S);
    for(long long int i=0;i<Slen;i++){
        counter=0;
        count=0;
        for(long long int j=0,k=i;j<slen;j++,k++){
            if(s[j]==S[k]) count++;
            if(count==slen){
                counter++;
                // 如果這幾項都符合s 那就把這幾項記起來
                for(int m=k;m>k-slen+1;m--){
                    d[m]++;
                }
            }
        }
        c[i+slen]=c[i+slen-1]+counter; //前綴和
    }
#if 0
    printf("\nc:\n");
    for (size_t i = 0; i <= Slen; ++i) {
        printf("%lld ", c[i]);
    }
    printf("\n");
    printf("d:\n");
    for (size_t i = 0; i <= Slen; ++i) {
        printf("%lld ", d[i]);
    }
    printf("\n");
#endif

    scanf("%lld",&t);
    while(t--){
        scanf("%lld %lld",&l,&r);
        printf("%lld\n", max(0, c[r]-c[l-1]-d[l-1]));
        continue;
        //若所選的l和l前面那項都是被記錄了兩次，代表前綴合再扣時要多扣2
        if(d[l]==2&&d[l-1]==2){
            printf("%lld\n",c[r]-c[l-1]-2);
        }
        //若所選的l有被記錄過，代表前綴合再扣的時候要多扣1
        else if(d[l-1]==1 || d[l-1]==2){
            printf("%lld\n",c[r]-c[l-1]-1);
        }
        else{
            printf("%lld\n",c[r]-c[l-1]);
        }

    }
    return 0;
}