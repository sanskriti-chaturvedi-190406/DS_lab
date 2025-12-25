#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

// Check if full
int isFull() {
    return (rear == MAX - 1);
}

// Check if empty
int isEmpty() {
    return (front == -1 || front > rear);
}

// Enqueue Operation
void enqueue(int x) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)
        front = 0;

    queue[++rear] = x;
    printf("%d enqueued\n", x);
}

// Dequeue Operation
int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return -1;
    }

    int val = queue[front++];

    if (front > rear)
        front = rear = -1;

    return val;
}

// Display Queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue contents: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {

    // Sample queue operations
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    printf("Dequeued: %d\n", dequeue());
    display();

    enqueue(40);
    enqueue(50);
    enqueue(60);   // Overflow expected
    display();

    return 0;
}
