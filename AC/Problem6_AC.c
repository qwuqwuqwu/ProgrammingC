// Problem 6
// Operation on Sequence
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _Node{
    int x;
    struct _Node* next;
}Node;


void insert(Node* head,int num,int cnt){
    Node* now = head;
    while(cnt--){
        Node* np = (Node*)malloc(sizeof(Node));
        np->x = num;
        np->next = now->next;
        now->next = np;
    }
}

void erase(Node* head, int cnt){
    Node* now = head;
    Node* next;
    while(cnt--){
        next = now->next;
        now->next = next->next;
        free(next);
    }
}

void move(Node** head, int cnt){

    Node* now = *head;
    int total = 0;
    while(now->next != *head){
        now = now->next;
        total++;
    }
    total++; // last time now->next = *head, but we need to count this "now"
    
    now = now->next; // now shoulw be head
    int real = cnt % total; 
    // noted that -2 % 5 = -2, -5 % 5 = 0, -6 % 5 = -1
    // so plus total if real < 0
    if( real < 0 ) {
        real += total;
    }

    while(real--) {
        now = now->next;
    }
    //printf("%d", now->x);
    *head = now;
}
void show(Node* head){
    Node* now = head;
    while(now->next != head){
        printf("%d ", now->x);
        now = now->next;
    }
    printf("%d\n", now->x);
}
int main(){
    Node * head =(Node*)malloc(sizeof(Node));
    head->next = head; // circular

    scanf("%d", &(head->x));
    
    int t;
    scanf("%d", &t);
    char tmp[10];
    while(t--){
        scanf("%s", tmp);
        if(!strcmp(tmp,"insert")){
            int num,cnt;
            scanf("%d%d", &num, &cnt);
            insert(head,num,cnt);
        }
        if(!strcmp(tmp,"erase")){
            int cnt;
            scanf("%d", &cnt);
            erase(head, cnt);
        }
        if(!strcmp(tmp,"move")){
            int cnt;
            scanf("%d", &cnt);
            move(&head, cnt);
        }
        if(!strcmp(tmp,"show")){
            show(head);
        }
    }
}