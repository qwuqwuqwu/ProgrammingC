// Problem 73
#include <stdio.h>
#include <stdlib.h>
long long int max = 1000000007;
typedef struct {
    long long int M[2][2];
}matrix;

matrix Mul(matrix a, matrix b){
    matrix ans;
    ans.M[0][0] = ((( (a.M[0][0] % max) * (b.M[0][0] % max) ) % max) + (( (a.M[0][1] % max) * (b.M[1][0] % max) ) % max)) % max;
    ans.M[0][1] = ((( (a.M[0][0] % max) * (b.M[0][1] % max) ) % max) + (( (a.M[0][1] % max) * (b.M[1][1] % max) ) % max)) % max;
    ans.M[1][0] = ((( (a.M[1][0] % max) * (b.M[0][0] % max) ) % max) + (( (a.M[1][1] % max) * (b.M[1][0] % max) ) % max)) % max;
    ans.M[1][1] = ((( (a.M[1][0] % max) * (b.M[0][1] % max) ) % max) + (( (a.M[1][1] % max) * (b.M[1][1] % max) ) % max)) % max;
    return ans;
}

matrix create(){
    matrix X;
    X.M[0][0] = 1;
    X.M[0][1] = 1;
    X.M[1][0] = 1;
    X.M[1][1] = 0;
    return X;
}

matrix fb(long long int i){
    if(i==1)
        return create();
    matrix now = fb(i/2);
    if(i%2 == 0)
        return Mul(now, now);
    return Mul(Mul(now, now), fb(1));
}

int main(){
    //initialize
    long long int i;
    while(scanf("%lld", &i) != EOF){
        matrix  fx;
        if(i == 1 || i==2)
            printf("%lld\n", 1);
        else {
            fx = fb(i - 2);
            long long int ans;
            ans = (fx.M[0][0] + fx.M[0][1]) % max;
            printf("%lld\n", ans);
        }
    }

}