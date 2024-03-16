#include <stdio.h>
#include <stdlib.h>
struct Node {
int key;
struct Node *left, *right, *parent;
};
struct Node* createNode(int key) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->key = key;
newNode->left = newNode->right = newNode->parent = NULL;
return newNode;
}
struct Node* insert(struct Node* root, int key) {
if (root == NULL)
return createNode(key);
if (key < root->key) {
struct Node* leftChild = insert(root->left, key);
root->left = leftChild;
leftChild->parent = root;
} else if (key > root->key) {
struct Node* rightChild = insert(root->right, key);
root->right = rightChild;
rightChild->parent = root;
}
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
void displayNodeInfo(struct Node* node) {
if (node != NULL) {
printf("Node with key %d found.\n", node->key);
if (node->parent != NULL) {
printf("Parent: %d\n", node->parent->key);
} else {
printf("No parent (root node).\n");
}
} else {
printf("Node not found.\n");
}
}
int countNodes(struct Node* root) {
if (root == NULL)
return 0;
return 1 + countNodes(root->left) + countNodes(root->right);
}
int findHeight(struct Node* root) {
if (root == NULL)
return -1;
int leftHeight = findHeight(root->left);
int rightHeight = findHeight(root->right);
return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}
struct Node* findMaxNode(struct Node* root) {
if (root == NULL || root->right == NULL)
return root;
return findMaxNode(root->right);
}
void displayMaxNodeInfo(struct Node* maxNode) {
if (maxNode != NULL) {
printf("Node with maximum key value: %d\n", maxNode->key);
if (maxNode->parent != NULL) {
printf("Parent: %d\n", maxNode->parent->key);
} else {
printf("No parent (root node).\n");
}
} else {
printf("Tree is empty.\n");
}
}
void menu() {
printf("\n1. Insert a node");
printf("\n2. Inorder Traversal");
printf("\n3. Preorder Traversal");
printf("\n4. Postorder Traversal");
printf("\n5. Search and Display node by key");
printf("\n6. Count all nodes");
printf("\n7. Find height of the tree");
printf("\n8. Find node with Maximum key value");
printf("\n9. Exit");
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
printf("Enter key to search and display: ");
scanf("%d", &key);
displayNodeInfo(searchNode(root, key));
break;
case 6:
printf("Total nodes in the tree: %d\n", countNodes(root));
break;
case 7:
printf("Height of the tree: %d\n", findHeight(root));
break;
case 8:
displayMaxNodeInfo(findMaxNode(root));
break;
case 9:
printf("Exiting program.\n");
break;
default:
printf("Invalid choice. Please enter a valid option.\n");
}
} while (choice != 9);
return 0;
}
