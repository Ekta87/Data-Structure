// Recursive Creation of Binary Tree

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};
struct node *MakeNode(int x)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void Create_tree(struct node **tree)
{
    struct node *p;
    int x, info;
    printf("whether left exist of %d ?(1/0)", (*tree)->data);
    scanf("%d", &x);
    if (x == 1)
    {
        printf("Enter data: ");
        scanf("%d", &info);
        p = MakeNode(info);
        (*tree)->left = p;
        Create_tree(&p);
    }

    printf("whether right exist of %d ?(1/0)", (*tree)->data);
    scanf("%d", &x);
    if (x == 1)
    {
        printf("Enter data: ");
        scanf("%d", &info);
        p = MakeNode(info);
        (*tree)->right = p;
        Create_tree(&p);
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
