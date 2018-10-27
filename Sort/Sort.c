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

int Partition_01(int array[], int left, int right)
{
    int start = left;
    int end = right - 1;
    while(start < end) {
        while(start < end && array[start] <= array[right]) {
            start++;
        }
        while(start < end && array[end] >= array[right]) {
            end--;
        }
        Swap(array + start, array + end);
    }
    Swap(array + end, array + right);
    return start;
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

int Partition_03(int array[], int left, int right)
{
    int i = left, j = left;            // i 是大于基准的最左边  j 是小于基准的最右边
    while(i < right) {
        if (array[i] < array[right]) {
            if (i != j) {                                           //i,j 指向同一个 不用交换
                Swap(array + i, array + j);
                j++;
            }
        }
        i++;
    }
    Swap(array + j + 1, array + right);
    return j;
}
void Print(int array[], int size);
void QuickSort(int array[], int size)
{
    printf("size = %d\n", size);
    int left = 0;
    int right = size - 1;
    int i = Partition_01(array, left, right);
    if (i == 0) {
        return;
    }
    Print(array, size);
    QuickSort(array, i);
    Print(array, size);
    QuickSort(array + i + 1, size - i - 1);

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
    int array[] = {2, 6, 4, 3, 7, 1, 0, 8, 9, 5};
    int size = sizeof(array) / sizeof(array[0]);
    Print(array, size);
    QuickSort(array, size);
    Print(array, size);
    return 0;
}

