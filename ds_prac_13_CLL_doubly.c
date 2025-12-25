#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

// Display forward
void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Forward: ");
    do {
        printf("%d <--> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");

    // Display backward
    struct Node* last = head->prev;
    printf("Backward: ");
    temp = last;
    do {
        printf("%d <--> ", temp->data);
        temp = temp->prev;
    } while (temp != last);
    printf("(back to tail)\n");
}


// Insert at beginning
void insertAtBeginning(int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        newNode->next = newNode->prev = newNode;
        head = newNode;
    } 
    else {
        struct Node* last = head->prev;

        newNode->next = head;
        newNode->prev = last;

        last->next = newNode;
        head->prev = newNode;

        head = newNode;
    }

    printf("Current List:\n");
    displayList();
}

// Insert at end
void insertAtEnd(int data) {
    if (head == NULL) {
        insertAtBeginning(data);
        return;
    }

    struct Node* newNode = createNode(data);
    struct Node* last = head->prev;

    newNode->next = head;
    newNode->prev = last;

    last->next = newNode;
    head->prev = newNode;

    printf("Current List:\n");
    displayList();
}

// Insert after key
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
            newNode->prev = temp;

            temp->next->prev = newNode;
            temp->next = newNode;

            printf("Current List:\n");
            displayList();
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Key not found.\n");
}

// Insert before key
void insertBeforeKey(int key, int data) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;

    do {
        if (temp->data == key) {
            if (temp == head) {
                insertAtBeginning(data);
                return;
            }

            struct Node* newNode = createNode(data);

            newNode->next = temp;
            newNode->prev = temp->prev;

            temp->prev->next = newNode;
            temp->prev = newNode;

            printf("Current List:\n");
            displayList();
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Key not found.\n");
}

// Insert at a specific position
void insertAtPosition(int pos, int data) {
    if (pos <= 0) {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1) {
        insertAtBeginning(data);
        return;
    }

    struct Node* temp = head;
    int count = 1;

    do {
        if (count == pos - 1) {
            struct Node* newNode = createNode(data);

            newNode->next = temp->next;
            newNode->prev = temp;

            temp->next->prev = newNode;
            temp->next = newNode;

            printf("Current List:\n");
            displayList();
            return;
        }
        temp = temp->next;
        count++;
    } while (temp != head);

    printf("Position out of range.\n");
}

// Delete from beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
    } 
    else {
        struct Node* last = head->prev;
        struct Node* temp = head;

        head = head->next;
        last->next = head;
        head->prev = last;

        free(temp);
    }

    printf("Current List:\n");
    displayList();
}

// Delete from end
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
        printf("List is empty now.\n");
        return;
    }

    struct Node* last = head->prev;
    struct Node* secondLast = last->prev;

    secondLast->next = head;
    head->prev = secondLast;

    free(last);

    printf("Current List:\n");
    displayList();
}

// Delete by value
void deleteByValue(int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;

    do {
        if (temp->data == key) {
            if (temp == head) {
                deleteFromBeginning();
                return;
            }

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            free(temp);

            printf("Current List:\n");
            displayList();
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Value not found.\n");
}

// Delete at position
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
    int count = 1;

    do {
        if (count == pos) {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            free(temp);

            printf("Current List:\n");
            displayList();
            return;
        }
        temp = temp->next;
        count++;
    } while (temp != head);

    printf("Position out of range.\n");
}

// Delete entire list
void deleteEntireList() {
    if (head == NULL) {
        printf("List already empty.\n");
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

    while (1) {
        printf("\n--- Circular Doubly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After Key\n");
        printf("4. Insert Before Key\n");
        printf("5. Insert at Position\n");
        printf("6. Delete from Beginning\n");
        printf("7. Delete from End\n");
        printf("8. Delete by Value\n");
        printf("9. Delete by Position\n");
        printf("10. Delete Entire List\n");
        printf("11. Display List\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

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
                printf("Enter value: ");
                scanf("%d", &key);
                deleteByValue(key);
                break;
            case 9:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 10:
                deleteEntireList();
                break;
            case 11:
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
