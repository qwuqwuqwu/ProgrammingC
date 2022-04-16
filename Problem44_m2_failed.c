#include <stdio.h>
#define MAX 1e9+7

int a[5005];

int main(){
	int t;
    scanf("%d", &t);

	while(t--){

	    int n,m,k;
        scanf("%d%d%d", &n, &m, &k);

	    for(int i=0;i<n;i++)
            scanf("%d", &a[ i ]);

            
	    int ans = -1;
	    if(k >= m-1){
            for(int i=0;i<m;i++){
                if(a[i] > ans)
                    ans = a[i];
                if(a[n-i-1] > ans)
                    ans = a[n-i-1];
            }
	    }
	    else{
	        for(int i=0;i<=k;i++){ //l = i, r = n-(k-i)-1
	            int now_ans = MAX;
	            for(int j=0;j<m-k;j++){
                    int l = i+j;//前面i+j個被選了
                    int r = n-m+i+j;//後面m-i-j-1個被選了
	                int tmp;
                    if(a[l] > a[r])
                        tmp = a[l];
                    else
                        tmp = a[r];
                    if(tmp < now_ans)
                        now_ans = tmp;
                    //cout << "i:" << i << " j:" << j << " tmp:" << tmp << " l:" << l << " r:" << r << '\n';
	            }
	            if(now_ans > ans)
	                ans = now_ans;
	        }
	    }
        printf("%d\n", ans);
	    //cout << ans << '\n';
	}
}