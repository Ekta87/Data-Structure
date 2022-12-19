// write a program to implement Insertion and Search operation in BST (Iterative)

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right, *father;
};
struct node *MakeNode(int x)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    p->father = NULL;
    return p;
}

int BST_Insert(struct node **t, int x)
{
    struct node *p, *q;
    p = *t;
    q = NULL;
    if ((*t) == NULL)
    {
        (*t) = MakeNode(x);
    }
    else
    {
        while (p != NULL)
        {
            q = p;
            if (x < p->data)
            {
                p = p->left;
            }
            else
            {
                p = p->right;
            }
        }

        if (x < q->data)
        {
            q->left = MakeNode(x);
            q->left->father = q;
        }
        else
        {
            q->right = MakeNode(x);
            q->right->father = q;
        }
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

struct node *BinarySearch(struct node *t, int key)
{
    while (t != NULL)
    {
        if (key < t->data)
        {
            t = t->left;
        }
        else if (key > t->data)
        {
            t = t->right;
        }
        else
        {
            return t;
        }
    }
}

struct node *Max(struct node *t)
{
    while (t->right != NULL)
    {
        t = t->right;
    }
    printf("%d", t->data);
}

struct node *Min(struct node *t)
{
    while (t->left != NULL)
    {
        t = t->left;
    }
    return t;
}

struct node *successor(struct node *p)
{
    struct node *q;
    if (p->right == NULL)
    {
        q = p->father;
        while (q != NULL && q->right == p)
        {
            p = q;
            q = q->father;
        }
    }
    else
    {
        q = Min(p->right);
    }

    return q;
}

struct node *predecessor(struct node *p)
{
    struct node *q;
    if (p->left == NULL)
    {
        q = p->father;
        while (q != NULL && q->left == p)
        {
            p = q;
            q = q->father;
        }
    }
    else
    {
        q = Max(p->left);
    }

    return q;
}

void main()
{
    struct node *root = NULL;
    BST_Insert(&root, 100);
    BST_Insert(&root, 50);
    BST_Insert(&root, 70);
    BST_Insert(&root, 130);
    BST_Insert(&root, 150);
    BST_Insert(&root, 20);
    BST_Insert(&root, 40);
    printf("Binary Search Tree after Insertion: ");
    InOrderTraversal(root);
    int key;
    printf("\nEnter key: ");
    scanf("%d", &key);
    struct node *p, *s, *r;
    p = BinarySearch(root, key);
    printf("Successor of %d : ", key);
    s = successor(p);
    if (s != NULL)
    {
        printf("%d", s->data);
    }
    else
    {
        printf("Doesn't exist");
    }
    printf("\nPredecessor of %d : ", key);
    r = predecessor(p);
    if (r != NULL)
    {
        printf("%d", r->data);
    }
    else
    {
        printf("Doesn't exist");
    }
}
