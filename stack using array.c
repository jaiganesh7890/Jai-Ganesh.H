#include<stdio.h>
#include<stdlib.h>
#define size 100
void push(int value);
void pop();
void display();

int stack[size],top=-1;
int main()
{
    int value,ch;
    while(5)
    {
        printf("\n..............menu...............\n");
        printf("1.push\n2.pop\n3.display");
        printf("\nenter the choice....");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("enter the value to inserted...");
            scanf("%d",&value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        default:
            printf("wrong choice...");
        }
    }
}
void push(int value)
{
    if(top==size-1)
    {
        printf("stack is full...");
    }
    else
    {
        top++;
        stack[top]=value;
        printf("value have been inserted successfully..");
    }
}
void pop()
{
    if(top==-1)
    {
        printf("empty stack..");
    }
    else
    {
      printf("deleted element:%d",stack[top]);
      top--;
    }
}
void display()
{
  if(top==-1)
    {
        printf("stack is empty..");
    }
    else
    {
        for(int i=top;i>=0;i--)
        {
            printf("%d ",stack[i]);
        }
    }
}

