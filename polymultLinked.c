#include<stdio.h>
#include<stdlib.h>

struct node {
  int coef, expo;
  struct node *next;
};

struct node *hPtr1, *hPtr2, *hPtr3;
struct node * buildNode(int coef, int expo)
 {
  struct node *ptr = (struct node *) malloc(sizeof (struct node));
  ptr->coef = coef;
  ptr->expo = expo;
  ptr->next = NULL;
  return ptr;
}

void poly_insert(struct node ** myNode, int coef, int expo)
 {
  struct node *lPtr, *pPtr, *qPtr = *myNode;
  lPtr = buildNode(coef, expo);

  if (*myNode == NULL || (*myNode)->expo < expo)
  {
    *myNode = lPtr;
    (*myNode)->next = qPtr;
    return;
  }

  while (qPtr) {
    pPtr = qPtr;
    qPtr = qPtr->next;
    if (!qPtr) {
      pPtr->next = lPtr;
      break;

    }
    else if ((expo < pPtr->expo) && (expo > qPtr->expo))
      {
    lPtr->next = qPtr;
    pPtr->next = lPtr;
    break;
      }
      }
    return;
  }


  void poly_add(struct node **n1, int coef, int expo)
   {
    struct node *x = NULL, *temp = *n1;
    if (*n1 == NULL || (*n1)->expo < expo)
    {

      *n1 = x = buildNode(coef, expo);
      (*n1)->next = temp;
    }
     else {
      while (temp) {
    if (temp->expo == expo)
    {

      temp->coef = temp->coef + coef;
      return;
    }
    if (temp->expo > expo && (!temp->next || temp->next->expo < expo))
    {

      x = buildNode(coef, expo);
      x->next = temp->next;
      temp->next = x;
      return;
    }
    temp = temp->next;
      }
      x->next = NULL;
      temp->next = x;
    }
  }

  void poly_multiply(struct node **n1, struct node *n2, struct node *n3)
  {
    struct node * temp;
    int coef, expo;

    temp = n3;

    if (!n2 && !n3)
      return;
    if (!n2) 
      *n1 = n3;
    else if (!n3)
      *n1 = n2;
    else 
    {
      while (n2) 
      {
       while (n3) 
       {
        coef = n2->coef * n3->coef;
        expo = n2->expo + n3->expo;
        n3 = n3->next;
        poly_add(n1, coef, expo);
       }
      n3 = temp;
      n2 = n2->next;
      }
    }
    return;
  }

  struct node * poly_deleteList(struct node *ptr)
  {
    struct node *temp;
    while (ptr){
      temp = ptr->next;
      free(ptr);
      ptr = temp;
    }
    return NULL;
  }

  void poly_view(struct node *ptr)
  {
    int i = 0;
    int flag=0;
    while (ptr) {
      if(ptr->expo != 0 || ptr->expo != 1 )
      {
    if(ptr->coef > 0 && flag==0 )
    {
      if(ptr->expo !=0)
      {
      printf("%dx^%d ", ptr->coef,ptr->expo);
      }
      else
      {
        printf("%d", ptr->coef);
      }
      flag++;
    }
    else if (ptr->coef > 0 && flag==1 )
    {
      if(ptr->expo !=0)
      {
      printf("+%dx^%d", ptr->coef,ptr->expo);
      }
      else
      {
        printf("+%d", ptr->coef);
      }
    }
    else if(ptr->coef < 0)
    {
      if(ptr->expo !=0)
      {
      printf("%dx^%d", ptr->coef,ptr->expo);
      }
      else
      {
        printf("%d", ptr->coef);
      }
    }
    }
      else if (ptr->expo == 0)
      {
    if(ptr->coef > 0 && flag==0 )
    {
      printf("%d", ptr->coef);
      flag++;
    }
    else if (ptr->coef > 0 && flag==1 )
      printf("+%d", ptr->coef);
    else if(ptr->coef < 0)
      printf("%d", ptr->coef);
      }
      else if( ptr->expo == 1 ){
    if(ptr->coef > 0 && flag==0 )
    {
      printf("%dx", ptr->coef);
      flag++;
    }
    else if (ptr->coef > 0 && flag==1 )
      printf("+%dx", ptr->coef);
    else if(ptr->coef < 0)
      printf("%dx", ptr->coef);
      }
      ptr = ptr->next;
      i++;
    }
    printf("\n");
    return;
  }

  int main (int argc, char *argv[])
  {
    int coef, expo, i, n;
    int count;
    printf("Enter the number of coefficients in the first polynomial : ");
    scanf("%d",&count);
    for(i=0;i<count;i++){
      printf("Enter the coef part: ");
      scanf("%d", &coef);
      printf("Enter the expo part: ");
      scanf("%d",&expo);
          poly_insert(&hPtr1, coef, expo);
    }
    printf("Enter the number of coefficients in the second polynomial : ");
    scanf("%d",&count);
    for(i=0;i<count;i++){
      printf("Enter the coef part:");
      scanf("%d", &coef);
      printf("Enter the expo part:");
      scanf("%d",&expo);
          poly_insert(&hPtr2, coef, expo);
    }
        printf("\n Polynomial Expression 1: ");
        poly_view(hPtr1);
        printf("\n Polynomial Expression 2: ");
        poly_view(hPtr2);

        poly_multiply(&hPtr3, hPtr1, hPtr2);

        printf("\nOutput : ");
        poly_view(hPtr3);
        hPtr1 = poly_deleteList(hPtr1);
        hPtr2 = poly_deleteList(hPtr2);
        hPtr3 = poly_deleteList(hPtr3);
        printf("\n");
        return 0;
}