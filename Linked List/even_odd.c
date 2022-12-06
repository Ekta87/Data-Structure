// Program for counting nodes containing even and odd information.

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

int even_odd(struct node **start)
{
    struct node *p;
    p = (*start);
    int even = 0;
    int odd = 0;
    while (p != NULL)
    {
        if (p->info % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
        p = p->next;
    }
    printf("Number of Even Nodes: ");
    printf("%d\n", even);
    printf("Number of Odd Nodes: ");
    printf("%d", odd);
}

int main()
{
    struct node *start;
    start = NULL;
    InsBeg(&start, 1);
    InsBeg(&start, 2);
    InsBeg(&start, 3);
    InsBeg(&start, 4);
    InsBeg(&start, 5);
    InsEnd(&start, 6);
    InsEnd(&start, 7);
    InsEnd(&start, 9);
    printf("Linked list: ");
    traverse(start);
    even_odd(&start);

    return 0;
}