#include <stdio.h>

// Bubble Sort
void bubble_sort(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Selection Sort
void selection_sort(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        int min_i = i;
        for(int j = i+1; j < n; j++)
            if(arr[j] < arr[min_i])
                min_i = j;
        int temp = arr[i];
        arr[i] = arr[min_i];
        arr[min_i] = temp;
    }
}

// Insertion Sort
void insertion_sort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// Display array
void display_array(int arr[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int choice;

    while(1) {
        printf("\n--- Sorting Menu ---\n");
        printf("1. Bubble Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 4) {
            printf("Exiting program.\n");
            break;
        }

        int n;
        printf("Enter number of elements: ");
        scanf("%d", &n);

        int arr[n];
        printf("Enter %d elements:\n", n);
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        switch(choice) {
            case 1:
                bubble_sort(arr, n);
                printf("Array after Bubble Sort: ");
                break;
            case 2:
                selection_sort(arr, n);
                printf("Array after Selection Sort: ");
                break;
            case 3:
                insertion_sort(arr, n);
                printf("Array after Insertion Sort: ");
                break;
            default:
                printf("Invalid choice.\n");
                continue;
        }

        display_array(arr, n);
    }

    return 0;
}
