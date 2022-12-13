// Program to find Node Count in the Binary Tree

#include <stdio.h>
#include <stdlib.h>

struct node
{
    char data;
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

int Count(struct node *tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    else
    {
        return (1 + Count(tree->left) + Count(tree->right));
    }
}

void main()
{
    struct node *root = NULL;
    int x;
    root = MakeNode('A');
    root->left = MakeNode('B');
    root->right = MakeNode('C');
    root->left->left = MakeNode('F');
    root->right->left = MakeNode('D');
    root->right->right = MakeNode('E');
    printf("Total Number of nodes: ");
    x = Count(root);
    printf("%d",x);

}
