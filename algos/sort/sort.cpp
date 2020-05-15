#include <iostream>

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Swaps adjacent elements in wrong order on each pass
// Keeps sorting until pass without any swap
void bubble_sort(int arr[], int size) {
    int i, j;
    for(i = 0; i < size - 1; i++)
        for(j = 0; j < size - i - 1; j++)
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
}

int main(void) {
    int arr1[] = {4, 1, 3, 9, 7};
    int arr2[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    bubble_sort(arr1, size1);
    bubble_sort(arr2, size2);

    printf("Sorted array:\n\t");
    int i;
    for(i = 0; i < size1; i++)
        std::cout << arr1[i] << " ";
    std::cout << "\nSorted array:\n\t";
    for(i = 0; i < size2; i++)
        std::cout << arr2[i] << " ";
    
    return 0;
}