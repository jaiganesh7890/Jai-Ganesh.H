//Implement a C Program for AVL tree – Insertion of Nodes
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};
int getHeight(struct Node* node)
{
    if (node == NULL)
        return 0;
    return node->height;
}
int max(int a, int b)
{
    return (a > b) ? a : b;
}
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}
struct Node* rightRotate(struct Node* y)
{
    struct Node* x = y->left;
    struct Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}
struct Node* leftRotate(struct Node* x)
{
    struct Node* y = x->right;
    struct Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}
int getBalanceFactor(struct Node* node)
{
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}
struct Node* insertNode(struct Node* node, int data)
{
    if (node == NULL)
        return createNode(data);
    if (data < node->data)
        node->left = insertNode(node->left, data);
    else if (data > node->data)
        node->right = insertNode(node->right, data);
    else
        return node;
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balanceFactor = getBalanceFactor(node);
    if (balanceFactor > 1 && data < node->left->data)
        return rightRotate(node);
    if (balanceFactor < -1 && data > node->right->data)
        return leftRotate(node);
    if (balanceFactor > 1 && data > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balanceFactor < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
void inorderTraversal(struct Node* root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}
int main()
{
    struct Node* root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 25);
    printf("Inorder traversal of the AVL tree: ");
    inorderTraversal(root);
    return 0;
}

