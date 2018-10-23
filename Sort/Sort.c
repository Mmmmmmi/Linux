#include <stdio.h>

void Swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void SelectSort(int array[], int size)
{
    int min = 0;
    int max = 0;
    int left = 0;
    int right = size - 1;
    while(left < right) {
        min = left;
        max = right;
        for (int j = 0; j <= right; j++) {

            if (array[left + j] > array[max]) {
                max = j;
            }
            if (array[left + j] < array[min]) {
                min = j;
            }
            if (min != left) {
                Swap(array + min, array + left);
            }
            if (max == left) {
                max = min;
            }
            if (max != right) {
                Swap(array + max, array + right);
            }
        }
        left++;
        right--;
    }
}

void AdjustDown(int array[], int size, int root)
{
    int left = 2 * root + 1;
    int right = 2 * root + 2;
    if (left >= size) {
        return;
    }
    int max = array[left];
    if (right < size && array[right] > array[left]) {
        max = right;
    } 
    if (array[root] >= array[max]) {
        return;
    }
    
    Swap(array + root, array + max);
    
    AdjustDown(array, size, max);


}

void CreatHeap(int array[], int size)
{
    int root = (size - 1 - 1) / 2;
    while(root >= 0) {
        AdjustDown(array, size, root);
        root--;
    } 
    
}

void BubbleSort(int array[], int size)
{
    int flag = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 -i; j++) {
            if (array[j] > array[j + 1]) {
                Swap(array + j, array + j + 1);
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }
}

int Partition_02(int array[], int left, int right)
{
    int begin = left;
    int end = right;
    int tmp = array[right];
    while(begin < end) {
        while(begin < end && array[end] <= tmp) {
            begin++;
        }
        array[end] = array[begin];
        while(begin < end && array[end] >= tmp) {
            end--;
        }
        array[begin] = array[end];
    }
    array[begin] = tmp;
    return begin;
}

void Print(int array[], int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}


int main()
{
    int array[] = {2, 6, 5, 3, 4, 1, 0, 8, 9, 7};
    int size = sizeof(array) / sizeof(array[0]);
    Print(array, size);
    Partition_02(array, 0, size - 1);
    Print(array, size);
    return 0;
}

