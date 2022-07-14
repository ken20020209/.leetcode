#include "../header/leetcode.h"
typedef struct HeapNode
{
    void *key;
    void *value;
} HeapNode;
typedef struct Heap
{
    int size;
    void **HeapNode;
} Heap;

#define left(a) (2 * (a) + 1);
#define right(a) (2 * (a) + 2);
#define parent(a) ((a) / 2)
#define arrSize 10
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void arrprintf(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void ShuffleArr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        swap(&arr[i], &arr[rand() % size]);
    }
}
void MaxHeap(int *arr, int size, int index)
{
    int left = left(index);
    int right = right(index);
    int largest = index;
    if (left < size && arr[left] > arr[index])
        largest = left;
    if (right < size && arr[right] > arr[largest])
        largest = right;
    if (largest != index)
    {
        swap(&arr[index], &arr[largest]);
        MaxHeap(arr, size, largest);
    }
}

void HeapIncreaseInsert(int *arr, int size, int index, int val)
{
    if (index < size)
    {
        if (arr[index] > val)
        {
            printf("key smaller than current key\n");
            return;
        }
        arr[index] = val;
        while (index > 0 && parent(index) < arr[index])
        {
            swap(&arr[index], &arr[parent(index)]);
            index = parent(index);
        }
    }
}
void HeapSort(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        swap(&arr[0], &arr[size - 1 - i]);
        MaxHeap(arr, size - 1 - i, 0);
    }
}
void HeapCreate(int *arr, int size)
{
    for (int i = (size) / 2; i >= 0; i--)
        MaxHeap(arr, size, i);
}
int main()
{
    int arr[arrSize];
    for (int i = 0; i < arrSize; i++)
    {
        arr[i] = i;
    }
    arrprintf(arr, arrSize);
    ShuffleArr(arr, arrSize);
    arrprintf(arr, arrSize);
    HeapCreate(arr, arrSize);
    arrprintf(arr, arrSize);
    HeapIncreaseInsert(arr, arrSize, 5, -3);
    arrprintf(arr, arrSize);
    return 0;
}