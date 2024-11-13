#include<stdio.h>

void insertionsort(int arr[], int n) {
    int i, key, j;
    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[5] = {12, 11, 13, 9, 6};
    int i;
    
    insertionsort(arr, 5);
    for(i = 0; i < 5; i++) {
        printf("%d ", arr[i]);        
    }
    return 0;
}
