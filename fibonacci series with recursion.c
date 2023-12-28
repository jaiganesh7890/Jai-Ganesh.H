#include<stdio.h>
int fibonacci(int a)
{
  if (a==0)
    return 0;
  else if(a==1)
    return 1;
  else
    return (fibonacci(a-1)+fibonacci(a-2));
}
int main()
{
  int a,i,fib;
  printf("\n enter the fibonacci length:");
  scanf("%d",&a);
  printf("fibonacci series are:");
  for(i=0;i<a;i++)
  {
    fib=fibonacci(i);
    printf("%d\t",fib);
  }
  return 0;
}
