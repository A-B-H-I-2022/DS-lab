 #include<stdio.h>
int main()
{
  int c , a[20], i , n , x , y , first , last , middle ;
  printf("enter the number of elements in the array : ");
  scanf("%d",&n);
  printf("\nenter the elements  in accending order : \n");
  for(i=0 ; i<n ; i++)
  {
    scanf("%d",&a[i]);
  }
  while(1)
  {
  printf("\n\nenter your choice : \n1: linear search \n2: binary search \n3: exit\n\n");
  scanf("%d",&c);
  printf("\n");
  if(c==3)
  {
    printf("exit....!!\n");
    break;
  }
  switch(c)
  {
    case 1:
           printf("Enter the element to be searched : ");
           scanf("%d", &x);
           for (i = 0; i < n; i++)
  {
    if (a[i] == x)
    {
      printf("%d is present at location %d.\n", x, i+1);
      break;
    }
  }
  if (i == n)
    printf("%d isn't present in the array.\n", x);
          break;
    case 2:
           printf("Enter value to find\n");
           scanf("%d", &y);
           first = 0;
           last = n - 1;
           middle = (first+last)/2;
           while (first <= last)
           {
             if (a[middle] < y)
                first = middle + 1;
             else if (a[middle] == y) {
                printf("%d found at location %d.\n", y, middle+1);
                break;
          }
          else
          last = middle - 1;
          middle = (first + last)/2;
          }
          if (first > last)
          printf("%d is not present in the array...\n", y);
         break;
    case 3:
           break;
    default:
            printf("wrong entry.....!!");
            break;
  }
  }
}
