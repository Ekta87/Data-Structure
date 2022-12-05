// Program to Delete kth node from end of a linked list in a single scan and O(n) time

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

void delBeg(struct node **start)
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
}

int delAft(struct node **p)
{
    if ((*p) == NULL || (*p)->next == NULL)
    {
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

void traverse(struct node *start)
{
    struct node *p;
    p = start;
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

void Del_kth_node(struct node **start, int n)
{
    struct node *p, *q;
    p = (*start);
    q = (*start);
    if (n > count(*start))
    {
        printf("Void Input");
        exit;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            q = q->next;
        }
    }
    if (q == NULL)
    {
        delBeg(&(*start));
    }
    else
    {
        while (q->next != NULL)
        {
            p = p->next;
            q = q->next;
        }
        delAft(&p);
    }
    // traverse(*start);
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
    printf("Linked list: ");
    traverse(start);
    int pos;
    printf("Enter Kth position from last:  ");
    scanf("%d", &pos);

    Del_kth_node(&start, pos);
    printf("linked list after deletion of Kth node from last: ");
    traverse(start);

    return 0;
}
