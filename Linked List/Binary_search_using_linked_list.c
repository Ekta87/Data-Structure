// Program to perform Binary Search on the Linked List

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

struct node *midElement(struct node **start)
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
    return t;
}

void Binary_search(struct node **start, int x)
{

    while ((*start)->next != NULL)
    {
        struct node *m;
        m = midElement(&(*start));
        if (m->info == x)
        {
            printf("%d", m->info);
            exit(1);
        }
        else if (m->info < x)
        {
            (*start) = m->next;
        }
        else
        {
            m->next = NULL;
        }
    }
    if ((*start)->info == x)
    {
        printf("%d", (*start)->info);
    }
    else
    {
        printf("ELement not found");
    }
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
    printf("Linked list: ");
    traverse(start);

    int x;
    printf("Enter element to search: ");
    scanf("%d", &x);
    printf("Searched Element is: ");
    Binary_search(&start, x);

    return 0;
}