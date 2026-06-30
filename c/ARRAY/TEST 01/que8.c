#include <stdio.h>

int deleteDuplicates(int arr[], int n, int temp[]) {
    int k = 0;
    
    for (int i = 0; i < n; i++) {
        int isDuplicate = 0;
        for (int j = 0; j < k; j++) {
            if (arr[i] == temp[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            temp[k] = arr[i];
            k++;
        }
    }
    return k;  // Return the new size of the array
}

int main() {
    int n;
    printf("Enter array size: \n");
    scanf("%d", &n);
    
    int arr[n], temp[n]; // temp array of same size
    printf("Enter array elements: \n");
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Given array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    int newSize = deleteDuplicates(arr, n, temp);
    
    printf("Array after removing duplicates: \n");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", temp[i]);
    }
    printf("\n");

    return 0;
}
