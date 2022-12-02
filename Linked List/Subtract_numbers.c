// Program to find out the subtraction of two given link list

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
    q = *start;
    while (q->next != '\0')
    {
        q = q->next;
    }
    p = GetNode();
    p->info = x;
    p->next = '\0';
    q->next = p;
}

void traverse(struct node **start)
{
    struct node *p;
    p = (*start);
    while (p != '\0')
    {
        printf("%d", p->info);
        p = p->next;
    }
    printf("\n");
}

int reverse(struct node **start1)
{
    struct node *p, *c, *n;
    p = NULL;
    c = (*start1);
    n = c->next;
    while (c != NULL)
    {
        c->next = p;
        p = c;
        c = n;
        if (n != NULL)
        {
            n = n->next;
        }
    }
    (*start1) = p;
}
struct node *Subtract_Numbers(struct node **start1, struct node **start2)
{
    reverse(&(*start1));
    reverse(&(*start2));
    struct node *p, *q, *start;
    p = (*start1);
    q = (*start2);
    start = NULL;
    int borrow = 10, total;

    while (p != NULL && q != NULL)
    {
        if ((p->info) < (q->info))
        {
            total = (p->info + borrow) - (q->info);
            InsBeg(&start, total);
            p = p->next;
            p->info = p->info - 1;
            q = q->next;
        }
        else
        {
            total = (p->info) - (q->info);
            InsBeg(&start, total);
            p = p->next;
            q = q->next;
        }
    }
    while (p != NULL)
    {
        total = p->info;
        InsBeg(&start, total);
        p = p->next;
    }

    return start;
}

int main()
{
    struct node *start1, *start2, *start;
    start1 = NULL;
    start2 = NULL;
    start = NULL;
    InsBeg(&start1, 1);
    InsEnd(&start1, 2);
    InsEnd(&start1, 5);
    // traverse(&start1);
    InsBeg(&start2, 8);
    InsEnd(&start2, 5);
    // traverse(&start2);
    printf("Subtraction of 2 numbers using linked list: ");
    start = Subtract_Numbers(&start1, &start2);
    traverse(&start);

    return 0;
}
