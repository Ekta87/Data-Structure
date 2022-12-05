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
int delBeg(struct node **start)
{
    if ((*start) == NULL)
    {
        printf("Invalid Deletion");
        exit;
    }
    struct node *p;
    p = (*start);
    (*start) = (*start)->next;
    int x = p->info;
    free(p);
    return x;
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
        printf("%c  ", p->info);
        p = p->next;
    }
    printf("\n");
}

void Vowel_consonent(struct node **start)
{
    struct node *p, *q, *r;
    p = NULL;
    r = NULL;
    q = (*start);
    int x;
    while (q != NULL)
    {
        if (q->info == 'a' || q->info == 'e' || q->info == 'i' || q->info == 'o' || q->info == 'u' || q->info == 'A' || q->info == 'E' || q->info == 'I' || q->info == 'O' || q->info == 'U')
        {
            q = q->next;
            if (p == NULL)
            {
                if (r == NULL)
                {
                    x = delBeg(&(*start));
                    InsBeg(&(*start), x);
                    p = (*start);
                    r = p;
                }
                else
                {
                    x = delAft(&r);
                    InsBeg(&(*start), x);
                    p = (*start);
                }
            }
            else
            {
                x = delAft(&r);
                InsAft(&p, x);
                if (p == r)
                {
                    r = r->next;
                }
                p = p->next;
            }
        }
        else
        {
            r = q;
            q = q->next;
        }
    }
    traverse(*start);
}
int main()
{
    struct node *start;
    start = NULL;
    InsBeg(&start, 'A');
    InsEnd(&start, 'i');
    InsEnd(&start, 'o');
    InsEnd(&start, 'u');
    InsEnd(&start, 'k');
    InsEnd(&start, 'a');
    // InsEnd(&start, 'a');
    printf("Linked list: ");
    traverse(start);

    printf("Arrangement of vowels and consonents: ");
    Vowel_consonent(&start);

    return 0;
}
