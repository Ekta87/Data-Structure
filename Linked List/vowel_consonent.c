// Program to arrange the consonats ad vowel nodes of the linked list it in such a way that all
// the vowels nodes come before the consonats while maintaining the order of their arrival

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
int traverse(struct node **start)
{
    struct node *p;
    p = (*start);
    while (p != '\0')
    {
        printf("%c  ", p->info);
        p = p->next;
    }
    printf("\n");
}
void Vowel_consonent(struct node **start)
{
    struct node *p, *nstart;
    p = (*start);
    nstart = NULL;
    while (p != NULL)
    {
        if (p->info == 'a' || p->info == 'e' || p->info == 'i' || p->info == 'o' || p->info == 'u' || p->info == 'A' || p->info == 'E' || p->info == 'I' || p->info == 'O' || p->info == 'U')
        {
            InsBeg(&nstart, p->info);
        }
        else
        {
            InsEnd(&nstart, p->info);
        }
        p = p->next;
    }
    traverse(&nstart);
}
int main()
{
    struct node *start;
    start = NULL;
    InsBeg(&start, 'a');
    InsBeg(&start, 'c');
    InsBeg(&start, 'e');
    InsBeg(&start, 'w');
    InsBeg(&start, 'i');
    InsEnd(&start, 'h');
    InsEnd(&start, 'o');
    InsEnd(&start, 'u');
    printf("Linked list: ");
    traverse(&start);

    printf("Arrangement of vowels and consonents: ");
    Vowel_consonent(&start);

    return 0;
}