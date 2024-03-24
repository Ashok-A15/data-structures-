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
} while (current != head);
printf("\n");
}
// Function to insert a node at the front
struct Node* insertFront(struct Node *head, int item) {
struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = item;
if (head == NULL) {
newNode->next = newNode;
return newNode;
}
struct Node *last = head;
while (last->next != head) {
last = last->next;
}
newNode->next = head;
last->next = newNode;
return newNode;
}
// Function to insert a node at the rear
struct Node* insertRear(struct Node *head, int item) {
struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = item;
if (head == NULL) {
newNode->next = newNode;
return newNode;
}
struct Node *last = head;
while (last->next != head) {
last = last->next;
}
newNode->next = head;
last->next = newNode;
return head;
}
// Function to delete a node with the given key
struct Node* deleteByKey(struct Node *head, int key) {
if (head == NULL) {
printf("List is empty.\n");
return NULL;
}
struct Node *current = head, *prev = NULL;
do {
if (current->data == key) {
if (prev == NULL) {
// Deleting the head node
if (current->next == head) {
// Only one node in the list
free(current);
return NULL;
}
head = current->next;
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
printf("1. Insert at the front\n");
printf("2. Insert at the rear\n");
printf("3. Delete a node with given key\n");
printf("4. Search for an item by position\n");
printf("5. Display the list contents\n");
printf("6. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter item to insert at the front: ");
scanf("%d", &item);
head = insertFront(head, item);
displayList(head);
break;
case 2:
printf("Enter item to insert at the rear: ");
scanf("%d", &item);
head = insertRear(head, item);
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
// Free the memory allocated for the circular singly linked list before exiting
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
