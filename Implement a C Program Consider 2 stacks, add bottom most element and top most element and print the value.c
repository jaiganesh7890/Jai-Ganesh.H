//Implement a C Program Consider 2 stacks, add bottom most element and top most element and print the value

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack
{
    int top;
    int items[MAX_SIZE];
};
void initialize(struct Stack* stack)
{
    stack->top = -1;
}
int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}
int isFull(struct Stack* stack)
{
    return stack->top == MAX_SIZE - 1;
}
void push(struct Stack* stack, int item)
{
    if (isFull(stack))
    {
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++stack->top] = item;
}
int pop(struct Stack* stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->items[stack->top--];
}
void addAndPrint(struct Stack* stack1, struct Stack* stack2)
{
    if (isEmpty(stack1) || isEmpty(stack2))
    {
        printf("One or both stacks are empty\n");
        return;
    }
    int bottom1 = pop(stack1);
    int top2 = pop(stack2);
    int sum = bottom1 + top2;
    printf("Sum: %d\n", sum);
}

int main()
{
    struct Stack stack1, stack2;
    initialize(&stack1);
    initialize(&stack2);
    push(&stack1, 10);
    push(&stack1, 20);
    push(&stack1, 30);
    push(&stack2, 40);
    push(&stack2, 50);
    push(&stack2, 60);
    addAndPrint(&stack1, &stack2);

    return 0;
}
