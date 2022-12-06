// Program for Linked List Implementation of Stacks

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

int delBeg(struct node **start)
{
    if (start == NULL)
    {
        printf("Void Deletion");
        exit;
    }
    struct node *p;
    p = (*start);
    (*start) = (*start)->next;
    int x = p->info;
    free(p);
    return x;
}

int push(struct node **top, int x)
{
    InsBeg(&(*top), x);
}

int pop(struct node **top)
{
    int x;
    x = delBeg(&(*top));
    printf("%d  ", x);
}

int traverse(struct node **start)
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

int main()
{
    struct node *top;
    top = NULL;
    push(&top, 100);
    push(&top, 200);
    push(&top, 300);
    push(&top, 400);
    push(&top, 500);
    push(&top, 600);
    push(&top, 700);
    printf("Stack: ");
    traverse(&top);
    printf("popped element: ");
    pop(&top);
    pop(&top);
    printf("\n");
    printf("Stack after pop: ");
    traverse(&top);

    return 0;
}