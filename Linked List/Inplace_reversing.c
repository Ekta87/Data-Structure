// Program for Reversing the Linear Linked List

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

void traverse(struct node **start)
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

int ordered_insertion(struct node **start, int x)
{
    struct node *p, *q;
    p = (*start);
    q = NULL;
    while (p != NULL && x >= p->info)
    {
        q = p;
        p = p->next;
    }
    if (q == NULL)
    {
        InsBeg(&(*start), x);
    }
    else
    {
        InsAft(&q, x);
    }
}

int reverse(struct node **start1){
    struct node *p,*c,*n;
    p=NULL;
    c=(*start1);
    n=c->next;
    while (c!=NULL)
    {
        c->next=p;
        p=c;
        c=n;
        if (n!=NULL)
        {
            n=n->next;
        }
    }
    (*start1)=p;
    traverse(&(*start1));
    
}

int main()
{
    struct node *start1;
    start1 = NULL;
    
    ordered_insertion(&start1, 10);
    ordered_insertion(&start1, 2);
    ordered_insertion(&start1, 15);
    ordered_insertion(&start1, 7);
    ordered_insertion(&start1, 20);
    traverse(&start1);
    
    printf("Reverse linked lists: ");
    reverse(&start1);

    return 0;
}
