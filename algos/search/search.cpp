#include <iostream>

// Iterates across each element in the array and returns location of value.
// Returns -1 if could not find value.
// Does not handle duplicates.
int linear_search(int arr[], int size, int val) {
    for(int i = 0; i < size; i++)
        if(arr[i] == val)
            return i;
    return -1;
}

// Searches a sorted array by recursively dividing the searchable area in half.
// If middle of array is greater or less than value, divide the array.
// Continue until middle is equal or value is not found
int binary_search(int array[], int l, int r, int target)
{
    if(r >= l)
    {
        int mid = l + (r-l) / 2; // Avoid integer overflow
        if(target == array[mid]) return mid;
        return array[mid] > target ? binary_search(array, l, mid-1, target) 
                                   : binary_search(array, mid+1, r, target);
    }
    return -1;
}

int main()
{
    // Unsorted
    int arr1[] = {29, 2, 77, 95, 876, 9};
    int val1 = 876;
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    // Sorted
    int arr2[] = {10, 15, 30, 100, 101, 256};
    int val2 = 100;
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    std::cout << "Running linear search:\n"; 
    int index1 = linear_search(arr1, size1, val1);
    (index1 == -1) ? std::cout << "\tNo value found in array.\n" 
                  : std::cout << "\tValue found at index " << index1 << ".\n";
    
    std::cout << "Running binary search:\n"; 
    int index2 = binary_search(arr2, 0, size2, val2);
    (index2 == -1) ? std::cout << "\tNo value found in array.\n" 
                  : std::cout << "\tValue found at index " << index2 << ".\n";
    return 0;
}