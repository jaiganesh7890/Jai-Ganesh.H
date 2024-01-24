//Implement a C Program for a Binary Search Tree - kth min value

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct Node* insertNode(struct Node* root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }
    if (value < root->data)
    {
        root->left = insertNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insertNode(root->right, value);
    }
    return root;
}
void findKthMinValue(struct Node* root, int k, int* count, int* result)
{
    if (root == NULL || *count >= k)
    {
        return;
    }
    findKthMinValue(root->left, k, count, result);
    (*count)++;
    if (*count == k)
    {
        *result = root->data;
        return;
    }
    findKthMinValue(root->right, k, count, result);
}
int kthMinValue(struct Node* root, int k)
{
    int count = 0;
    int result = -1;
    findKthMinValue(root, k, &count, &result);
    return result;
}
int main() {
    struct Node* root = NULL;
    root = insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 7);
    insertNode(root, 2);
    insertNode(root, 4);
    insertNode(root, 6);
    insertNode(root, 8);
    int k = 3;
    int kthMin = kthMinValue(root, k);
    printf("The %dth minimum value in the Binary Search Tree is: %d\n", k, kthMin);
    return 0;
}
