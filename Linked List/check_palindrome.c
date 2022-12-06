// Program for finding if the given link list is palindrome or not

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
    p = GetNode();
    p->info = x;
    p->next = '\0';
    if (q == NULL)
    {
        (*start) = p;
    }
    else
    {
        while (q->next != '\0')
        {
            q = q->next;
        }
        q->next = p;
    }
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

struct node *reverse(struct node **start1)
{
    struct node *p, *start;
    p = (*start1);
    start = NULL;
    while (p != NULL)
    {
        InsBeg(&start, p->info);
        p = p->next;
    }
    return start;
}

void palindrome(struct node **start1)
{
    struct node *p, *start2;
    start2 = NULL;
    p = (*start1);
    start2 = reverse(&(*start1));
    struct node *q;
    q = start2;
    int flag = 0;
    while (p != NULL && q != NULL)
    {
        if (q->info == p->info)
        {
            q = q->next;
            p = p->next;
        }
        else
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("linked List is Palindrome");
    }
    else
    {
        printf("Linked List is not Palindrome");
    }
}
int main()
{
    struct node *start;
    start = NULL;
    InsEnd(&start, 2);
    InsEnd(&start, 0);
    InsEnd(&start, 5);
    InsEnd(&start, 0);
    InsEnd(&start, 2);
    printf("Linked list: ");
    traverse(start);
    palindrome(&start);

    return 0;
}