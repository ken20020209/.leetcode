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
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i;
    }
    for (int i = 0; i < 10; i++)
    {
        swap(&arr[i], &arr[rand() % 10]);
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d \n", arr[i]);
    }
    printf("\n");

    return 0;
} 