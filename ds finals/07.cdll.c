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
// Function to insert a node at the front
struct Node* insertFront(struct Node *head, int item) {
struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = item;
if (head == NULL) {
newNode->prev = newNode;
newNode->next = newNode;
return newNode;
}
newNode->next = head;
newNode->prev = head->prev;
head->prev->next = newNode;
head->prev = newNode;
return newNode;
}
// Function to insert a node at the rear
struct Node* insertRear(struct Node *head, int item) {
struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = item;
if (head == NULL) {
newNode->prev = newNode;
newNode->next = newNode;
return newNode;
}
newNode->prev = head->prev;
newNode->next = head;
head->prev->next = newNode;
head->prev = newNode;
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
// Key not found
printf("Key not found.\n");
return -1;
}
int main() {
struct Node *head = NULL;
int choice, item, position, key, result;
do {
printf("\nMenu:\n");
printf("1. Insert at the front\n");
printf("2. Insert at the rear\n");
printf("3. Delete by position\n");
printf("4. Search by key\n");
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
printf("Enter position to delete: ");
scanf("%d", &position);
head = deleteByPosition(head, position);
displayList(head);
break;
case 4:
printf("Enter key to search: ");
scanf("%d", &key);
result = searchByKey(head, key);
if (result != -1) {
printf("Key %d found at position %d.\n", key, result);
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
