// write a program to implement Insertion and Search operation in BST (Iterative)

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
        }
        else
        {
            q->right = MakeNode(x);
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
            BinarySearch(t, key);
        }
        else if (key > t->data)
        {
            t = t->right;
            BinarySearch(t, key);
        }
        else
        {
            break;
            ;
        }
    }
    return t;
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
    printf("\nEnter key to search: ");
    scanf("%d", &key);
    if (BinarySearch(root, key) != NULL)
    {
        printf("Yes");
    }
    else
    {
        printf("no");
    }
}
