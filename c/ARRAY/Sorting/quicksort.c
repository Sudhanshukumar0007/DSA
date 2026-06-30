#include <stdio.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[low];  // Choose first element as pivot
    int lb = low, up = high, temp;

    while (lb < up) {
        while (arr[lb] <= pivot && lb < up) {
            lb++;
        }
        while (arr[up] > pivot) {
            up--;
        }
        if (lb < up) {
            // Swap elements at lb and up
            temp = arr[lb];
            arr[lb] = arr[up];
            arr[up] = temp;
        }
    }

    // Place pivot at correct position
    arr[low] = arr[up];
    arr[up] = pivot;

    return up;
}

void Quicksort(int arr[], int low, int high) {
    if (low < high) {  // ✅ Base condition to stop recursion
        int p = partition(arr, low, high);
        Quicksort(arr, low, p - 1);
        Quicksort(arr, p + 1, high);
    }
}

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

    Quicksort(arr, 0, n - 1);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
