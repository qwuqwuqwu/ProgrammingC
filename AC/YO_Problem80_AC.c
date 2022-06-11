#include<stdio.h>
#include<stdlib.h>
typedef struct{
    char name[23];
    int a,b;
    int diff;
}Data;
Data factory[503];
int n,x,y,ans,best,tmp;

int cmp_diff(const void *x,const void *y){                              //差值由大而小
    return ((Data*)y)->diff-((Data*)x)->diff;
}

int cmp_a(const void *x,const void *y){                                 //a由大而小
    return ((Data*)y)->a-((Data*)x)->a;
}

int cmp_b(const void *x,const void *y){                                 //b由小而大
    return ((Data*)x)->b-((Data*)y)->b;
}

int cmp_name(const void *x,const void *y){                              //比較名字(依辭典方式排列)
    return (strcmp(((Data*)x)->name,((Data*)y)->name));
}

int count(int k){                                                       //用暴力蒐尋找哪一種產值最大
    int total=0;                                                        //紀錄產值
    qsort(factory,k,sizeof(Data),cmp_a);                                //把前面k個分成一組，然後對a排序
    qsort(factory+k,n-k,sizeof(Data),cmp_b);                            //把後面k個分成一組，然後對b排序
    for(int i=0;i<x;i++) total+=factory[i].a;                           //a最大的幾種加起來
    for(int i=n-y;i<n;i++) total+=factory[i].b;                         //b最大的幾種加起來
    return total;
}
int main (void){
    scanf("%d %d %d",&n,&x,&y);
    for(int i=0;i<n;i++){
        scanf("%s %d %d",factory[i].name,&factory[i].a,&factory[i].b);
        factory[i].diff=factory[i].a-factory[i].b;
    }
    for(int i=0;i<n;i++){
        qsort(factory,n,sizeof(Data),cmp_diff);                         //每次排都讓差值由大到小排(取a比較划算的放前面)
        tmp=count(i);                                                   //算算看用i當分界線的結果(因為差值大的不代表實際的值是大的)
        if(best<tmp){                                                   //比較大就存下來
            best=tmp;
            ans=i;
        }
    }
    qsort(factory,n,sizeof(Data),cmp_diff);                             //都算完了，重製後準備復原最佳情況
    qsort(factory,ans,sizeof(Data),cmp_a);                              //復原a
    qsort(factory+ans,n-ans,sizeof(Data),cmp_b);                        //復原b
    qsort(factory,x,sizeof(Data),cmp_name);                             //排好a的名字(依辭典順序)
    for(int i=0;i<x;i++){
        printf("%s\n",factory[i].name);                                 
    }
    return 0;
}