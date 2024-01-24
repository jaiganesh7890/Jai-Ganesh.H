//Write a C program to find the maximum element in a queue. >
//Expected Output:

//Queue elements are: 1 2 3 4 5
//Maximum value in the queue is: 5

//Remove 2 elements from the said queue:
//Queue elements are: 3 4 5
//Maximum value in the queue is: 5

//Insert 3 more elements:
//Queue elements are: 3 4 5 600 427 519
//Maximum value in the queue is: 600

#include <stdio.h>
#define MAX_SIZE 100
struct Queue
{
    int items[MAX_SIZE];
    int front;
    int rear;
};
void enqueue(struct Queue *q, int value)
{
    if (q->rear == MAX_SIZE - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        if (q->front == -1)
        {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
    }
}
void dequeue(struct Queue *q)
{
    if (q->front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Dequeued element: %d\n", q->items[q->front]);
        if (q->front == q->rear)
        {
            q->front = -1;
            q->rear = -1;
        }
        else
        {
            q->front++;
        }
    }
}
int getMax(struct Queue q)
{
    int max = q.items[q.front];
    for (int i = q.front + 1; i <= q.rear; i++)
    {
        if (q.items[i] > max)
        {
            max = q.items[i];
        }
    }
    return max;
}
void display(struct Queue q)
{
    if (q.front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements are: ");
        for (int i = q.front; i <= q.rear; i++)
        {
            printf("%d ", q.items[i]);
        }
        printf("\n");
    }
}
int main()
{
    struct Queue q;
    q.front = -1;
    q.rear = -1;
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    printf("Queue elements are: ");
    display(q);
    printf("Maximum value in the queue is: %d\n", getMax(q));
    dequeue(&q);
    dequeue(&q);
    printf("Queue elements are: ");
    display(q);
    printf("Maximum value in the queue is: %d\n", getMax(q));
    enqueue(&q, 600);
    enqueue(&q, 427);
    enqueue(&q, 519);
    printf("Queue elements are: ");
    display(q);
    printf("Maximum value in the queue is: %d\n", getMax(q));
    return 0;
}
