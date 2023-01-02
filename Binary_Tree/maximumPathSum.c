// Maximum root to leaf path Sum

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

int Max(int left, int right)
{
    if (left > right)
    {
        return left;
    }
    else
    {
        return right;
    }
}

int mps(struct node *t)
{
    int L, R;
    if (t == NULL)
    {
        return 0;
    }
    else if (t->left == NULL && t->right == NULL)
    {
        return t->data;
    }
    else
    {
        L = mps(t->left);
        R = mps(t->right);
        return t->data + Max(L, R);
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

    printf("%d", mps(root));
}
