//Write a C program to find the intersection of two singly linked lists.
//Test Data and Expected Output :
//Original lists:
//1 2 3 4
//5 3 4
//Intersection found at 3.
//Original lists:
//1 2 3 4
//5 3 4
//Intersection not found.

#include <stdio.h>
#include <stdlib.h>

// Node structure for a singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to find the intersection of two linked lists
struct Node* findIntersection(struct Node* list1, struct Node* list2) {
    struct Node* ptr1 = list1;
    struct Node* ptr2 = list2;

    // Traverse both lists until they intersect or reach the end
    while (ptr1 != ptr2) {
        // If ptr1 reaches the end of list1, move it to the head of list2
        if (ptr1 == NULL) {
            ptr1 = list2;
        } else {
            ptr1 = ptr1->next;
        }

        // If ptr2 reaches the end of list2, move it to the head of list1
        if (ptr2 == NULL) {
            ptr2 = list1;
        } else {
            ptr2 = ptr2->next;
        }
    }

    return ptr1;
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print a linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // Create the first linked list
    struct Node* list1 = createNode(1);
    list1->next = createNode(2);
    list1->next->next = createNode(3);
    list1->next->next->next = createNode(4);

    // Create the second linked list
    struct Node* list2 = createNode(5);
    list2->next = createNode(3);
    list2->next->next = createNode(4);

    // Print the original lists
    printf("Original lists:\n");
    printList(list1);
    printList(list2);

    // Find the intersection of the two lists
    struct Node* intersection = findIntersection(list1, list2);

    // Print the result
    if (intersection != NULL) {
        printf("Intersection found at %d.\n", intersection->data);
    } else {
        printf("Intersection not found.\n");
    }

    return 0;
}
