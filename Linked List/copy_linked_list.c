// Program for Creation of Copy of the Linked list

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

void Copy_linked_list(struct node **start1, struct node **start2)
{
    struct node *p;
    p = (*start1);
    while (p != NULL)
    {
        InsEnd(&(*start2), p->info);
        p = p->next;
    }
}
int main()
{
    struct node *start1, *start2;
    start1 = NULL;
    start2 = NULL;
    InsEnd(&start1, 100);
    InsEnd(&start1, 200);
    InsEnd(&start1, 300);
    InsEnd(&start1, 400);
    InsEnd(&start1, 500);
    InsEnd(&start1, 600);
    InsEnd(&start1, 700);
    InsEnd(&start1, 800);
    printf("Linked list 1: ");
    traverse(start1);

    printf("Copy of Linked List 1 in Linked List 2: ");
    Copy_linked_list(&start1, &start2);
    traverse(start2);

    return 0;
}