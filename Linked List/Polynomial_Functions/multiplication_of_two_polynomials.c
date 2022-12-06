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
void InsAft(struct node **q, int x, int pr)
{
    struct node *r, *p;
    r = (*q)->next;
    p = GetNode();
    p->coef = x;
    p->expo = pr;
    p->next = r;
    (*q)->next = p;
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

int ordered_insertion(struct node **start, int x, int pr)
{
    struct node *p, *q;
    p = (*start);
    q = NULL;
    while (p != NULL && pr <= p->expo)
    {
        q = p;
        p = p->next;
    }
    if (q == NULL)
    {
        InsBeg(&(*start), x, pr);
    }
    else
    {
        InsAft(&q, x, pr);
    }

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
    int x = q->coef;
    free(q);
}
int polynomial_multiplication(struct node **poly1, struct node **poly2)
{
    struct node *p, *q, *start;
    start = NULL;
    q = (*poly2);
    while (q != NULL)
    {
        p = (*poly1);
        while (p != NULL)
        {
            ordered_insertion(&start, (p->coef) * (q->coef), (p->expo) + (q->expo));
            p = p->next;
        }
        q = q->next;
    }
    p=start;
    while (p->next != NULL)
    {
        if ((p->expo) == (p->next->expo))
        {
            (p->coef) = (p->coef) + (p->next->coef);
            delAft(&p);
        }
        else
        p = p->next;
    }
    traverse(&start);
}
int main()
{
    struct node *start1, *start2;
    start1 = NULL;
    start2 = NULL;
    InsBeg(&start1, 1, 1);
    InsBeg(&start1, 2, 2);
    InsBeg(&start1, 3, 3);
    InsBeg(&start2, 6, 0);
    InsBeg(&start2, 7, 2);
    InsBeg(&start2, 8, 3);
    traverse(&start1);
    traverse(&start2);
    printf("Multiplication of the above polynomial: ");
    polynomial_multiplication(&start1, &start2);
    

    return 0;
}
