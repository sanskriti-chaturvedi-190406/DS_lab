#include <stdio.h>

// Linear search
int linear_search(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

// Binary search (array must be sorted)
int binary_search(int arr[], int n, int target) {
    int begin = 0, end = n - 1;
    while (begin <= end) {
        int mid = (begin + end) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            begin = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Search Menu ---\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search (Array must be sorted)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 3) {
            printf("Exiting program.\n");
            break;
        }

        int n, target;
        printf("Enter number of elements: ");
        scanf("%d", &n);

        int arr[n];
        printf("Enter %d elements:\n", n);
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        printf("Enter the value to search: ");
        scanf("%d", &target);

        int result = -1;

        switch (choice) {
            case 1:
                result = linear_search(arr, n, target);
                break;
            case 2:
                result = binary_search(arr, n, target);
                break;
            default:
                printf("Invalid choice.\n");
                continue;
        }

        if (result != -1)
            printf("Element found at index: %d\n", result);
        else
            printf("Element not found\n");
    }

    return 0;
}
