// Program to find the Merging point in the linked list

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

int merging_point(struct node **start1, struct node **start2)
{
    struct node *p, *q;
    p = (*start1);
    q = (*start2);
    int m = count(*start1);
    int n = count(*start2);

    if (m > n)
    {
        for (int i = 0; i < (m - n); i++)
        {
            p = p->next;
        }
    }
    else if (m < n)
    {
        for (int i = 0; i < (n - m); i++)
        {
            q = q->next;
        }
    }
    while (p != q)
    {
        p = p->next;
        q = q->next;
    }
    if (p != NULL)
    {
        printf("%d", p->info);
    }
    else
    {
        printf("No merging point exists");
    }
}

int main()
{
    struct node *start1, *start2;
    start1 = NULL;
    InsBeg(&start1, 1);
    InsEnd(&start1, 2);
    InsEnd(&start1, 3);
    InsEnd(&start1, 4);
    InsEnd(&start1, 5);
    InsEnd(&start1, 6);
    InsEnd(&start1, 7);
    InsEnd(&start1, 8);
    printf("Linked List 1: ");
    traverse(start1);
    struct node *p, *q;
    p = start1;
    while (p->info != 5)
    {
        p = p->next;
    }
    start2 = NULL;
    InsBeg(&start2, 10);
    InsEnd(&start2, 11);
    q = start2;
    while (q->next != NULL)
    {
        q = q->next;
    }
    q->next = p;
    printf("Linked List 2: ");
    traverse(start2);
    merging_point(&start1, &start2);

    return 0;
}