// write a program to perform insertion operation for AVL tree.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data, h;
    struct node *left, *right;
};
struct node *MakeNode(int x)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    p->h = 0;
    return p;
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
int Height(struct node *t)
{
    int hL, hR;
    if (t == NULL)
    {
        return 0;
    }
    if (t->left == NULL)
    {
        hL = 0;
    }
    else
    {
        hL = 1 + (t->left)->h;
    }
    if (t->right == NULL)
    {
        hR = 0;
    }
    else
    {
        hR = 1 + (t->right)->h;
    }
    return Max(hL, hR);
}

struct node *LeftRotation(struct node *x)
{
    struct node *y, *z;
    y = x->right;
    z = y->left;
    y->left = x;
    x->right = z;
    return y;
}
struct node *RightRotation(struct node *x)
{
    struct node *y, *z;
    y = x->left;
    z = y->right;
    y->right = x;
    x->left = z;
    return y;
}
struct node *RR(struct node *x)
{
    struct node *y;
    y = LeftRotation(x);
    return y;
}
struct node *LL(struct node *x)
{
    struct node *y;
    y = RightRotation(x);
    return y;
}
struct node *LR(struct node *x)
{
    struct node *y, *z, *t;
    y = x->left;
    z = LeftRotation(y);
    x->left = z;
    t = RightRotation(x);
    return t;
}
struct node *RL(struct node *x)
{
    struct node *y, *z, *t;
    y = x->right;
    z = RightRotation(y);
    x->right = z;
    t = LeftRotation(x);
    return t;
}

int balanceFactor(struct node *t)
{
    int hL, hR;
    if (t == NULL)
    {
        return 0;
    }
    if (t->left == NULL)
    {
        hL = 0;
    }
    else
    {
        hL = 1 + (t->left)->h;
    }
    if (t->right == NULL)
    {
        hR = 0;
    }
    else
    {
        hR = 1 + (t->right)->h;
    }
    return hL - hR;
}

struct node *Avl_Insert(struct node *t, int x)
{
    if (t == NULL)
    {
        t = MakeNode(x);
    }
    else
    {
        if (x < t->data)
        {
            t->left = Avl_Insert(t->left, x);
            if (balanceFactor(t) == 2)
            {
                if (x < t->left->data)
                {
                    t = LL(t);
                }
                else
                {
                    t = LR(t);
                }
            }
        }
        else
        {
            t->right = Avl_Insert(t->right, x);
            if (balanceFactor(t) == -2)
            {
                if (x > (t)->right->data)
                {
                    t = RR(t);
                }
                else
                {
                    t = RL(t);
                }
            }
        }
    }
    t->h = Height(t);
    return (t);
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

void main()
{
    struct node *root = NULL;
    root = Avl_Insert(root, 1);
    root = Avl_Insert(root, 10);
    root = Avl_Insert(root, 5);
    root = Avl_Insert(root, 9);
    root = Avl_Insert(root, 7);
    root = Avl_Insert(root, 2);
    root = Avl_Insert(root, 3);
    root = Avl_Insert(root, 8);
    root = Avl_Insert(root, 6);
    root = Avl_Insert(root, 4);
    printf("Avl Tree Traversal after Insertion: ");
    InOrderTraversal(root);
}
