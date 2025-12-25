#include <stdio.h>
#define MAX 5

int cq[MAX];
int front = -1;
int rear = -1;

// Check if full
int isFull() {
    return (front == (rear + 1) % MAX);
}

// Check if empty
int isEmpty() {
    return (front == -1);
}

// Enqueue Operation
void enqueue(int x) {
    if (isFull()) {
        printf("Circular Queue Overflow\n");
        return;
    }

    if (isEmpty())
        front = 0;

    rear = (rear + 1) % MAX;
    cq[rear] = x;

    printf("%d enqueued\n", x);
}

// Dequeue Operation
int dequeue() {
    if (isEmpty()) {
        printf("Circular Queue Underflow\n");
        return -1;
    }

    int val = cq[front];

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;

    return val;
}

// Display Queue
void display() {
    if (isEmpty()) {
        printf("Circular Queue is empty\n");
        return;
    }

    printf("Circular Queue contents: ");

    int i = front;
    while (1) {
        printf("%d ", cq[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main() {

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    display();

    printf("Dequeued: %d\n", dequeue());
    display();

    enqueue(5);
    enqueue(6);   // should succeed
    display();

    enqueue(7);   // likely overflow
    return 0;
}
