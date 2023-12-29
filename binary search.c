#include<stdio.h>
int main()
{
  int size,arr[size],se;
  printf("enter the size:");
  scanf("%d",&size);
  printf("enter the elemnts in ascending order:");
  for(int i=0;i<size;i++)
  scanf("%d",&arr[i]);
  printf("enter the search element:");
  scanf("%d",&se);
  int fe=0,mid,le=size-1;
  mid=(fe+le)/2;
  while(fe<=le)
  {
      if(arr[mid]<se)
      {
        fe=mid+1;
        mid=(fe+le)/2;
      }
      else if(arr[mid]==se)
      {
        printf("element is found in %d position",mid);
        break;
      }
      else
      {
          le=mid-1;
          mid=(fe+le)/2;
      }
  }
  if(fe>size)
  {
      printf("elemeny is not found in array");
  }
  return 0;

}
