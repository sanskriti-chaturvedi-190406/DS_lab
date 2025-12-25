#include <stdio.h>
#define MAX 10

int val[MAX], pr[MAX];
int size = 0;

// Insert (value, priority)
void insert(int v, int p) {

    if (size == MAX) {
        printf("Priority queue overflow\n");
        return;
    }

    int i = size - 1;

    // place so that array sorted by priority descending (higher p first)
    while (i >= 0 && pr[i] < p) {
        pr[i + 1] = pr[i];
        val[i + 1] = val[i];
        i--;
    }

    pr[i + 1] = p;
    val[i + 1] = v;

    size++;

    printf("Inserted (%d, priority=%d)\n", v, p);
}

// Display queue
void display() {

    if (size == 0) {
        printf("Priority queue empty\n");
        return;
    }

    printf("Queue (value:priority) from front to rear:\n");

    for (int i = 0; i < size; i++)
        printf("%d:%d ", val[i], pr[i]);

    printf("\n");
}

// Delete highest priority element
int deleteHighest() {

    if (size == 0) {
        printf("Priority queue empty\n");
        return -1;
    }

    int v = val[0];

    for (int i = 0; i < size - 1; i++) {
        val[i] = val[i + 1];
        pr[i] = pr[i + 1];
    }

    size--;

    return v;
}

int main() {

    insert(100, 2);
    insert(50, 5);
    insert(70, 3);
    display();

    printf("Deleted highest priority: %d\n", deleteHighest());
    display();

    return 0;
}
