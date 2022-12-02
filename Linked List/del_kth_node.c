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

void Del_kth_node(struct node **start, int n)
{
    struct node *p, *q;
    p = (*start);
    q = (*start);
    for (int i = 0; i < n; i++)
    {
        q = q->next;
    }
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    delAft(&p);
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
    traverse(start);
    int pos;
    printf("Enter Kth position from last:  ");
    scanf("%d", &pos);

    Del_kth_node(&start, pos);
    printf("linked list after deletion of Kth node from last: ");
    traverse(start);

    return 0;
}