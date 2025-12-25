#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Display List
void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d --> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

// Insert at Beginning
void insertAtBeginning(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    printf("Current List: ");
    displayList();
}

// Insert at End
void insertAtEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
    printf("Current List: ");
    displayList();
}

// Insert After a Given Key
void insertAfterKey(int key, int data) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        if (temp->data == key) {
            struct Node* newNode = createNode(data);
            newNode->next = temp->next;
            temp->next = newNode;
            printf("Current List: ");
            displayList();
            return;
        }
        temp = temp->next;
    } while (temp != head);
    printf("Key not found.\n");
}

// Insert Before a Given Key
void insertBeforeKey(int key, int data) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    // Special case: if key is head
    do {
        if (temp->data == key) {
            struct Node* newNode = createNode(data);
            if (temp == head) {
                struct Node* last = head;
                while (last->next != head)
                    last = last->next;
                newNode->next = head;
                last->next = newNode;
                head = newNode;
            } else {
                prev->next = newNode;
                newNode->next = temp;
            }
            printf("Current List: ");
            displayList();
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != head);

    printf("Key not found.\n");
}

// Insert at Specific Position
void insertAtPosition(int pos, int data) {
    if (pos <= 0) {
        printf("Invalid position.\n");
        return;
    }

    struct Node* newNode = createNode(data);

    if (head == NULL) {
        if (pos == 1) {
            newNode->next = newNode;
            head = newNode;
            printf("Current List: ");
            displayList();
        } else {
            printf("Position out of range.\n");
            free(newNode);
        }
        return;
    }

    if (pos == 1) {
        insertAtBeginning(data);
        return;
    }

    struct Node* temp = head;
    int count = 1;

    while (temp->next != head && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    if (count < pos - 1) {
        printf("Position out of range.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Current List: ");
    displayList();
}

// Delete from Beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        struct Node* temp = head;
        struct Node* last = head;
        while (last->next != head)
            last = last->next;
        head = head->next;
        last->next = head;
        free(temp);
    }
    printf("Current List: ");
    displayList();
}

// Delete from End
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        struct Node* temp = head;
        struct Node* prev = NULL;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        free(temp);
    }
    printf("Current List: ");
    displayList();
}

// Delete by Value
void deleteByValue(int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    // If head is to be deleted
    if (head->data == key) {
        deleteFromBeginning();
        return;
    }

    do {
        prev = temp;
        temp = temp->next;
        if (temp->data == key) {
            prev->next = temp->next;
            free(temp);
            printf("Current List: ");
            displayList();
            return;
        }
    } while (temp != head);

    printf("Key not found.\n");
}

// Delete at Position
void deleteAtPosition(int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (pos <= 0) {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1) {
        deleteFromBeginning();
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;
    int count = 1;

    do {
        prev = temp;
        temp = temp->next;
        count++;
        if (count == pos) {
            prev->next = temp->next;
            free(temp);
            printf("Current List: ");
            displayList();
            return;
        }
    } while (temp->next != head);

    printf("Position out of range.\n");
}

// Delete Entire List
void deleteEntireList() {
    if (head == NULL) {
        printf("List is already empty.\n");
        return;
    }

    struct Node* temp = head;
    struct Node* nextNode;
    do {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    } while (temp != head);
    head = NULL;
    printf("Entire list deleted.\n");
}

int main() {
    int choice, data, key, pos;

    // Create Initial Linked List
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(4);
    insertAtEnd(6);

    printf("\nInitial Linked List:\n");
    printf("Current List: ");
    displayList();

    while (1) {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After a Given Key\n");
        printf("4. Insert Before a Given Key\n");
        printf("5. Insert at a Specific Position\n");
        printf("6. Delete from Beginning\n");
        printf("7. Delete from End\n");
        printf("8. Delete by Value\n");
        printf("9. Delete by Position\n");
        printf("10. Delete Entire List\n");
        printf("11. Display List\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter value: ");
                scanf("%d", &data);
                insertAfterKey(key, data);
                break;
            case 4:
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter value: ");
                scanf("%d", &data);
                insertBeforeKey(key, data);
                break;
            case 5:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter value: ");
                scanf("%d", &data);
                insertAtPosition(pos, data);
                break;
            case 6:
                deleteFromBeginning();
                break;
            case 7:
                deleteFromEnd();
                break;
            case 8:
                printf("Enter value to delete: ");
                scanf("%d", &key);
                deleteByValue(key);
                break;
            case 9:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 10:
                deleteEntireList();
                break;
            case 11:
                printf("Current List: ");
                displayList();
                break;
            case 12:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
