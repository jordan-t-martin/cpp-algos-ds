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

int pairsOfKDiff(int array[], int size, int k)
{
    int count = 0;, targetPlus, targetMinus;
    for(int i = 0; i < size; i++)
    {
        targetPlus = array[i] + k;
        targetMinus = array[i] - k;
        if(binarySearch(array, i+1, size-1, targetPlus) != -1)
        {
            count++;
            printf("(%d, %d)\n", array[i], targetPlus);
        }
        if(binarySearch(array, i+1, size-1, targetMinus) != -1)
        {
            count++;
            printf("(%d, %d)\n", array[i], targetMinus);
        }
    }
    return count;
}

int main()
{
    int array [] = {1, 7, 5, 9, 2, 12 };
    int k = 2;
    int size = sizeof(array) / sizeof(array[0]);
    printf("%d", pairsOfKDiff(array, size, k));
}