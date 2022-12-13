// Program to Find if the given Binary Tree is complete

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

int Count_n1(struct node *tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    else if ((tree->left == NULL) && (tree->right == NULL))
    {
        return 0;
    }
    else if ((tree->left != NULL) && (tree->right != NULL))
    {
        return Count_n1(tree->left) + Count_n1(tree->right);
    }
    else
    {
        return 1 + Count_n1(tree->left) + Count_n1(tree->right);
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

int Height(struct node *tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    else if ((tree->left == NULL) && (tree->right == NULL))
    {
        return 0;
    }
    else
    {
        return 1 + Max(Height(tree->left), Height(tree->right));
    }
}

void Complete_BinaryTree(struct node *tree)
{
    if ((Count_n1(tree) == 0) && (Height(tree->left) == Height(tree->right)))
    {
        printf("A Complete Binary Tree");
    }
    else
    {
        printf("Not a Complete Binary Tree");
    }
}

void main()
{
    struct node *root = NULL;
    root = MakeNode(1);
    root->left = MakeNode(2);
    root->right = MakeNode(3);
    root->left->left = MakeNode(5);
    root->left->right = MakeNode(7);
    root->right->left = MakeNode(4);
    root->right->right = MakeNode(6);
    Complete_BinaryTree(root);
}
