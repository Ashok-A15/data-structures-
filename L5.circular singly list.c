#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Head structure
struct Head {
    int size;
    struct Node* first;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation error!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to free the memory allocated for the list
void freeList(struct Head* head) {
    if (head->size == 0) {
        free(head);
        return;
    }

    struct Node* current = head->first;
    struct Node* temp;

    for (int i = 0; i < head->size; ++i) {
        temp = current;
        current = current->next;
        free(temp);
    }

    free(head);
}

// Function to initialize the head node
struct Head* initializeHead() {
    struct Head* head = (struct Head*)malloc(sizeof(struct Head));
    if (head == NULL) {
        printf("Memory allocation error!\n");
        exit(1);
    }
    head->size = 0;
    head->first = NULL;
    return head;
}

// Function to print the circular linked list
void displayList(struct Head* head) {
    if (head->size == 0) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head->first;
    for (int i = 0; i < head->size; ++i) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("(head)\n");
}
// Function to insert a node at the front
void insertFront(struct Head* head, int data) {
    struct Node* newNode = createNode(data);

    if (head->size == 0) {
        newNode->next = newNode;
        head->first = newNode;
    } else {
        newNode->next = head->first;
        struct Node* last = head->first;
        while (last->next != head->first) {
            last = last->next;
        }
        last->next = newNode;
        head->first = newNode;
    }

    head->size++;
    displayList(head);
}

// Function to insert a node at the rear
void insertRear(struct Head* head, int data) {
    struct Node* newNode = createNode(data);

    if (head->size == 0) {
        newNode->next = newNode;
        head->first = newNode;
    } else {
        struct Node* last = head->first;
        while (last->next != head->first) {
            last = last->next;
        }
        newNode->next = head->first;
        last->next = newNode;
    }

    head->size++;
    displayList(head);
}

// Function to insert a node at a specified position
void insertAtPosition(struct Head* head, int data, int position) {
    if (position < 1 || position > head->size + 1) {
        printf("Invalid position.\n");
        return;
    }

    struct Node* newNode = createNode(data);

    if (position == 1) {
        insertFront(head, data);
    } else {
        struct Node* current = head->first;
        for (int i = 1; i < position - 1; ++i) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        head->size++;
        displayList(head);
    }
}

// Function to delete a node at the front
void deleteFront(struct Head* head) {
    if (head->size == 0) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head->first;
    if (head->size == 1) {
        free(temp);
        head->first = NULL;
    } else {
        struct Node* last = head->first;
        while (last->next != head->first) {
            last = last->next;
        }
        head->first = temp->next;
        last->next = head->first;
        free(temp);
    }

    head->size--;
    displayList(head);
}

// Function to delete a node at the rear
void deleteRear(struct Head* head) {
    if (head->size == 0) {
        printf("List is empty.\n");
        return;
    }

    if (head->size == 1) {
        free(head->first);
        head->first = NULL;
    } else {
        struct Node* last = head->first;
        struct Node* secondLast = NULL;

        while (last->next != head->first) {
            secondLast = last;
            last = last->next;
        }

        secondLast->next = head->first;
        free(last);
    }

    head->size--;
    displayList(head);
}

// Function to delete a node at a specified position
void deleteAtPosition(struct Head* head, int position) {
    if (head->size == 0) {
        printf("List is empty.\n");
        return;
    }

    if (position < 1 || position > head->size) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 1) {
        deleteFront(head);
    } else {
        struct Node* current = head->first;
        struct Node* temp;

        for (int i = 1; i < position - 1; ++i) {
            current = current->next;
        }

        temp = current->next;
        current->next = temp->next;
        free(temp);

        head->size--;
        displayList(head);
    }
}

// Function to delete a node by key 
void deleteByKey(struct Head* head, int key) {
    if (head->size == 0) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head->first;
    struct Node* temp = NULL;

    if (current->data == key) {
        deleteFront(head);
        return;
    }

    while (current->next != head->first) {
        if (current->next->data == key) {
            temp = current->next;
            current->next = temp->next;
            free(temp);
            head->size--;
            return;
        }
        current = current->next;
        displayList(head);
    }

    printf("Key not found.\n");
}

// Function to search a node by key
void searchByKey(struct Head* head, int key) {
    if (head->size == 0) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head->first;
    int position = 1;

    do {
        if (current->data == key) {
            printf("Key found at position %d.\n", position);
            return;
        }
        current = current->next;
        position++;
    } while (current != head->first);

    printf("Key not found.\n");
}

// This Method Inserts the Value Such that the List is maintained in Sorted Order...
void insertByOrder(struct Head* list, int data) {
    if (list->first == NULL) {
        list->first = createNode(data);
        list->first->next = list->first;
    } else if (data <= list->first->data) {
        struct Node* tempNode = list->first;

        while (tempNode->next != list->first) {
            tempNode = tempNode->next;
        }

        tempNode->next = createNode(data);
        tempNode->next->next = list->first;
        list->first = tempNode->next;
    } else {
        struct Node* tempNode = list->first;

        while (tempNode->next != list->first && tempNode->next->data < data) {
            tempNode = tempNode->next;
        }
        struct Node* temp = tempNode->next;
        tempNode->next = createNode(data);
        tempNode->next->next = temp;
    }

    printf("\nValue has been Inserted Succesfully... List: ");
    list->size++;
}

// Method to Create Ordered List...
void createOrderedList() {
    struct Head* orderedList = initializeHead();

    printf("\nCreating Ordered List...\n");

    while (1) {
        int data;
        printf("\n[Enter -1 to Exit] Enter the Value to be Inserted (Except -1): ");
        scanf("%d", &data);

        if (data != -1) {
            insertByOrder(orderedList, data);
            displayList(orderedList);
        } else {
            printf("\nOrdered List has been Created...\n\nOrdered List: ");
            displayList(orderedList);
            break;
        }
    }

    freeList(orderedList);
}

// Function to create an ordered list
// void createOrderedList(struct Head* head, int data) {
//     struct Node* newNode = createNode(data);

//     if (head->size == 0 || data < head->first->data) {
//         insertFront(head, data);
//     } else {
//         struct Node* current = head->first;

//         while (current->next != head->first && current->next->data < data) {
//             current = current->next;
//         }

//         newNode->next = current->next;
//         current->next = newNode;

//         head->size++;
//     }
// }

// Function to reverse the list
void reverseList(struct Head* head) {
    if (head->size == 0) {
        printf("List is empty.\n");
        return;
    }

    struct Node* prev = NULL;
    struct Node* current = head->first;
    struct Node* next;

    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != head->first);

    head->first->next = prev;
    head->first = prev;

}

// This Method Returns the newly created Linked List that's been Copied...
struct Head* copyOfList(struct Head* head) {
     if (head->size == 0) {
        printf("List is empty.\n");
        return NULL;
    } else {
        struct Head* copyList = initializeHead();
        struct Node*  newHead = copyList->first = createNode(head->first->data);
        struct Node*  currNode = head->first->next;

        while (currNode != head->first) {
            newHead = newHead->next = createNode(currNode->data);
            currNode = currNode->next;
        }
        newHead->next = copyList->first, copyList->size = head->size;

        return copyList;
    }
}

// Function to create a copy of the list
// struct Head* copyList(struct Head* head) {
//     if (head->size == 0) {
//         printf("List is empty.\n");
//         return NULL;
//     }

//     struct Head* newHead = initializeHead();
//     struct Node* current = head->first;

//     do {
//         createOrderedList(newHead, current->data);
//         current = current->next;
//     } while (current != head->first);

//     return newHead;
// }

int main() {
    struct Head* head = initializeHead();
    struct Head* copy = NULL;
    int choice, data, position, key;

    do {
        printf("\n1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Insert at Specified Position\n");
        printf("4. Delete at Front\n");
        printf("5. Delete at Rear\n");
        printf("6. Delete at Specified Position\n");
        printf("7. Delete by Key\n");
        printf("8. Search by Key\n");
        printf("9. Create an Ordered List\n");
        printf("10. Reverse List\n");
        printf("11. Create a Copy of the List\n");
        printf("12. Display List\n");
        printf("13. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                insertFront(head, data);
                break;
            case 2:
                printf("Enter data to insert at rear: ");
                scanf("%d", &data);
                insertRear(head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                insertAtPosition(head, data, position);
                break;
            case 4:
                deleteFront(head);
                break;
            case 5:
                deleteRear(head);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(head, position);
                break;
            case 7:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteByKey(head, key);
                break;
            case 8:
                printf("Enter key to search: ");
                scanf("%d", &key);
                searchByKey(head, key);
                break;
            case 9:
                // printf("Enter data to insert in ordered list: ");
                // scanf("%d", &data);
                createOrderedList(head);
                break;
            case 10:
                reverseList(head);
                displayList(head);
                break;
            case 11:
                printf("Creating a copy of the list...\n");
                copy = copyOfList(head);
                printf("Original list: ");
                displayList(head);
                printf("Copied list: ");
                displayList(copy);
                break;
            case 12:
                printf("Current List: ");
                displayList(head);
                break;
            case 13:
                printf("Exiting...\n");
                freeList(head);
                freeList(copy);
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 13);

    return 0;
}
