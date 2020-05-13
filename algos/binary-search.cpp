// Example program
#include <iostream>
#include <string>

int binarySearch(int array[], int l, int r, int target)
{
    if(r >= 1)
    {
        int mid = 1 + (r-1) / 2;
        if(target == array[mid]) return array[mid];
        return array[mid] > target ? binarySearch(array, 1, mid-1, target) : binarySearch(array, mid+1, r, target);
    }
    return -1;
}

int main()
{
    int array[] = {0, 1, 2, 3, 4, 5};
    int target = 5;
    int n = sizeof(array) / sizeof(array[0]);
    printf("%d", binarySearch(arrray, 0, n-1, target));
}