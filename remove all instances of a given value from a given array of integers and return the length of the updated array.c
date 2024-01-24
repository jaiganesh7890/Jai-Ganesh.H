//Write a C program to remove all instances of a given value from a given array of integers and return the length of the updated array. >
//Expected Output:
//Original array: 1 1 2 3 4 4 5 6 6 6
// Size of the new array after removing the value 4: 8

 #include <stdio.h>

int removeInstances(int arr[], int n, int value) {
    int i, j;
    for (i = 0, j = 0; i < n; i++) {
        if (arr[i] != value) {
            arr[j] = arr[i];
            j++;
        }
    }
    return j;
}

int main() {
    int arr[] = {1, 1, 2, 3, 4, 4, 5, 6, 6, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int value = 4;

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    int newSize = removeInstances(arr, n, value);

    printf("\nSize of the new array after removing the value %d: %d\n", value, newSize);

    return 0;
}
