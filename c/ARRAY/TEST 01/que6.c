#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // For malloc()

bool Check_sorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;

    // Input array size
    printf("Enter array size: ");
    scanf("%d", &n);

    // Handle invalid input size
    if (n <= 0) {
        printf("❌ Invalid array size! Must be greater than 0.\n");
        return 1;
    }

    // Dynamic memory allocation
    int *arr = (int*) malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("❌ Memory allocation failed!\n");
        return 1;
    }

    // Input array elements
    printf("Enter %d array elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Display given array
    printf("Given array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Check if the array is sorted
    if (Check_sorted(arr, n)) {
        printf("✅ The array is sorted.\n");
    } else {
        printf("❌ The array is NOT sorted.\n");
    }

    // Free allocated memory
    free(arr);

    return 0;
}
