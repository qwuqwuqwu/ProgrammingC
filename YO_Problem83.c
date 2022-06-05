// 83
Node* ptr;
Node* Create_List(Node* x, int y){
    Node *node;
    if(x==NULL){                            //第一個點
        x=(Node*)malloc(sizeof(Node));      //直接用他當第一格
        x->data=y;
        x->next=NULL;                       //不先幫他指下一個位子
        ptr=x;                              //記第一點在global
        return x;
    }else{                                  //之後的點
        node=(Node*)malloc(sizeof(Node));   //因為有起點了，所以開一個新的格子
        node->data=y;
        x->next=node;                       //原來那格要指到現在這格
        node->next=NULL;                    //不先幫他指下一個位子
        return node;
    }
}
Node* Reverse_List(Node* x){
    Node *first,*second,*tmp;
    if(ptr->next!=NULL){                    //有很多格才需要倒轉
        first=ptr;                          //先記第一格
        second=ptr->next;                   //記第二格
        first->next=NULL;                   //把第一格指的位子消掉(因為變成最後一格)
        tmp=second->next;                   //先存第二格指的位子(等等要從那裡繼續排)
        second->next=first;                 //把第二格指到第一格
        while(tmp!=NULL){                   //直到排到最後一格前
            first=second;                   //把要處理的格子放到first
            second=tmp;                     //原來在要處理的下一個存到second
            tmp=second->next;               //先把再下一格的位子存好(等等要從那裡繼續排)
            second->next=first;             //把下一格指到現在這格
        }
        return second;                      //回傳最尾巴的位子
    }else return x;                         //因為只有一格，所以直接回傳即可
    
}
   

void Print_List(Node*x){
    printf("%d",x->data);                   //先printf第一格
    if(x->next!=NULL){                      //確保有下一格(檢查是否指有一格)
        x=x->next;                          //因為已經排過原來的格子，所以跳到下一格
        while(x!=NULL){                     //直到最後一格前    
            printf("->%d",x->data);         
            x=x->next;                      //跑到下一格
        }
    }

}
void Free_List(Node*x){
    Node *ptr;                              
    while(x!=NULL){                         //到最後一格前
        ptr=x->next;                        //先跑到下一格，這樣才不會找不到下一格
        free(x);                            //釋放現在這格
        x=ptr;                              //走到下一格
    }
}