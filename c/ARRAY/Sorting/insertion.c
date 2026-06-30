#include <stdio.h>
void InsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) { // Start from the second element
        int key = arr[i];  // The element to be placed correctly
        int j = i - 1;

        // Move elements that are greater than key one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; // Shift element right
            j--; // Move left to check the next element
        }

        arr[j + 1] = key;  // 🔹 Place key at the vacant position
    }
}


int main() {
    int n;
    printf("Enter size of the array: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter array elements: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Given array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    InsertionSort(arr, n);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
