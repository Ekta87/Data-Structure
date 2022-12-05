// Program to find kth node from the last in a single link list

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
void kth_node(struct node **start, int n)
{
    struct node *p, *q;
    p = (*start);
    q = (*start);
    int x;
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
        x = p->info;
    }
    else
    {
        while (q->next != NULL)
        {
            p = p->next;
            q = q->next;
        }
        p = p->next;
        x = p->info;
    }
    printf("%d", x);
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

    printf("Kth node information from the last: ");
    kth_node(&start, pos);

    return 0;
}
