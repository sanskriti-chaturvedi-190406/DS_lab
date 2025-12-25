#include <stdio.h>
#define SIZE 7

int ht[SIZE];

// Hash function
int hash(int key) {
    return key % SIZE;
}

// Initialize hash table
void init() {
    for (int i = 0; i < SIZE; i++)
        ht[i] = -1;
}

// Insert key into hash table using linear probing
int insert(int key) {
    int idx = hash(key);
    int start = idx;
    while (ht[idx] != -1) {
        idx = (idx + 1) % SIZE;
        if (idx == start) return 0; // Table full
    }
    ht[idx] = key;
    return 1;
}

// Search for a key in the hash table
int search(int key) {
    int idx = hash(key);
    int start = idx;
    while (ht[idx] != -1) {
        if (ht[idx] == key) return idx;
        idx = (idx + 1) % SIZE;
        if (idx == start) break;
    }
    return -1;
}

// Display the hash table
void display() {
    printf("Hash table:\n");
    for (int i = 0; i < SIZE; i++)
        printf("[%d] -> %d\n", i, ht[i]);
}

int main() {
    init();
    int choice, key, pos;

    while (1) {
        printf("\n--- Hash Table Menu ---\n");
        printf("1. Insert key\n");
        printf("2. Search key\n");
        printf("3. Display table\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                if (insert(key))
                    printf("Key %d inserted successfully.\n", key);
                else
                    printf("Hash table is full! Cannot insert key %d.\n", key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                pos = search(key);
                if (pos != -1)
                    printf("Key %d found at index %d.\n", key, pos);
                else
                    printf("Key %d not found.\n", key);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
    