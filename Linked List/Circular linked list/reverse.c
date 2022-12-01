// Program for reversing the Circular Linked List

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
int reverse(struct node **cstart)
{
    struct node *p, *c, *n;
    p = (*cstart);
    c = p->next;
    n = c->next;
    while (c != (*cstart))
    {
        c->next = p;
        p = c;
        c = n;
        if (n != (*cstart)->next)
        {
            n = n->next;
        }
    }
    c->next = p;
    (*cstart) = n;
    ctraverse(*cstart);
}

int main()
{
    struct node *start;
    start = NULL;

    InsBeg(&start, 30);
    InsBeg(&start, 70);
    InsBeg(&start, 50);
    InsBeg(&start, 10);
    InsEnd(&start, 180);
    InsEnd(&start, 170);
    printf("Linked list : ");
    ctraverse(start);

    printf("Reverse of circular linked list: ");
    reverse(&start);

    return 0;
}