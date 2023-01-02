// Write a program for creating the General Tree

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *child, *sibling;
};
struct node *MakeNode(int x)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = x;
    p->child = NULL;
    p->sibling = NULL;
    return p;
}

void Create_tree(struct node **tree)
{
    struct node *p;
    int x, info;
    printf("whether child exist of %d ?(1/0)", (*tree)->data);
    scanf("%d", &x);
    if (x == 1)
    {
        printf("Enter data: ");
        scanf("%d", &info);
        p = MakeNode(info);
        (*tree)->child = p;
        Create_tree(&p);
    }

    printf("whether sibling exist of %d ?(1/0)", (*tree)->data);
    scanf("%d", &x);
    if (x == 1)
    {
        printf("Enter data: ");
        scanf("%d", &info);
        p = MakeNode(info);
        (*tree)->sibling = p;
        Create_tree(&p);
    }
}

void PreOrderTraversal(struct node *t)
{
    if ((t != NULL))
    {
        printf("%d ", t->data);
        PreOrderTraversal(t->child);
        PreOrderTraversal(t->sibling);
    }
}
void InOrderTraversal(struct node *t)
{
    if ((t != NULL))
    {
        InOrderTraversal(t->child);
        printf("%d ", t->data);
        InOrderTraversal(t->sibling);
    }
}

void PostOrderTraversal(struct node *t)
{
    if ((t != NULL))
    {
        PostOrderTraversal(t->child);
        PostOrderTraversal(t->sibling);
        printf("%d ", t->data);
    }
}

int main()
{
    struct node *root;
    root=NULL;
    int info;
    printf("Enter data of root: ");
    scanf("%d", &info);
    root = MakeNode(info);

    Create_tree(&root);

    printf("Pre Order: ");
    PreOrderTraversal(root);
    printf("\n");
    printf("In Order: ");
    InOrderTraversal(root);
    printf("\n");
    printf("Post Order: ");
    PostOrderTraversal(root);
}
