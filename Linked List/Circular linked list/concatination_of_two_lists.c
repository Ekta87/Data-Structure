// Program for concatenation of Circular Linked List

#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

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
void InsBeg(struct node **cstart, int x)
{
    struct node *p;
    p = GetNode();
    p->info = x;

    if ((*cstart) != NULL)
    {
        p->next = (*cstart)->next;
        (*cstart)->next = p;
    }
    else
    {
        (*cstart) = p;
        (*cstart)->next = (*cstart);
    }
}
void InsEnd(struct node **cstart, int x)
{
    struct node *q, *p;
    p = GetNode();
    p->info = x;
    if ((*cstart) != NULL)
    {
        p->next = (*cstart)->next;
        (*cstart)->next = p;
        (*cstart) = p;
    }
    else
    {
        (*cstart) = p;
        (*cstart)->next = (*cstart);
    }
}

void ctraverse(struct node *cstart)
{
    struct node *p, *q;
    p = cstart;
    q = cstart->next;
    while (q != p)
    {
        printf("%d  ", q->info);
        q = q->next;
    }
    printf("%d  ", p->info);
    printf("\n");
}
int concatenate(struct node **cstart1, struct node **cstart2)
{
    struct node *p, *q, *r;
    p = (*cstart1)->next;
    q = (*cstart2)->next;
    (*cstart1)->next = q;
    (*cstart2)->next = p;
    ctraverse(*cstart2);
}

int main()
{
    struct node *start1, *start2, *q;
    start1 = NULL;
    start2 = NULL;
    InsBeg(&start1, 30);
    InsBeg(&start1, 70);
    InsBeg(&start1, 50);
    InsBeg(&start1, 10);
    InsEnd(&start1, 180);
    InsEnd(&start1, 170);
    printf("Linked list 1: ");
    ctraverse(start1);
    InsBeg(&start2, 2);
    InsBeg(&start2, 5);
    InsBeg(&start2, 9);
    InsBeg(&start2, 3);
    printf("Linked List 2: ");
    ctraverse(start2);
    printf("Linked List after concatenation: ");
    concatenate(&start1, &start2);

    return 0;
}