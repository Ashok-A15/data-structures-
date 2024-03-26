#include <stdio.h>
#include <stdlib.h>
// Define Node structure for Circular Singly Linked List
struct Node {
int data;
struct Node* next;
};
// Function to create a new node
struct Node* createNode(int data) {
      struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
      newNode->data = data;
      newNode->next = NULL;
      return newNode;
}
// Function to insert a node at a given position
void insertByPosition(struct Node** head, int data, int position) {
      struct Node* newNode = createNode(data);
      if (*head == NULL) {
      *head = newNode;
      newNode->next = *head;
      printf("Inserted %d at position %d\n", data, position);
return;
}
      struct Node* temp = *head;
// Traverse to the node just before the desired position
      for (int i = 1; i < position - 1; ++i) {
      temp = temp->next;
      if (temp == *head) {
      printf("Invalid position. Insertion not possible.\n");
return;
}
}
// Insert the new node
      newNode->next = temp->next;
      temp->next = newNode;
      printf("Inserted %d at position %d\n", data, position);
}
// Function to delete the rear node
void deleteRear(struct Node** head) {
      if (*head == NULL) {
      printf("List is empty. Deletion not possible.\n");
      return;
}
      struct Node* temp = *head;
      struct Node* prev = NULL;
// Traverse to the rear node
      while (temp->next != *head) {
      prev = temp;
      temp = temp->next;
}
// If there is only one node in the list
      if (temp == *head) {
      free(temp);
      *head = NULL;
} else {
      prev->next = temp->next;
      free(temp);
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
      struct Node* last = *head;
// Traverse to the rear node
      while (last->next != *head) {
      last = last->next;
}
// If there is only one node in the list
      if (temp == last) {
      free(temp);
      *head = NULL;
} else {
      *head = temp->next;
      last->next = *head;
      free(temp);
}
printf("Deleted front node\n");
}
// Function to search for an item by value
void searchByValue(struct Node* head, int value) {
      if (head == NULL) {
      printf("List is empty. Search not possible.\n");
return;
}
      struct Node* temp = head;
      int position = 1;
      int found = 0;
// Traverse the list to find the item
do {
      if (temp->data == value) {
      printf("Item %d found at position %d\n", value, position);
      found = 1;
      break;
}
      temp = temp->next;
      position++;
} while (temp != head);
      if (!found) {
      printf("Item %d not found in the list\n", value);
}
}
// Function to display the contents of the circular linked list
void displayList(struct Node* head) {
      if (head == NULL) {
      printf("List is empty.\n");
      return;
}
      struct Node* temp = head;
// Traverse and print each node's data
do {
      printf("%d ", temp->data);
      temp = temp->next;
} while (temp != head);
      printf("\n");
}
int main() {
struct Node* head = NULL;
int choice, data, position, value;
do {
printf("\n1. Insert by position");
printf("\n2. Delete Rear");
printf("\n3. Delete Front");
printf("\n4. Search for an item by value");
printf("\n5. Display list");
printf("\n6. Exit");
printf("\nEnter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter data to insert: ");
scanf("%d", &data);
printf("Enter position to insert: ");
scanf("%d", &position);
insertByPosition(&head, data, position);
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
printf("Enter value to search: ");
scanf("%d", &value);
searchByValue(head, value);
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
