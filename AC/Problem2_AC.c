// Problem 2
// after rain
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

// FROM OJ ==============================
typedef struct _NODE
{
    char color[10];
    struct _NODE *next;
} Node;
// ==============================

void insert(Node**, char*, int);

void erase1(Node**, int);

void erase2(Node**, char*);

void show(Node **head);

void reverse(Node**, int, int);

void insert(Node** head, char* buf,int num){
    Node* now = *head; // always count from head
    Node* np = (Node*) malloc(sizeof(Node));
    strcpy(np->color,buf);
    while(num--){
        if(now->next == NULL)
            break;
        now = now->next;
    }
    np->next = now->next;
    now->next = np; // store new data in now.next
    // linked list will looks like this
    // head 1 2 3 4 5
}

void erase1(Node** head, int num){
    Node* now = *head;
    Node* pre = NULL;
    while(num--){
        if(now->next == NULL)
            break;
        pre = now;
        now = now->next;
    }
    if(pre != NULL){
        pre->next = now->next;
        free(now);
    }
}

void erase2(Node** head,char* buf){
    Node *now = (*head)->next;
    Node *pre = *head;
    while(now != NULL){
        if(!strcmp(now->color,buf)){
            pre->next = now->next;
            free(now);
            now = pre->next;
        }
        else {
            pre = now;
            now = now->next;
        }
    }
}

void reverse(Node** head, int a, int b){
    Node *now = *head;
    Node *connect;
    Node *next;
    int copya = a;
    // if a = 1, connect = first element, now is the second element
    while(copya--){
        connect = now;
        now = now->next;
    }
    int cnt = b-a;
    while(cnt-- && (now->next)!=NULL){
        next = now->next;           // @a
        now->next = next->next;     // @b
        next->next = connect->next; // @c
        connect->next = next;       // @d
    }
/*
example
from 1 to 6
con a b c d e f g -> a f e d c b g
con already
con a e d c b f g
0   1 2 3 4 5 6 7
    _ _ _ _ _     <- already reverse
^           ^
|           |
|           |
|           now
connect
@a: set f as new next
we want f insert between a and e
but before that we should let f->next connect to now
@b: b.next = g
@c: f.next = e
@d: a.next = f
total times = ( 6 - 1 ) = ( now cursor from a to e )
*/
}

// FROM OJ===============================================================

void show(Node **head) {
    Node *now = (*head)->next;
    while(now!=NULL) {
        printf("%s ", now->color);
        now = now->next;
    }
    puts("");
}

int n;
char buf[100];
int num1, num2;
Node *head;

int main() {
    head = (Node*)malloc(sizeof(Node)); // create an empty node
    memset(head->color,'\0',sizeof(head->color));
    head->next = NULL;
    scanf("%d",&n);
    while(n--) {
        scanf("%s",buf);
        if(!strcmp(buf,"insert")) {
            scanf("%s%d",buf,&num1);
            insert(&head, buf, num1); // insert <color> <dest>
        }
        else if(!strcmp(buf,"erase1")) {
            scanf("%d",&num1);
            erase1(&head, num1); // erase1 <dest>
        }
        else if(!strcmp(buf,"erase2")) {
            scanf("%s",buf);
            erase2(&head, buf); // erase2 <color>
        }
        else if(!strcmp(buf,"reverse")) {
            scanf("%d%d",&num1,&num2);
            reverse(&head, num1, num2); // reverse <dest1> <dest2>
        }
        else if(!strcmp(buf,"show")) {
            show(&head);
        }
    }
    return 0;
}
// ==============================