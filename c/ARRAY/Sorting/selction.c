#include <stdio.h>

int main() {
    int n;
    printf("Enter size of the array\n");
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

    // Selection Sort
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;  // Assume i is the smallest
        for (int j = i + 1; j < n; j++) {  // Find the minimum element
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Swap if min_idx changed
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
