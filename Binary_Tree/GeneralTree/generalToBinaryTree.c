// Write a program to convert the given General Tree to Binary Tree

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *child, *sibling , *left, *right;
};
struct node *MakeNode(int x)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = x;
    p->child = NULL;
    p->sibling = NULL;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void Create_Generaltree(struct node **tree)
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
        Create_Generaltree(&p);
    }

    printf("whether sibling exist of %d ?(1/0)", (*tree)->data);
    scanf("%d", &x);
    if (x == 1)
    {
        printf("Enter data: ");
        scanf("%d", &info);
        p = MakeNode(info);
        (*tree)->sibling = p;
        Create_Generaltree(&p);
    }
}
void GeneralToBinary(struct node **tree)
{
    struct node *p;
   
    if ( (*tree)->child != NULL)
    {
        p = (*tree)->child;
        (*tree)->left=p;
        GeneralToBinary(&p);
    }

    if ((*tree)->sibling != NULL)
    {
        p = (*tree)->sibling;
        (*tree)->right=p;
        GeneralToBinary(&p);
    }
}

void PreOrderTraversal(struct node *t)
{
    if ((t != NULL))
    {
        printf("%d ", t->data);
        PreOrderTraversal(t->left);
        PreOrderTraversal(t->right);
    }
}
void InOrderTraversal(struct node *t)
{
    if ((t != NULL))
    {
        InOrderTraversal(t->left);
        printf("%d ", t->data);
        InOrderTraversal(t->right);
    }
}

void PostOrderTraversal(struct node *t)
{
    if ((t != NULL))
    {
        PostOrderTraversal(t->left);
        PostOrderTraversal(t->right);
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
    Create_Generaltree(&root);
    GeneralToBinary(&root);

    printf("Pre Order: ");
    PreOrderTraversal(root);
    printf("\n");
    printf("In Order: ");
    InOrderTraversal(root);
    printf("\n");
    printf("Post Order: ");
    PostOrderTraversal(root);
}
