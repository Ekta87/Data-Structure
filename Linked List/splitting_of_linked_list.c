// Program for Splitting a Linked List(in-place)

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
    p->next = *start;
    *start = p;
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

int traverse(struct node *start)
{
    struct node *p;
    p = (start);
    while (p != '\0')
    {
        printf("%d  ", p->info);
        p = p->next;
    }
    printf("\n");
}

int *split(struct node **start1)
{
    struct node *t, *r, *start2;
    t = (*start1);
    r = (*start1)->next;
    while (r != NULL && r->next != NULL)
    {
        t = t->next;
        r = r->next;
        r = r->next;
    }
    start2 = t->next;
    t->next = NULL;
    printf("Linked List 1: ");
    traverse(*start1);
    printf("Linked List 2: ");
    traverse(start2);
}

int main()
{
    struct node *start;
    start = NULL;
    InsBeg(&start, 1);
    InsEnd(&start, 2);
    InsEnd(&start, 3);
    InsEnd(&start, 4);
    InsEnd(&start, 5);
    InsEnd(&start, 6);
    InsEnd(&start, 7);
    InsEnd(&start, 8);
    InsEnd(&start, 9);
    InsEnd(&start, 10);
    InsEnd(&start, 11);
    printf("Linked list: ");
    traverse(start);
    split(&start);

    return 0;
}