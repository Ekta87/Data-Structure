// Program for implementation of Josephus Problem

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
void DelAft(struct node *q)
{
    struct node *p;
    p = q->next;
    q->next = p->next;
    free(p);
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

int Josephus(struct node **cstart)
{
    struct node *p, *q;

    p = (*cstart);
    q = NULL;
    int c = 0;
    while (p->next != p)
    {
        while (c != 13)
        {
            q = p;
            p = p->next;
            c++;
        }
        p = p->next;
        DelAft(q);
        c = 1;
    }
    printf("%d", p->info);
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
    printf("Linked list : ");
    ctraverse(start);

    printf("The position which is safe: ");
    Josephus(&start);

    return 0;
}