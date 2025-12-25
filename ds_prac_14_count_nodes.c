#include <stdio.h>
#include <stdlib.h>

void displayList();

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

// Insert at end
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

    printf("Current List: ");
    displayList();
}

// Display list
void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Count nodes
int countNodes() {
    int cnt = 0;
    struct Node* temp = head;

    while (temp != NULL) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

// Search for a value
void searchValue(int key) {
    struct Node* temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Value %d found at position %d.\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }

    printf("Value %d not found in the list.\n", key);
}

int main() {
    int choice, data, key;

    while (1) {
        printf("\n--- Linear Linked List Menu (Count/Search) ---\n");
        printf("1. Insert at End\n");
        printf("2. Count Nodes\n");
        printf("3. Search for Value\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;

            case 2:
                printf("Total nodes = %d\n", countNodes());
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &key);
                searchValue(key);
                break;

            case 4:
                printf("Current List: ");
                displayList();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
