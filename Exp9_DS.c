#include<stdio.h>
#include<malloc.h>
#define NODE struct node
NODE{
    int data;
    NODE* next;
};

void stackdisplay(NODE *top)
{
    printf("\nSTACK : ");
    for(;top!=NULL;top=top->next)
        printf("\n\t%d ",top->data);
    putchar('\n');
}

void queuedisplay(NODE* front)
{
    printf("\nQUEUE : ");
    for(;front!=NULL;front=front->next)
        printf("%d ",front->data);
    putchar('\n');

}
int main(){
NODE *top=NULL,*front=NULL,*rear=NULL;
NODE *temp=NULL;
int item;
int c;
do
{
    printf("\nEnter your choice : \n1.Push in stack\n2.Pop stack\n3.Insert in queue\n4.Delete queue\n5.Exit\n");
    scanf("%d",&c);
    if(c==5)
    {
      printf("Exited.");
      break;
    }
    switch(c)
    {
        case 1:
        temp=(NODE*)malloc(sizeof(NODE));
        printf("Input the data in stack : ");
        scanf("%d",&item);
        temp->data=item;

        if(top==NULL)
        {
            top=temp;
            top->next=NULL;
        }
        else
        {
            temp->next=top;
            top=temp;
        }
        stackdisplay(top);
        break;

        case 2:

        temp=top;
        if(temp==NULL)
            printf("\nStack is empty\n");
        else
        {
            printf("\n%d popped\n",top->data);
            top=top->next;
            free(temp);
        }
        stackdisplay(top);
        break ;

        case 3:
        temp=(NODE*)malloc(sizeof(NODE));
        printf("Input the data in queue : ");
        scanf("%d",&item);
        temp->data=item;
        temp->next=NULL;

        if(front==NULL)
            rear=front=temp;
        else
        {
            rear->next=temp;
            rear=temp;
        }
        queuedisplay(front);
        break;

        case 4:
        if(front==NULL)
            printf("\nQueue is empty\n");
        else
        {
            temp=front;
            front=front->next;
            printf("\n%d popped\n",temp->data);
            free(temp);
        }
        queuedisplay(front);
        break;

        case 5:
        break;
    }
}
while(c);
return 0;
}
