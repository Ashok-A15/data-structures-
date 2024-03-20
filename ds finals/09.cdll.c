#include <stdio.h>
#include <stdlib.h>
// Define Node structure for Circular Doubly Linked List
struct Node {
int data;
struct Node* next;
struct Node* prev;
};
// Function to create a new node
struct Node* createNode(int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = NULL;
newNode->prev = NULL;
return newNode;
}
// Function to insert a node in order
void insertByOrder(struct Node** head, int data) {
        struct Node* newNode = createNode(data);
        if (*head == NULL) {
        *head = newNode;
        (*head)->next = *head;
        (*head)->prev = *head;
        printf("Inserted %d\n", data);
        return;
}
        if (data < (*head)->data) {
        newNode->next = *head;
        newNode->prev = (*head)->prev;
        (*head)->prev->next = newNode;
        (*head)->prev = newNode;
        *head = newNode;
        printf("Inserted %d\n", data);
        return;
}
        struct Node* current = (*head)->next;
        while (current != *head && current->data < data) {
        current = current->next;
}
        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;
        printf("Inserted %d\n", data);
}
// Function to delete the rear node
void deleteRear(struct Node** head) {
        if (*head == NULL) {
        printf("List is empty. Deletion not possible.\n");
        return;
}
        struct Node* last = (*head)->prev;
        if (*head == last) {
        free(*head);
        *head = NULL;
} else {
        last->prev->next = *head;
        (*head)->prev = last->prev;
        free(last);
}
        printf("Deleted rear node\n");
}
// Function to delete the front node
void deleteFront(struct Node** head) {
if (*head == NULL) {
printf("List is empty. Deletion not possible.\n");
return;
}
struct Node* temp = *head;
if ((*head)->next == *head) {
free(*head);
*head = NULL;
} else {
*head = (*head)->next;
(*head)->prev = temp->prev;
temp->prev->next = *head;
free(temp);
}
printf("Deleted front node\n");
}
// Function to search for an item by position
void searchByPosition(struct Node* head, int position) {
if (head == NULL) {
printf("List is empty. Search not possible.\n");
return;
}
struct Node* current = head;
int currentPosition = 1;
int found = 0;
// Traverse the list to find the item at the specified position
do {
if (currentPosition == position) {
printf("Item at position %d: %d\n", position, current->data);
found = 1;
break;
}
current = current->next;
currentPosition++;
} while (current != head);
if (!found) {
printf("Item not found at position %d\n", position);
}
}
// Function to display the contents of the circular doubly linked list
void displayList(struct Node* head) {
if (head == NULL) {
printf("List is empty.\n");
return;
}
struct Node* current = head;
// Traverse and print each node's data
do {
printf("%d ", current->data);
current = current->next;
} while (current != head);
printf("\n");
}
int main() {
struct Node* head = NULL;
int choice, data, position;
do {
printf("\n1. Insert by order");
printf("\n2. Delete Rear");
printf("\n3. Delete Front");
printf("\n4. Search for an item by position");
printf("\n5. Display list");
printf("\n6. Exit");
printf("\nEnter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter data to insert: ");
scanf("%d", &data);
insertByOrder(&head, data);
displayList(head);
break;
case 2:
deleteRear(&head);
displayList(head);
break;
case 3:
deleteFront(&head);
displayList(head);
break;
case 4:
printf("Enter position to search: ");
scanf("%d", &position);
searchByPosition(head, position);
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
return 0;
}
