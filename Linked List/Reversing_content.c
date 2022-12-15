// Program to print Linked List contents in reverse order

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

void traverse(struct node *start)
{
    struct node *p;
    p = start;
    while (p != NULL)
    {
        printf("%d ", p->info);
        p=p->next;
    }
    printf("\n");
}

void print_reverse(struct node *start)
{
    struct node *p;
    p = (start);
    if (p != NULL)
    {
        print_reverse(p->next);
        printf("%d  ", p->info);
    }
}

int main()
{
    struct node *start1;
    start1 = NULL;

    InsBeg(&start1, 10);
    InsBeg(&start1, 2);
    InsBeg(&start1, 15);
    InsBeg(&start1, 7);
    InsBeg(&start1, 20);
    printf("Linked List: ");
    traverse(start1);
    printf("Reverse content of linked lists: ");
    print_reverse(start1);

    return 0;
}