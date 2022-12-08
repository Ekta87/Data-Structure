// Program for Delete duplicate nodes in the Linked List

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

int DelAft(struct node *p)
{
    if (p == NULL || p->next == NULL)
    {
        printf("Invalid Deletion");
        exit;
    }
    struct node *q, *r;
    q = p->next;
    r = q->next;
    p->next = r;
    int x = q->info;
    free(q);
    return x;
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

struct node *Del_duplicate_nodes(struct node **start)
{
    struct node *p, *q, *r;
    p = (*start);
    r = (*start);
    q = (*start)->next;
    while (p != NULL)
    {

        while (q != NULL)
        {
            if (q->info == p->info)
            {
                q = q->next;
                DelAft(r);
            }
            else
            {
                r = q;
                q = q->next;
            }
        }
         if (p->next !=NULL)
        {
            p = p->next;
            r = p;
            q = p->next;
        }
        else 
        {
            break;
        }
    }
    traverse(*start);
}

int main()
{
    struct node *start;
    start = NULL;
    InsBeg(&start, 1);
    InsEnd(&start, 2);
    InsEnd(&start, 1);
    InsEnd(&start, 3);
    InsEnd(&start, 3);
    InsEnd(&start, 2);
    InsEnd(&start, 4);
    InsEnd(&start, 1);
    InsEnd(&start, 5);
    InsEnd(&start, 4);
    InsEnd(&start, 2);
    printf("Linked list: ");
    traverse(start);
    printf("Linked List after deleting duplicate nodes: ");
    Del_duplicate_nodes(&start);

    return 0;
}
