#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coef;
    int expo;
    struct node *next;
};
struct node *GetNode()
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    return p;
}
void InsBeg(struct node **start, int x, int pr)
{
    struct node *p;
    p = GetNode();
    p->coef = x;
    p->expo = pr;
    p->next = (*start);
    (*start) = p;
}
void InsAft(struct node *q, int x, int pr)
{
    struct node *r, *p;
    r = q->next;
    p = GetNode();
    p->coef = x;
    p->expo = pr;
    p->next = r;
    q->next = p;
}

void InsEnd(struct node **start, int x, int pr)
{
    struct node *q, *p;
    q = (*start);
    if (q == NULL)
    {
        InsBeg(&(*start), x, pr);
    }
    else
    {
        while (q->next != '\0')
        {
            q = q->next;
        }
        p = GetNode();
        p->coef = x;
        p->expo = pr;
        p->next = '\0';
        q->next = p;
    }
}
void traverse(struct node **start)
{
    struct node *p;
    p = (*start);
    while (p != NULL)
    {
        printf("%dx^%d + ", p->coef, p->expo);
        p = p->next;
    }
    printf("\n");
}
void traverse1(struct node **start)
{
    struct node *p;
    p = (*start);
    while (p != NULL)
    {
        printf("(%dx^%d) + ", p->coef, p->expo);
        p = p->next;
    }
    printf("\n");
}
int polynomial_addition(struct node **poly1, struct node **poly2)
{
    struct node *p, *q, *start;
    p = (*poly1);
    q = (*poly2);
    start = NULL;
    while (p != NULL && q != NULL)
    {
        if (p->expo == q->expo)
        {
            InsEnd(&start, p->coef + q->coef, p->expo);
            p = p->next;
            q = q->next;
        }
        else if (p->expo > q->expo)
        {
            InsEnd(&start, p->coef, p->expo);
            p = p->next;
        }
        else
        {
            InsEnd(&start, q->coef, q->expo);
            q = q->next;
        }
    }
    while (p != NULL)
    {
        InsEnd(&start, p->coef, p->expo);
        p = p->next;
    }
    while (q != NULL)
    {
        InsEnd(&start, q->coef, q->expo);
        q = q->next;
    }
    traverse1(&start);
}
int polynomial_subtraction(struct node **poly1, struct node **poly2)
{
    struct node *q;
    q=(*poly2);
    while (q != NULL)
    {
        q->coef = -(q->coef);
        q = q->next;
    }
    
   polynomial_addition(&(*poly1), &(*poly2));
   
}
int main()
{
    struct node *start1, *start2;
    start1 = NULL;
    start2 = NULL;
    InsBeg(&start1, 100, 1);
    InsBeg(&start1, 200, 2);
    InsBeg(&start1, 300, 3);
    InsBeg(&start1, 400, 4);
    InsBeg(&start1, 500, 5);
    InsBeg(&start2, 600, 0);
    InsBeg(&start2, 700, 2);
    InsBeg(&start2, 800, 3);
    InsBeg(&start2, 600, 4);
    InsBeg(&start2, 700, 5);
    InsBeg(&start2, 800, 6);
    traverse(&start1);
    traverse(&start2);
    printf("subtraction   of the above polynomial: ");
    polynomial_subtraction(&start1, &start2);

    return 0;
}