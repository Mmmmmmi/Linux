
#include "Heap.h"


int main()
{
    Heap heap;
    HDataType array[] = { 53, 17, 78, 9, 45, 65, 87, 23, 31};
    int size = sizeof(array) / sizeof (array[0]);
    HeapInitialize(&heap, array, size);
    CreateHeap(&heap); 
    Print(&heap);
    HeapPush(&heap, 99);
    Print(&heap);
    return 0;
}

