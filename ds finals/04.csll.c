#include <stdio.h>
#include <stdlib.h>
// Node structure
struct Node {
int data;
struct Node *next;
};
// Function to display the circular linked list
void displayList(struct Node *head) {
        if (head == NULL) {
        printf("List is empty.\n");
        return;
}
        struct Node *current = head;
do {
        printf("%d ", current->data);
        current = current->next;
}       while (current != head);
         printf("\n");
}
// Function to insert a node in order
        struct Node* insertByOrder(struct Node *head, int item) {
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = item;
        if (head == NULL) {
        newNode->next = newNode;
        return newNode;
}
        struct Node *current = head;
// Traverse the list to find the correct position to insert
        while (current->next != head && current->next->data < item) {
        current = current->next;
}
// Insert the new node
        newNode->next = current->next;
        current->next = newNode;
// Update head if needed
        if (item < head->data) {
        head = newNode;
}
return head;
}
// Function to delete a node by position
struct Node* deleteByPosition(struct Node *head, int position) {
if (head == NULL) {
printf("List is empty.\n");
return NULL;
}
struct Node *current = head, *prev = NULL;
// Traverse to the specified position
for (int i = 0; i < position; i++) {
prev = current;
current = current->next;
// Check if the position is valid
if (current == head) {
printf("Invalid position.\n");
return head;
}
}
// Update pointers to remove the node
if (prev == NULL) {
// Deleting the head node
head = current->next;
} else {
prev->next = current->next;
}
free(current);
return head;
}
// Function to search for an item by key
int searchByKey(struct Node *head, int key) {
if (head == NULL) {
printf("List is empty.\n");
return -1;
}
struct Node *current = head;
int position = 0;
do {
if (current->data == key) {
return position;
}
current = current->next;
position++;
} while (current != head);
return -1; // Key not found
}
// Function to delete a node by key
// Function to delete a node by key
struct Node* deleteByKey(struct Node *head, int key) {
if (head == NULL) {
printf("List is empty.\n");
return NULL;
}
struct Node *current = head, *prev = NULL;
// Search for the key
do {
if (current->data == key) {
// Update pointers to remove the node
if (prev == NULL) {
// Deleting the head node
if (current->next == head) {
// Only one node in the list
free(current);
return NULL;
}
head = current->next;
// Update the last node's next pointer to maintain circular structure
struct Node *last = head;
while (last->next != current) {
last = last->next;
}
last->next = head;
} else {
prev->next = current->next;
}
free(current);
return head;
}
prev = current;
current = current->next;
} while (current != head);
// Key not found
printf("Key not found.\n");
return head;
}
int main() {
struct Node *head = NULL;
int choice, item, position, key, result;
do {
printf("\nMenu:\n");
printf("1. Insert by order\n");
printf("2. Delete by position\n");
printf("3. Search for an item by key\n");
printf("4. Delete by key\n");
printf("5. Display the list contents\n");
printf("6. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
        printf("Enter item to insert: ");
        scanf("%d", &item);
        head = insertByOrder(head, item);
        displayList(head);
        break;
case 2:
        printf("Enter position to delete: ");
        scanf("%d", &position);
        head = deleteByPosition(head, position);
        displayList(head);
        break;
case 3:
        printf("Enter key to search: ");
        scanf("%d", &key);
        result = searchByKey(head, key);
        if (result != -1) {
        printf("Key %d found at position %d.\n", key, result);
}
break;
case 4:
printf("Enter key to delete: ");
scanf("%d", &key);
head = deleteByKey(head, key);
displayList(head);
break;
case 5:
displayList(head);
break;
case 6:
printf("Exiting program.\n");
break;
default:
printf("Invalid choice. Please enter a valid option.\n");
}
} while (choice != 6);
// Free the memory allocated for the circular linked list before exiting
struct Node *current = head, *temp;
if (head != NULL) {
do {
temp = current->next;
free(current);
current = temp;
} while (current != head);
}
return 0;
}
