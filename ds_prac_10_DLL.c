#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Display List
void displayList() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Insert at Beginning
void insertAtBeginning(int data) {
    struct Node* newNode = createNode(data);
    if (head != NULL) {
        newNode->next = head;
        head->prev = newNode;
    }
    head = newNode;
    printf("Current List: ");
    displayList();
}

// Insert at End
void insertAtEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Current List: ");
    displayList();
}

// Insert After Key
void insertAfterKey(int key, int data) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL) {
        printf("Key not found.\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
    printf("Current List: ");
    displayList();
}

// Insert Before Key
void insertBeforeKey(int key, int data) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->data == key) {
        insertAtBeginning(data);
        return;
    }
    struct Node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL) {
        printf("Key not found.\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = temp;
    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    temp->prev = newNode;
    printf("Current List: ");
    displayList();
}

// Insert at a Given Position
void insertAtPosition(int pos, int data) {
    if (pos <= 0) {
        printf("Invalid position.\n");
        return;
    }
    struct Node* newNode = createNode(data);
    if (pos == 1) {
        insertAtBeginning(data);
        return;
    }
    struct Node* temp = head;
    int count = 1;
    while (temp != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newNode;
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
    struct Node* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(temp);
    printf("Current List: ");
    displayList();
}

// Delete from End
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    if (temp->next == NULL) {
        head = NULL;
        free(temp);
    } else {
        while (temp->next != NULL)
            temp = temp->next;
        temp->prev->next = NULL;
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
    if (head->data == key) {
        deleteFromBeginning();
        return;
    }
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL) {
        printf("Key not found.\n");
        return;
    }
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    free(temp);
    printf("Current List: ");
    displayList();
}

// Delete by Position
void deleteByPosition(int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (pos <= 0) {
        printf("Invalid position.\n");
        return;
    }
    struct Node* temp = head;
    int count = 1;
    if (pos == 1) {
        deleteFromBeginning();
        return;
    }
    while (temp != NULL && count < pos) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    free(temp);
    printf("Current List: ");
    displayList();
}

// Delete Entire List
void deleteEntireList() {
    struct Node* temp = head;
    while (temp != NULL) {
        struct Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    head = NULL;
    printf("Entire list deleted.\n");
}

int main() {
    int choice, data, key, pos;

    // Create initial linked list
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(4);
    insertAtEnd(6);

    printf("\nInitial Linked List:\n");
    printf("Current List: ");
    displayList();

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
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

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Exiting...\n");
            break;
        }

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
                deleteByPosition(pos);
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
