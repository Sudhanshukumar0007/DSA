#include <stdio.h>

// Partition function for Quick Sort
int partition(int arr[], int lb, int ub) {
    int pivot = arr[lb];
    int start = lb;
    int end = ub;
    int temp;

    while (start < end) {
        while (arr[start] <= pivot && start < ub) {
            start++;
        }
        while (arr[end] > pivot) {
            end--;
        }
        if (start < end) {
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }

    // Swap pivot with arr[end]
    arr[lb] = arr[end];
    arr[end] = pivot;

    return end;
}

// Quick Sort function
void QuickSort(int arr[], int low, int high) {
    int p;
    if (low < high) {
        p = partition(arr, low, high);
        QuickSort(arr, low, p - 1);
        QuickSort(arr, p + 1, high);
    }
}

int main() {
    int n;
    int arr[20];

    printf("Enter Size of array: \n");
    scanf("%d", &n);

    printf("Enter elements of array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Given array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    QuickSort(arr, 0, n - 1);  // ✅ Correct range

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
