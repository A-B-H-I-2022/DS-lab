#include<stdio.h>
#include<string.h>
#include<malloc.h>
struct node
{
 struct node *r,*l,*p;
 char data;
}*cur,*par,*root=NULL;

void preorder(struct node *);
void postorder(struct node *);
void inorder(struct node *);

int main()
{
  char a[100];
  int len,i,c;
  struct node *new_node;

  printf("Enter the Postfix Expression : ");
  gets(a);
  len=strlen(a);
  for(i=len-1 ; i>=0 ; i--)
  {
   new_node=(struct node *)malloc(sizeof(struct node));
   new_node->data=a[i];
   new_node->l=new_node->r=new_node->p=NULL;
   if(root==NULL)
   {
     root=new_node;
     cur=par=root;
   }
   else
   {
    if(a[i]=='+' ||a[i]=='-' ||a[i]=='*'||a[i]=='/')
    {
     if(par->r==NULL)
     {
      cur=new_node;
      par->r=cur;
      cur->p=par;
      par=cur;
     }
     else if(par->l==NULL)
     {
      cur=new_node;
      par->l=cur;
      cur->p=par;
      par=cur;
     }
    else
    {
     while(par->l!=NULL)
     {
      par=par->p;
     }
     cur=new_node;
     par->l=cur;
     cur->p=par;
     par=cur;
    }
   }
   else
   {
    if(par->r==NULL)
    {
     cur=new_node;
     par->r=cur;
     cur->p=par;
    }
    else if(par->l==NULL)
    {
     cur=new_node;
     par->l=cur;
     cur->p=par;
    }
    else
    {
     while(par->l!=NULL)
     {
      par=par->p;
     }
     cur=new_node;
     par->l=cur;
     cur->p=par;
    }
   }
  }
 }
 while(1)
 {
   printf("\n\nenter the choice :\n1. Inorder \n2. Preorder \n3. Postorder \n4. Exit\n\n");
   scanf("%d",&c);
   if(c==4)
   {
     printf("\n");
     break;
   }
switch(c)
{
 case 1:
 printf("\nInorder Traversal : ");
 inorder(root);
 break;

 case 2:
 printf("\nPreorder Traversal : ");
 preorder(root);
 break;

 case 3:
 printf("\nPostorder Traversal : ");
 postorder(root);
 break;

 case 4:
 break;

 default:
 printf("\nWrong choice....");
 break;
}
}
}

void inorder(struct node *root)
{
 if(root!=NULL)
 {
  inorder(root->l);
  printf("%c ",root->data);
  inorder(root->r);
 }
}
void preorder(struct node *root)
{
 if(root!=NULL)
 {
  printf("%c ",root->data);
  preorder(root->l);
  preorder(root->r);
 }
}
void postorder(struct node *root)
{
 if(root!=NULL)
 {
  postorder(root->l);
  postorder(root->r);
  printf("%c ",root->data);
 }
}
