// Program for Linked List Implementaion of Queue

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};
struct node *GetNode()
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    return p;
}
void InsBeg(struct node **start, int x)
{
    struct node *p;
    p = GetNode();
    p->info = x;
    p->next = (*start);
    (*start) = p;
}

void InsEnd(struct node **start, int x)
{
    struct node *q, *p;
    q = (*start);
    while (q->next != '\0')
    {
        q = q->next;
    }
    p = GetNode();
    p->info = x;
    p->next = '\0';
    q->next = p;
}

int delBeg(struct node **start)
{
    struct node *p;
    p = (*start);
    (*start) = (*start)->next;
    int x = p->info;
    free(p);
    return x;
}

void EnQueue(struct node **q, char x)
{
    if ((*q) == NULL)
    {
        InsBeg(&(*q), x);
    }
    else
    {
        InsEnd(&(*q), x);
    }
}
void DeQueue(struct node **q)
{
    int x;
    if ((*q) == NULL)
    {
        printf("Queue Underflows");
        exit;
    }
    else
    {
        x = delBeg(&(*q));
    }
    printf("%c  ", x);
}

void traverse(struct node **start)
{
    struct node *p;
    p = (*start);
    while (p != '\0')
    {
        printf("%c  ", p->info);
        p = p->next;
    }
    printf("\n");
}
int main()
{
    struct node *myQ;
    myQ = NULL;
    EnQueue(&myQ, 'A');
    EnQueue(&myQ, 'B');
    EnQueue(&myQ, 'C');
    EnQueue(&myQ, 'D');
    EnQueue(&myQ, 'E');
    EnQueue(&myQ, 'F');
    EnQueue(&myQ, 'G');

    printf("Queue elements are: ");
    traverse(&myQ);

    printf("Deleted elements of queue are: ");
    DeQueue(&myQ);
    DeQueue(&myQ);
    DeQueue(&myQ);
    printf("\n");

    printf("Queue after dequeue: ");
    traverse(&myQ);

    return 0;
}