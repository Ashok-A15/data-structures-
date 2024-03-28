#include <stdio.h>
#include <stdlib.h>
struct Node {
int key;
struct Node *left, *right;
};
struct Node* createNode(int key) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->key = key;
newNode->left = newNode->right = NULL;
return newNode;
}
struct Node* insert(struct Node* root, int key) {
if (root == NULL)
return createNode(key);
if (key < root->key)
root->left = insert(root->left, key);
else if (key > root->key)
root->right = insert(root->right, key);
return root;
}
void inorderTraversal(struct Node* root) {
if (root != NULL) {
inorderTraversal(root->left);
printf("%d ", root->key);
inorderTraversal(root->right);
}
}
void preorderTraversal(struct Node* root) {
        if (root != NULL) {
        printf("%d ", root->key);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
}
}
void postorderTraversal(struct Node* root) {
        if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->key);
}
}
struct Node* searchNode(struct Node* root, int key) {
        if (root == NULL || root->key == key)
        return root;
        if (key < root->key)
        return searchNode(root->left, key);
        return searchNode(root->right, key);
}
struct Node* minValueNode(struct Node* node) {
        struct Node* current = node;
        while (current->left != NULL)
        current = current->left;
        return current;
}
struct Node* deleteNode(struct Node* root, int key) {
        if (root == NULL)
        return root;
        if (key < root->key)
        root->left = deleteNode(root->left, key);
        else if (key > root->key)
        root->right = deleteNode(root->right, key);
        else {
        if (root->left == NULL) {
        struct Node* temp = root->right;
        free(root);
        return temp;
        } else if (root->right == NULL) {
        struct Node* temp = root->left;
        free(root);
        return temp;
}
struct Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
}
return root;
}
void menu() {
        printf("\n1. Insert a node");
        printf("\n2. Inorder Traversal");
        printf("\n3. Preorder Traversal");
        printf("\n4. Postorder Traversal");
        printf("\n5. Search and Delete a node by key");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
}
int main() {
        struct Node* root = NULL;
int choice, key;
        do {
        menu();
        scanf("%d", &choice);
switch (choice) {
case 1:
        printf("Enter key to insert: ");
        scanf("%d", &key);
        root = insert(root, key);
        break;
case 2:
        printf("Inorder Traversal: ");
        inorderTraversal(root);
        printf("\n");
        break;
case 3:
        printf("Preorder Traversal: ");
        preorderTraversal(root);
        printf("\n");
        break;
case 4:
        printf("Postorder Traversal: ");
        postorderTraversal(root);
        printf("\n");
        break;
case 5:
        printf("Enter key to search and delete: ");
        scanf("%d", &key);
        if (searchNode(root, key) != NULL) {
        root = deleteNode(root, key);
        printf("Node with key %d deleted successfully.\n", key);
        } else {
        printf("Node with key %d not found.\n", key);
}
break;
case 6:
        printf("Exiting program.\n");
        break;
default:
        printf("Invalid choice. Please enter a valid option.\n");
}
} while (choice != 6);
return 0;
}
