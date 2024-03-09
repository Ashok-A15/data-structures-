#include <stdio.h>
#include <stdlib.h>
// Node structure
struct Node {
int data;
struct Node *prev;
struct Node *next;
};
// Function to display the circular doubly linked list
void displayList(struct Node *head) {
if (head == NULL) {
printf("List is empty.\n");
return;
}
struct Node *current = head;
do {
printf("%d ", current->data);
current = current->next;
} while (current != head);
printf("\n");
}
// Function to insert a node in order
struct Node* insertByOrder(struct Node *head, int item) {
struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = item;
if (head == NULL) {
newNode->prev = newNode;
newNode->next = newNode;
return newNode;
}
struct Node *current = head;
// Traverse the list to find the correct position to insert
while (current->next != head && current->next->data < item) {
current = current->next;
}
// Insert the new node
newNode->prev = current;
newNode->next = current->next;
current->next->prev = newNode;
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
struct Node *current = head;
// Traverse to the specified position
for (int i = 0; i < position; i++) {
current = current->next;
// Check if the position is valid
if (current == head) {
printf("Invalid position.\n");
return head;
}
}
// Update pointers to remove the node
current->prev->next = current->next;
current->next->prev = current->prev;
// Update head if needed
if (current == head) {
head = current->next;
}
free(current);
return head;
}
// Function to delete a node by key
struct Node* deleteByKey(struct Node *head, int key) {
if (head == NULL) {
printf("List is empty.\n");
return NULL;
}
struct Node *current = head;
// Search for the key
do {
if (current->data == key) {
// Update pointers to remove the node
current->prev->next = current->next;
current->next->prev = current->prev;
// Update head if needed
if (current == head) {
head = current->next;
}
free(current);
return head;
}
current = current->next;
} while (current != head);
// Key not found
printf("Key not found.\n");
return head;
}
// Function to search for an item by position
int searchByPosition(struct Node *head, int position) {
if (head == NULL) {
printf("List is empty.\n");
return -1;
}
struct Node *current = head;
int currentPosition = 0;
do {
if (currentPosition == position) {
return current->data;
}
current = current->next;
currentPosition++;
} while (current != head);
// Invalid position
printf("Invalid position.\n");
return -1;
}
int main() {
struct Node *head = NULL;
int choice, item, position, key, result;
do {
printf("\nMenu:\n");
printf("1. Insert by order\n");
printf("2. Delete by position\n");
printf("3. Delete by key\n");
printf("4. Search by position\n");
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
printf("Enter key to delete: ");
scanf("%d", &key);
head = deleteByKey(head, key);
displayList(head);
break;
case 4:
printf("Enter position to search: ");
scanf("%d", &position);
result = searchByPosition(head, position);
if (result != -1) {
printf("Item at position %d: %d\n", position, result);
}
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
// Free the memory allocated for the circular doubly linked list before exiting
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
