// Program for Pre-Order, In-Order, Post-Order Traversal

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

struct node* Create_tree(struct node *t){
    int info,x;
    printf("Enter data of root: ");
    scanf("%d",&info);
    MakeNode(info);
    
    printf("whether left exist(1/0) of %d ?",info);
    scanf("%d",&x);
    if (x==1)
    {
       printf("Enter data: ");
       scanf("%d",info);
       MakeNode(info);
    }
    else
    {
    printf("whether right exist(1/0) of %d ?",info);
    scanf("%d",x);
    if (x==1)
    {
       printf("Enter data: ");
       scanf("%d",info);
       MakeNode(info);
    }
    else
    {
        return 0;
    }
    
    }
}

void PreOrderTraversal(struct node *t)
{
    if ((t != NULL))
    {
        printf("%c ", t->data);
        PreOrderTraversal(t->left);
        PreOrderTraversal(t->right);
    }
}
void InOrderTraversal(struct node *t)
{
    if ((t != NULL))
    {
        InOrderTraversal(t->left);
        printf("%c ", t->data);
        InOrderTraversal(t->right);
    }
}

void PostOrderTraversal(struct node *t)
{
    if ((t != NULL))
    {
        PostOrderTraversal(t->left);
        PostOrderTraversal(t->right);
        printf("%c ", t->data);
    }
}

int main()
{
    struct node *t = NULL,*root;
    root=Create_tree(&t);
   
    
   
    
    printf("Pre Order: ");
    PreOrderTraversal(root);
    printf("\n");
    printf("In Order: ");
    InOrderTraversal(root);
    printf("\n");
    printf("Post Order: ");
    PostOrderTraversal(root);
}
