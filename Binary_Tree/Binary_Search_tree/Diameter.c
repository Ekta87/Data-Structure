// Program to find the diameter of the Binary Tree (distance between the farthest node)
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
int Height(struct node *tree)
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
        return 1 + Max(Height(tree->left), Height(tree->right));
    }
}
int max(int d1, int d2,int d3)
{
    if (d1 > d2)
    {
       if (d1>d3)
       {
        return d1;
       }
       else
       {
        return d3;
       }
    }
    else
    {
        if (d2>d3)
        {
            return d2;
        }
        else
        {
            return d3;
        }
    }
}
int diameter(struct node *t){
    int d1,d2,d3;
    if (t==NULL)
    {
        return 0;
    }
    else
    {
        d1= Height(t->left)+Height(t->right)+1;
        d2= diameter(t->left);
        d3= diameter(t->right);
        return max(d1,d2,d3);
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
    printf("%d",diameter(root));
    

}
