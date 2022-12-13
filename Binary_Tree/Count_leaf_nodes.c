// Program to find leaf node Count in the Binary Tree

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};
struct node *MakeNode(char x)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

int Count_leaf(struct node *tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    else if ((tree->left == NULL) && (tree->right == NULL))
    {
        return 1;
    }
    else
    {
        return Count_leaf(tree->left) + Count_leaf(tree->right);
    }
}

void main()
{
    struct node *root = NULL;
    int x;
    root = MakeNode(1);
    root->left = MakeNode(2);
    root->right = MakeNode(3);
    root->left->left = MakeNode(5);
    root->right->left = MakeNode(4);
    root->right->right = MakeNode(6);
    printf("Total Number of leaf nodes: ");
    x = Count_leaf(root);
    printf("%d", x);
}
