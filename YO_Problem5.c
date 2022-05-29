// Problem 5
// Uncle Huang choose Tutor(Easy version)
Node *createList(int n)
{
    Node *node = malloc(sizeof(Node));
    node->number = n;
    return node;
}

void freeList(Node* head)
{
    free(head);
    head = NULL;
}

int solveJosephus(Node **head, int step)
{
    int num = (*head)->number;
    int DP[1001] = {0};
    for (int i = 2; i <= num; ++i)
        DP[i] = (DP[i - 1] + step) % i;

    return DP[num] + 1;
}