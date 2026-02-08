#include <stdio.h>
#define MAX_SIZE 100

void swapVal(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

/* min heap ko lagi heapify */
void minHeapFix(int arr[], int n, int idx)
{
    int smallest = idx;
    int l = 2 * idx + 1;
    int r = 2 * idx + 2;

    if (l < n && arr[l] < arr[smallest])
        smallest = l;

    if (r < n && arr[r] < arr[smallest])
        smallest = r;

    if (smallest != idx)
    {
        swapVal(&arr[idx], &arr[smallest]);
        minHeapFix(arr, n, smallest);
    }
}

/* min heap banaune */
void makeMinHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapFix(arr, n, i);
}

/* max heap ko lagi heapify */
void maxHeapFix(int arr[], int n, int idx)
{
    int largest = idx;
    int l = 2 * idx + 1;
    int r = 2 * idx + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != idx)
    {
        swapVal(&arr[idx], &arr[largest]);
        maxHeapFix(arr, n, largest);
    }
}

/* max heap banaune */
void makeMaxHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapFix(arr, n, i);
}

void showArray(int arr[], int n, const char *msg)
{
    printf("%s: ", msg);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {15, 20, 13, 5, 96, 71};
    int n = sizeof(arr) / sizeof(arr[0]);

    int minH[MAX_SIZE], maxH[MAX_SIZE];

    for (int i = 0; i < n; i++)
    {
        minH[i] = arr[i];
        maxH[i] = arr[i];
    }

    makeMinHeap(minH, n);
    showArray(minH, n, "Min Heap");

    makeMaxHeap(maxH, n);
    showArray(maxH, n, "Max Heap");

    return 0;
}
