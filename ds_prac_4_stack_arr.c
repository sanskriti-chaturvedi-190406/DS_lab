#include <stdio.h>

#define MAX 5
int stack[MAX];
int top = -1;

void push(int item) {
    if (top == MAX - 1) {
        printf("Stack overflow...\n");
    } 
    else {
        stack[++top] = item;
        printf("%d inserted successfully...\n", item);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack underflow...\n");
    } else {
        int item = stack[top--];
        printf("%d deleted successfully...\n", item);
    }
}

void peek() {
    if (top == -1) {
        printf("Stack underflow...\n");
    } 
    else {
        int item = stack[top];
        printf("Top most element is: %d\n", item);
    }
}

void display() {
    if (top == -1) {
        printf("Stack underflow...\n");
    } 
    else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
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
