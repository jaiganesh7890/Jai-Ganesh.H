//Implement a C Program to Reverse – SLL

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};
void reverseLinkedList(struct Node** head)
{
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}
void insertAtBeginning(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}
void displayLinkedList(struct Node* head)
{
    struct Node* temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    struct Node* head = NULL;
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);
    printf("Original Linked List: ");
    displayLinkedList(head);
    reverseLinkedList(&head);
    printf("Reversed Linked List: ");
    displayLinkedList(head);
    return 0;
}
