//Write a C program to merge two sorted singly linked lists into a single sorted linked list.
//Test Data and Expected Output :
//Two sorted singly linked lists:
//1 3 5 7
//2 4 6
//After merging the said two sorted lists:
//1 2 3 4 5 6 7


#include <stdio.h>
#include <stdlib.h>

// Node structure for a singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of a linked list
void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to merge two sorted linked lists into a single sorted linked list
struct Node* mergeLists(struct Node* list1, struct Node* list2) {
    // Create a dummy node as the starting point of the merged list
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    // Traverse both lists and compare the nodes
    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    // Append the remaining nodes of the non-empty list
    if (list1 != NULL) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }

    // Return the head of the merged list
    return dummy.next;
}

// Function to print the elements of a linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Create the first sorted linked list
    struct Node* list1 = NULL;
    insert(&list1, 7);
    insert(&list1, 5);
    insert(&list1, 3);
    insert(&list1, 1);

    // Create the second sorted linked list
    struct Node* list2 = NULL;
    insert(&list2, 6);
    insert(&list2, 4);
    insert(&list2, 2);

    // Merge the two sorted linked lists
    struct Node* mergedList = mergeLists(list1, list2);

    // Print the merged list
    printf("Merged List: ");
    printList(mergedList);

    return 0;
}
