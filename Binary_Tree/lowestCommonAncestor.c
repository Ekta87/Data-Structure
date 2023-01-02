// Lowest Common Ancestor in a Binary Tree
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

struct node *lca(struct node *t, int x, int y)
{
    struct node *L, *R;
    if (t == NULL)
    {
        return NULL;
    }
    else if (t->data == x || t->data == y)
    {
        return t;
    }
    else
    {
        L = lca(t->left, x, y);
        R = lca(t->right, x, y);
        if (L == NULL)
        {
            return R;
        }
        else if (R == NULL)
        {
            return L;
        }
        else
        {
            return t;
        }
    }
}

int main()
{
    struct node *root;
    root = NULL;
    int info;
    printf("Enter data of root: ");
    scanf("%d", &info);
    root = MakeNode(info);
    Create_tree(&root);
    int x, y;
    struct node *p;
    printf("Enter elements x and y: ");
    scanf("%d %d", &x, &y);
    p = lca(root, x, y);
    printf("%d", p->data);
}
