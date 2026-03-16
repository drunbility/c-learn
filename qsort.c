#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        /* code */
        if (arr[j] <= pivot) {
            /* code */
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

int hpartition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;
    while (1) {
        /* code */
        do {
            i++;
        } while (arr[i] < pivot);
        do {
            /* code */
            j--;
        } while (arr[j] > pivot);
        if (i >= j) {
            return j;
        }

        swap(&arr[i], &arr[j]);
    }
}

void qksort(int arr[], int low, int high) {
    if (low < high) {
        /* code */
        // int pi = partition(arr, low, high);
        // qksort(arr, low, pi - 1);
        // qksort(arr, pi + 1, high);
        int pi = hpartition(arr, low, high);
        qksort(arr, low, pi);
        qksort(arr, pi + 1, high);
    }
}

void parr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");

    printf("end\n");
}

int main() {
    int arr[] = {10, 3, 7, 23, 4, 8, 33};
    int n = (sizeof(arr) / sizeof(arr[0]));
    parr(arr, n);
    qksort(arr, 0, n - 1);
    parr(arr, n);
    return 0;
}