// Problem 5
// Uncle Huang choose Tutor(Easy version)
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    int number;
    struct _Node* next;
} Node;

Node *createList(int n);
void freeList(Node* head);
int solveJosephus(Node **head, int step);

int main( void )
{
    int n, k;
    while( scanf( "%d%d", &n, &k )!=EOF ) {
        Node *head;
        head = createList( n );
        printf( "%d\n", solveJosephus( &head, k ) );
        freeList( head );
    }
    return 0;
}

//=============================
Node *createList( int n )
{
    Node *pHead = NULL;
    Node *pTemp = NULL;
    Node *pLast = NULL;
    for( int i = 1; i <= n; i++ ) {
        pTemp = ( Node * )malloc( sizeof( Node ) );
        pTemp->number = i;
        
        if( i == 1 ) {
            pHead = pTemp;
        }
        else {
            pLast->next = pTemp;
        }

        pTemp->next = pHead;
        pLast = pTemp;
    }
    return pHead;
}

void freeList( Node* head )
{
    Node *pTemp = head;
    Node *pNext = head->next;
    while( pNext != head ) {
        pTemp = pNext;
        pNext = pNext->next;
        //printf( "%d ", pTemp->number );
        free( pTemp );
    }
    //free( head );
    //printf( "\n" );
}

int Size( Node *pHead )
{
    Node *pTemp = pHead;
    Node *pNext = pHead->next;
    int i = 1;
    while( pNext != pHead ) {
        i++;
        pTemp = pNext;
        pNext = pNext->next;
        //printf( "%d ", pTemp->number );
    }
    return i;
}

Node* GetLast( Node *pHead )
{
    Node *pTemp = pHead;
    Node *pNext = pHead->next;
    int i = 1;
    while( pNext != pHead ) {
        i++;
        pTemp = pNext;
        pNext = pNext->next;
        //printf( "%d ", pTemp->number );
    }
    return pTemp;
}

Node * delete( Node * pLast, Node * pStart, int step )
{
    Node *pNow = pStart;
    Node *pNext = pNow->next;
    if( step == 1 ) {
        //printf( "free %d\n", pNow->number );
        pLast->next = pNext;
        free( pNow );
        return pNext;
    }

    for( int i = 1; i < step; i++ ) {
        pLast = pNow;
        pNow = pNext;
        pNext = pNow->next;
    }
    //printf( "free %d\n", pNow->number );
    pLast->next = pNext;
    free( pNow );
    return pNext;
}

int solveJosephus( Node **head, int step )
{
    Node *pTemp = *head;
    Node *pLast = NULL;
    int nSize = Size( pTemp );
    int nTempSize = 0;
    for( int i = 0; i < nSize - 1; i++ ) {
        nTempSize = nSize - i;
        int nStep = step % nTempSize;
        if( nStep == 0 ) {
            nStep = nTempSize;
        }
        
        pLast = GetLast( pTemp );
        pTemp = delete( pLast, pTemp, nStep );
    }
    *head = pTemp;
    return pTemp->number;
}
