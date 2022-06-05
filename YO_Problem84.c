// 84
#include<stdio.h>
int point[1001],t,n,m,first,second;
int edge[1001][1001];
int cal;

void check(int now,int group){
    point[now]=group;                       //分組
    for(int i=1;i<=n;i++){
        if(edge[now][i]==1){                //如果剛好點now跟點i只有一條連接
            if(point[i]==group){            //還有點i已經被分過組了，還剛好是同一組那就不是二分圖
                cal++;                      //紀錄起來，有找到不符合的
                break;                      //確定不是就不用做了
            }else if(point[i]==0){          //還沒走過這點
                if(group==1) check(i,2);    //新點會是另一組
                else check(i,1);
            }
        }
    }
}

int main (void){
    scanf("%d",&t);
    for(int time=0;time<t;time++){
        scanf("%d %d",&n,&m);
        for(int i=0;i<m;i++){
            scanf("%d %d",&first,&second);
            edge[first][second]+=1;         //算兩點之間有多少個連接
            edge[second][first]+=1;         //算兩種可以確保上面now比i小所造成的誤判
        }
        check(1,1);                         //從點1來看，然後點1是第1組
        if(cal!=0) printf("No\n");          //有不對的
        else printf("Yes\n");
        for(int i=1;i<=n;i++){              //歸零
            point[i]=0;
            for(int j=1;j<=n;j++){
                edge[i][j]=0;
            }
        }
        cal=0;
    }
    return 0;
}