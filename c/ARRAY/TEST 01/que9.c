#include <stdio.h>

int intersection(int a[], int b[], int temp[], int n1, int n2) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (a[i] == b[j]) {
            temp[k] = a[i];
            i++;
            j++;
            k++;
        } 
        else if (a[i] < b[j]) { 
            i++; // Move i forward
        } 
        else {
            j++; // Move j forward
        }
    }
    return k; // Return the number of elements in intersection
}

int main() {
    int a[5] = {11, 21, 32, 44, 55};
    int b[7] = {11, 22, 32, 44, 55, 58, 60};
    int intersectedArray[5]; // Max size of intersection is min(n1, n2)

    int size = intersection(a, b, intersectedArray, 5, 7);

    printf("Intersection of Arrays:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", intersectedArray[i]);
    }
    printf("\n");

    return 0;
}
