// Program for Pair wise swap of elements in linked list

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

struct node *Pair_swap(struct node **start)
{
    struct node *p, *q;
    p = (*start);
    q = (*start)->next;
    while (q != NULL)
    {
        int x = p->info;
        p->info = q->info;
        q->info = x;
        p = p->next;
        p = p->next;
        q = q->next;
        if (q != NULL)
        {
            q = q->next;
        }
    }
    traverse(*start);
}

int main()
{
    struct node *start;
    start = NULL;
    InsBeg(&start, 100);
    InsEnd(&start, 200);
    InsEnd(&start, 300);
    InsEnd(&start, 400);
    InsEnd(&start, 500);
    InsEnd(&start, 600);
    InsEnd(&start, 700);
    InsEnd(&start, 800);
    InsEnd(&start, 900);
    printf("Linked list: ");
    traverse(start);
    printf("Linked List after pair wise swapping: ");
    Pair_swap(&start);

    return 0;
}