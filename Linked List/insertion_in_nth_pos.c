// Program to insert an item at any given position in the linked List

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
void InsAft(struct node *q, int x)
{
    struct node *r, *p;
    r = q->next;
    p = GetNode();
    p->info = x;
    p->next = r;
    q->next = p;
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
int traverse(struct node **start)
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
int delBeg(struct node **start)
{
    if (start == NULL)
    {
        printf("Invalid Deletion");
        exit;
    }
    struct node *p;
    p = (*start);
    (*start) = (*start)->next;
    int x = p->info;
    free(p);
    return x;
}
int delEnd(struct node **start)
{
    struct node *p, *q;
    p = (*start);
    q = NULL;
    while (p->next != NULL)
    {
        q = p;
        p = p->next;
    }
    q->next = NULL;
    int x = p->info;
    free(p);
    return x;
}
int delAft(struct node **p)
{
    if ((*p) == NULL || (*p)->next == NULL)
    {
        printf("Invalid Deletion");
        exit;
    }
    struct node *q, *r;
    q = (*p)->next;
    r = q->next;
    (*p)->next = r;
    int x = q->info;
    free(q);
    return x;
}
int main()
{
    struct node *start;
    start = NULL;
    InsBeg(&start, 100);
    InsBeg(&start, 200);
    InsBeg(&start, 300);
    InsBeg(&start, 400);
    InsBeg(&start, 500);
    InsEnd(&start, 600);
    InsEnd(&start, 700);
    InsEnd(&start, 800);
    printf("Linked list before insertion: ");
    traverse(&start);
    int pos,x;
    printf("Enter position and element:  ");
    scanf("%d %d", &pos,&x);
    struct node *p;
    p = start;
    if (pos > count(start) + 1)
    {
        printf("Invalid Deletion");
    }
    else if (pos == 1)
    {
        InsBeg(&start,x);
    }
    else
    {
        for (int i = 1; i < pos - 1; i++)
        {
            p = p->next;
        }
        InsAft(p,x);
    }
    printf("linked list after deletion: ");
   traverse(&start);
    

    return 0;
}