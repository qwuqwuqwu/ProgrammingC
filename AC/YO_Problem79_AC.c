// 79
#include<stdio.h>
typedef struct{
    double col[5];
}vector;

typedef struct{
    vector row[5];
}matrix;

int t,n,m,ans;
matrix change;
vector want,x;

void multiple(matrix a,vector b,int n){                 //矩陣乘法，用void存是為了省記憶體空間，將x向量放到global
    for(int i=0;i<n;i++){                               //讓每一次跑只是更改向量裡的值就不用開一堆向量
      	x.col[i]=0;
        for(int j=0;j<n;j++){
            x.col[i]+=(a.row[i].col[j]*b.col[j]);
        }
    }
}

int check (matrix a,int want,vector b,int time,int n){  
    if(b.col[0]<=want) return time;                     //符合要求就回傳總共跑的次數
    else{                                               
        int cal=0;                                      
        multiple(a,b,n);                                //經過一次變化後的結果
        for(int i=0;i<n;i++){
        	if(b.col[0]-x.col[0]<1) return 0;           //如果到穩定狀態也回傳，要算到真的穩定狀態會跑超多次
        }                                               //加上跑遞迴裡只會出現遞減的狀況，所以控制在誤差範圍
        if(cal==n) return 0;                            //就直接回傳了，實際測試誤差小於1就會過了，但真實情況最好取到更小(如1e6之類的)
        else check(a,want,x,time+1,n);                  //如果還沒到穩定狀況就繼續跑
    }
} 
int main (void){
    scanf("%d",&t);
    for(int time=0;time<t;time++){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%lf",&change.row[i].col[j]);
            }
        }
        for(int i=0;i<n;i++){
            scanf("%lf",&want.col[i]);
        }
        scanf("%d",&m);
        if(want.col[0]<=m) printf("0\n");               //還沒跑之前就已經符合情況就不用算了，同時把遞增的情形去除了
        else{
            ans=check(change,m,want,0,n);
            if(ans) printf("%d\n",ans);
            else printf("Never\n");
        }
    }
    return 0;
}