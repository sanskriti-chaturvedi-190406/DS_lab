#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack overflow...\n");
        return;
    }
    newNode->data = item;
    newNode->next = top;
    top = newNode;
    printf("%d inserted successfully...\n", item);
}

void pop() {
    if (top == NULL) {
        printf("Stack underflow...\n");
    } 
    else {
        struct Node* temp = top;
        int item = temp->data;
        top = top->next;
        free(temp);
        printf("%d deleted successfully...\n", item);
    }
}

void peek() {
    if (top == NULL) {
        printf("Stack underflow...\n");
    } 
    else {
        printf("Top most element is: %d\n", top->data);
    }
}

void display() {
    if (top == NULL) {
        printf("Stack underflow...\n");
    } 
    else {
        struct Node* temp = top;
        printf("Stack elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice, item;
    while (1) {
        printf("\n\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to push: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exited successfully...\n");
                return 0;
            default:
                printf("Invalid choice...\n");
        }
    }
    return 0;
}
