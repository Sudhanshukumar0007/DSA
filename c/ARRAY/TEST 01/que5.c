#include <stdio.h>
#include <limits.h>  // For INT_MIN and INT_MAX

int main() {
    int n;
    int max, min, second_max, second_min;

    printf("Enter array size: \n");
    scanf("%d", &n);

    if (n < 2) {
        printf("Array must have at least two distinct elements.\n");
        return 0;
    }

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

    // Initialize max and min
    max = min = arr[0];
    second_max = INT_MIN;
    second_min = INT_MAX;

    // Find max, min, second_max, and second_min
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            second_max = max;
            max = arr[i];
        } else if (arr[i] > second_max && arr[i] < max) {
            second_max = arr[i];
        }

        if (arr[i] < min) {
            second_min = min;
            min = arr[i];
        } else if (arr[i] < second_min && arr[i] > min) {
            second_min = arr[i];
        }
    }

    printf("Max: %d, Min: %d\n", max, min);

    // Handle cases when no second max or second min exists
    if (second_max == INT_MIN)
        printf("No second maximum exists.\n");
    else
        printf("Second Max: %d\n", second_max);

    if (second_min == INT_MAX)
        printf("No second minimum exists.\n");
    else
        printf("Second Min: %d\n", second_min);

    return 0;
}
