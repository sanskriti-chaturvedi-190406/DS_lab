#include <stdio.h>
#define MAX 5

int dq[MAX];
int front = -1;
int rear = -1;

// Check if full
int isFull() {
    return (front == 0 && rear == MAX - 1) || (front == rear + 1);
}

// Check if empty
int isEmpty() {
    return (front == -1);
}

// Insert at front
void insertFront(int x) {

    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
        dq[front] = x;
    }
    else if (front == 0) {
        front = MAX - 1;
        dq[front] = x;
    }
    else {
        dq[--front] = x;
    }

    printf("Inserted at front: %d\n", x);
}

// Insert at rear
void insertRear(int x) {

    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
        dq[rear] = x;
    }
    else {
        rear = (rear + 1) % MAX;
        dq[rear] = x;
    }

    printf("Inserted at rear: %d\n", x);
}

// Delete from front
int deleteFront() {

    if (isEmpty()) {
        printf("Deque Underflow\n");
        return -1;
    }

    int x = dq[front];

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;

    return x;
}

// Delete from rear
int deleteRear() {

    if (isEmpty()) {
        printf("Deque Underflow\n");
        return -1;
    }

    int x = dq[rear];

    if (front == rear)
        front = rear = -1;
    else if (rear == 0)
        rear = MAX - 1;
    else
        rear--;

    return x;
}

// Display deque
void display() {

    if (isEmpty()) {
        printf("Deque empty\n");
        return;
    }

    printf("Deque contents: ");

    int i = front;
    while (1) {
        printf("%d ", dq[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main() {

    insertRear(10);
    insertRear(20);
    insertFront(5);
    display();

    printf("Deleted from rear: %d\n", deleteRear());
    printf("Deleted from front: %d\n", deleteFront());
    display();

    return 0;
}
