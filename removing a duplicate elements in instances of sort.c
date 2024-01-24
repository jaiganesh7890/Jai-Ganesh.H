//Write a C program to remove duplicates from a single unsorted linked list.
//Test Data and Expected Output :
//Original Singly List:
//1 2 3 3 4
//After removing duplicate elements from the said singly list:
//1 2 3 4
//Original Singly List:
//1 2 3 3 4 4
//After removing duplicate elements from the said singly list:
//1 2 3 4

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};
void removeDuplicates(struct Node* head)
{
    struct Node* current = head;
    struct Node* next_next;
    if (current == NULL)
    {
        return;
    }
    while (current->next != NULL)
    {
        if (current->data == current->next->data)
        {
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        }
        else
        {
            current = current->next;
        }
    }
}
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}
int main()
{
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(3);
    head->next->next->next->next = newNode(4);
    printf("Original Singly List:\n");
    printList(head);
    removeDuplicates(head);
    printf("After removing duplicate elements from the said singly list:\n");
    printList(head);
    struct Node* temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
