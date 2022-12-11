#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *tree;
void create(struct node *);
struct node *insert(struct node *,int);
void preorder(struct node *);
int main()
{
    
    create(tree);
    insert(tree,70);
    insert(tree,60);
    insert(tree,80);
    insert(tree,50);
    insert(tree,65);
    preorder(tree);
    return 0;
}
void create(struct node *tree)
{
    tree=NULL;
}
struct node *insert(struct node *tree,int val)
{
    if (tree==NULL)
    {
        tree=(struct node*)malloc(sizeof(struct node));
        tree->data=val;
        tree->left=NULL;
        tree->right=NULL;
        return tree;
    }
    else
    {
        if(val<tree->data)
        {
            tree->left=insert(tree->left,val);
            
        }
        else
        {
            tree->right=insert(tree->right,val);
        }
    }
    
}
void preorder(struct node *tree)
{
    while(tree!=NULL)
    {
        printf("%d",tree->data);
        printf("   ");
        preorder(tree->left);
        preorder(tree->right);
    }
}