// Program for Union of two sorted Linked List (consider lists as sets)

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
void InsAft(struct node **q, int x)
{
    struct node *r, *p;
    r = (*q)->next;
    p = GetNode();
    p->info = x;
    p->next = r;
    (*q)->next = p;
}
void InsEnd(struct node **start, int x)
{
    struct node *q, *p;
    q = *start;
    if (q == NULL)
    {
        InsBeg(&(*start), x);
    }
    else
    {
        while (q->next != '\0')
        {
            q = q->next;
        }
        p = GetNode();
        p->info = x;
        p->next = '\0';
        q->next = p;
    }
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

int ordered_insertion(struct node **start, int x)
{
    struct node *p, *q;
    p = (*start);
    q = NULL;
    while (p != NULL && x >= p->info)
    {
        q = p;
        p = p->next;
    }
    if (q == NULL)
    {
        InsBeg(&(*start), x);
    }
    else
    {
        InsAft(&q, x);
    }
}
int Union(struct node *start1, struct node *start2)
{
    struct node *p, *q, *start;
    p = (start1);
    q = (start2);
    start = NULL;
    while (p != NULL && q != NULL)
    {
        if (p->info < q->info)
        {
            InsEnd(&start, p->info);
            p = p->next;
        }
        else if (p->info == q->info)
        {
            InsEnd(&start, p->info);
            p = p->next;
            q = q->next;
        }

        else
        {
            InsEnd(&start, q->info);
            q = q->next;
        }
    }
    while (p != NULL)
    {
        InsEnd(&start, p->info);
        p = p->next;
    }
    while (q != NULL)
    {
        InsEnd(&start, q->info);
        q = q->next;
    }
    traverse(&start);
}

int main()
{
    struct node *start1, *start2;
    start1 = NULL;
    start2 = NULL;
    ordered_insertion(&start1, 10);
    ordered_insertion(&start1, 2);
    ordered_insertion(&start1, 15);
    ordered_insertion(&start1, 7);
    ordered_insertion(&start1, 20);
    traverse(&start1);
    ordered_insertion(&start2, 14);
    ordered_insertion(&start2, 19);
    ordered_insertion(&start2, 10);
    ordered_insertion(&start2, 5);
    ordered_insertion(&start2, 25);
    ordered_insertion(&start2, 23);
    ordered_insertion(&start2, 35);
    traverse(&start2);
    printf("Union of 2 linked lists: ");
    Union(start1, start2);

    return 0;
}