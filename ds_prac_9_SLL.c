#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Display linked list
void displayList() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Current List: ");
    while (temp != NULL) {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* -------------------- INSERTION FUNCTIONS -------------------- */

// 1. Insert at Beginning
void insertAtBeginning(int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    displayList();
}

// 2. Insert at End
void insertAtEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    displayList();
}

// 3. Insert After a Given Key
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
    temp->next = newNode;
    displayList();
}

// 4. Insert Before a Given Key
void insertBeforeKey(int key, int data) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->data == key) {
        insertAtBeginning(data);
        return;
    }

    struct Node *temp = head, *prev = NULL;
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Key not found.\n");
        return;
    }

    struct Node* newNode = createNode(data);
    prev->next = newNode;
    newNode->next = temp;
    displayList();
}

// 5. Insert at Specific Position
void insertAtPosition(int pos, int data) {
    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1) {
        insertAtBeginning(data);
        return;
    }

    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }

    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
    displayList();
}

/* -------------------- DELETION FUNCTIONS -------------------- */

// 6. Delete at Beginning
void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);
    displayList();
}

// 7. Delete at End
void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        displayList();
        return;
    }

    struct Node *temp = head, *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
    displayList();
}

// 8. Delete by Value (Key)
void deleteByValue(int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head, *prev = NULL;

    if (head->data == key) {
        head = head->next;
        free(temp);
        displayList();
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Key not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    displayList();
}

// 9. Delete at Specific Position
void deleteAtPosition(int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (pos == 1) {
        deleteAtBeginning();
        return;
    }

    struct Node *temp = head, *prev = NULL;

    for (int i = 1; temp != NULL && i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    displayList();
}

// 10. Delete Entire List
void deleteEntireList() {
    struct Node* temp = head;
    while (temp != NULL) {
        struct Node* next = temp->next;
        free(temp);
        temp = next;
    }
    head = NULL;
    printf("Entire list deleted.\n");
}

// 11. Delete After a Given Key
void deleteAfterKey(int key) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("No node found after key.\n");
        return;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    displayList();
}

// 12. Delete Before a Given Key
void deleteBeforeKey(int key) {
    if (head == NULL || head->next == NULL) {
        printf("List too small.\n");
        return;
    }

    if (head->next->data == key) {
        deleteAtBeginning();
        return;
    }

    struct Node *prev = NULL, *curr = head, *next = head->next;

    while (next->next != NULL && next->next->data != key) {
        prev = curr;
        curr = next;
        next = next->next;
    }

    if (next->next == NULL) {
        printf("Key not found.\n");
        return;
    }

    prev->next = next;
    free(curr);
    displayList();
}

/* -------------------- MAIN FUNCTION -------------------- */

int main() {
    int choice, data, key, pos;

    // Create initial linked list
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(4);
    insertAtEnd(6);

    printf("\nInitial Linked List:\n");
    displayList();

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After a Given Key\n");
        printf("4. Insert Before a Given Key\n");
        printf("5. Insert at a Specific Position\n");
        printf("6. Delete at Beginning\n");
        printf("7. Delete at End\n");
        printf("8. Delete by Value (Key)\n");
        printf("9. Delete at Specific Position\n");
        printf("10. Delete Entire List\n");
        printf("11. Delete After a Given Key\n");
        printf("12. Delete Before a Given Key\n");
        printf("13. Display List\n");
        printf("14. Exit\n");
        printf("Enter choice: ");
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
                deleteAtBeginning();
                break;
            case 7:
                deleteAtEnd();
                break;
            case 8:
                printf("Enter value to delete: ");
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
                printf("Enter key: ");
                scanf("%d", &key);
                deleteAfterKey(key);
                break;
            case 12:
                printf("Enter key: ");
                scanf("%d", &key);
                deleteBeforeKey(key);
                break;
            case 13:
                displayList();
                break;
            case 14:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
