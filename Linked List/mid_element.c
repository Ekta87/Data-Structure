// Program for Finding the Middle element of a singly linked list in one pass

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
        printf("%d  ", p->info);
        p = p->next;
    }
    printf("\n");
}
int count(struct node *start)
{
    struct node *p = start;
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}
int midElement(struct node **start)
{
    struct node *t, *r;
    t = (*start);
    r = (*start)->next;
    while (r != NULL && r->next != NULL)
    {
        t = t->next;
        r = r->next;
        r = r->next;
    }
    printf("%d", t->info);
}

int main()
{
    struct node *start, *p, *q;
    start = NULL;
    InsBeg(&start, 100);
    InsBeg(&start, 200);
    InsBeg(&start, 300);
    InsBeg(&start, 400);
    InsBeg(&start, 500);
    InsEnd(&start, 600);
    InsEnd(&start, 700);
    // InsEnd(&start, 800);
    traverse(&start);
    midElement(&start);

    return 0;
}
