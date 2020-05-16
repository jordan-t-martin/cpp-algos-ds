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

// Takes the minimum value on each pass and adds to sorted partition
// Needs to make as many passes as there are elements
void selection_sort(int arr[], int size) {
    int i, j, min;
    for(i = 0; i < size - 1; i++){
        min = i;
        for(j = i+1; j < size; j++)
            if(arr[j] < arr[min])
                min = j;
        if(min != j)
            swap(arr[min], arr[i]);
    }
}

// Merge two arrays together
void merge(int arr[], int l, int m, int r) {
    // Array to hold sorted values
    int temp[r - l + 1];

    int i = l, j = m + 1, k = 0;

    // Iterate across both arrays and add lesser value to temp
    while(i <= m && j <= r) {
        if(arr[i] <= arr[j]) {
            temp[k] = arr[i];
            k++; i++;
        }
        else {
            temp[k] = arr[j];
            k++; j++;
        }
    }

    // Add the rest of first interval
    while (i <= m) {
        temp[k] = arr[i];
        k++; i++;
    }

    // Add the rest of second interval
    while (j <= r) {
        temp[k] = arr[j];
        k++; j++;
    }

    // Copy temp array to original array
    for(i = l; i <= r; i++)
        arr[i] = temp[i-l];
}

void merge_sort(int arr[], int l, int r) {
    if(l >= r)
        return;
    
    int m = l + (r-l) / 2; // Avoid integer overflow

    merge_sort(arr, l, m);
    merge_sort(arr, m+1, r);

    merge(arr, l, m, r);

}

int partition(int arr[], int low, int high) {
    // Pick rightmost as pivot 
    int pivot = high;
    // Index of smaller value
    int index = low;

    // Find correct index for the pivot
    for(int i = low; i < high; i++) {
        if(arr[i] < arr[pivot]) {
            swap(arr[i], arr[index]);
            index++;
        }
    }

    // Place pivot into correct index
    swap(arr[pivot], arr[index]);
    return(index);
}

void quick_sort(int arr[], int low, int high) {
    if(low < high) {
        // Partition array using rightmost as pivot
        int pivot = partition(arr, low, high);
        // Recursively call on each partition
        quick_sort(arr, low, pivot - 1);
        quick_sort(arr, pivot + 1, high);
    }
}

int main(void) {
    int arr1[] = {4, 1, 3, 9, 7};
    int arr2[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int arr3[] = {92, 40, 55, 22, 67, 152, 21};
    int arr4[] = {4, 2, 9, 6, 15, 22, 1};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    
    bubble_sort(arr1, size1);
    selection_sort(arr2, size2);
    merge_sort(arr3, 0, size3 - 1);
    quick_sort(arr4, 0, size4 - 1);

    printf("Bubble sorted array:\n\t");
    int i;
    for(i = 0; i < size1; i++)
        std::cout << arr1[i] << " ";
    std::cout << "\nSelection sorted array:\n\t";
    for(i = 0; i < size2; i++)
        std::cout << arr2[i] << " ";
    std::cout << "\nMerge sorted array:\n\t";
    for(i = 0; i < size3; i++)
        std::cout << arr3[i] << " ";
    std::cout << "\nQuick sorted array:\n\t";
    for(i = 0; i < size4; i++)
        std::cout << arr4[i] << " ";
    
    return 0;
}