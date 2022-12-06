// Program for Circular Linked List Primitive Operations

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
void InsAft(struct node *q, int x)
{

    if (q != NULL)
    {
        struct node *p;
        p = GetNode();
        p->info = x;
        p->next = q->next;
        q->next = p;
    }
    else
    {
        printf("Void Insertion");
        exit;
    }
}
void DelBeg(struct node **cstart)
{
    struct node *p;
    int x;
    p = (*cstart)->next;
    (*cstart)->next = p->next;
    if ((*cstart)->next == (*cstart))
    {
        (*cstart) = NULL;
    }
    x = p->info;
    free(p);
}
void DelEnd(struct node **cstart)
{
    struct node *p, *q;
    int x;
    p = (*cstart);
    q = (*cstart)->next;
    while (q->next != p)
    {
        q = q->next;
    }
    q->next = p->next;
    (*cstart) = q;
    x = p->info;
    free(p);
}
void DelAft(struct node *q)
{
    struct node *p;
    p = q->next;
    q->next = p->next;
    int x;
    x = p->info;
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
int cycleLen(struct node **cstart)
{
    struct node *t, *r;
    t = (*cstart);
    r = (*cstart);
    while (r != NULL && r->next != NULL)
    {
        t = t->next;
        r = r->next;
        r = r->next;
        if (r == t)
        {
            break;
        }
    }
    int count = 0;
    do
    {
        count++;
        t = t->next;
    } while (t != r);

    return count;
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
    printf("Circular Linked List: ");
    ctraverse(start);
    struct node *p;
    int pos, x;
    printf("Enter position of insertion and element: ");
    scanf("%d %d", &pos, &x);
    p = start;
    if (pos > cycleLen(&start) + 1)
    {
        printf("Invalid Insertion\n");
    }
    else if (pos == 1)
    {
        InsBeg(&start, x);
    }
    else
    {
        for (int i = 1; i < pos; i++)
        {
            p = p->next;
        }
        InsAft(p, x);
    }
    printf("linked list after Insertion: ");
    ctraverse(start);

    DelEnd(&start);
    int pos1;
    printf("Enter position:  ");
    scanf("%d", &pos1);
    struct node *q;
    q = start;
    if (pos1 > cycleLen(&start) + 1)
    {
        printf("Invalid Deletion");
    }
    else if (pos1 == 1)
    {
        DelBeg(&start);
    }
    else
    {
        for (int i = 1; i < pos1 - 1; i++)
        {
            p = p->next;
        }
        DelAft(p);
    }
    printf("linked list after deletion: ");
    ctraverse(start);

    return 0;
}