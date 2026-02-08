# Min Heap and Max Heap Implementation (C)

## Overview
This program demonstrates how to create **Min Heap** and **Max Heap** from an unsorted array using **heapify** operations.

- Min Heap: parent node is smaller than its children  
- Max Heap: parent node is larger than its children  

Both heaps are implemented using arrays.

---

## Heap Representation
For an element at index `i`:
- Left child: `2*i + 1`
- Right child: `2*i + 2`

The heap is stored in a normal integer array.

---

## Swap Function
```c
void swapVal(int *x, int *y);
