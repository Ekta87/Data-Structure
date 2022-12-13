// Program to find if the given Binary Tree is strictly

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

void BinaryTree(struct node *tree)
{
    if (Count_n1(tree) == 0)
    {
        printf("Stirctly a Binary Tree");
    }
    else
    {
        printf("Not a Binary Tree");
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
    root->right->left->left = MakeNode(8);
    root->right->left->right = MakeNode(9);
    root->right->right = MakeNode(6);
    BinaryTree(root);
}
