#include "heap.h"

void swapNode(node *a, node *b)
{
    node temp = *a;
    *a = *b;
    *b = temp;
}
//sorting


//apply the parental nodedownheap algorithm in the array representation
//isplays the heap as a20×10array, a row for an object.
void minHeapUp(node *heap, int nodeIndex, int size)
{
    int childIndex = 2 * nodeIndex + 1;
    // get minIndex
    int minIndex = nodeIndex;
    for (int i = 0; i < 2 && childIndex + i < size; i++)
    {
        // set new minIndex if found
        if (heap[childIndex + i].sum_key < heap[minIndex].sum_key)
        {
            minIndex = childIndex + i;
        }
    }
    // if there is a new found minIndex,  swap vals
    if (minIndex != nodeIndex)
    {
        swapNode(&heap[minIndex], &heap[nodeIndex]);
    }
    // check if left has child
    if (childIndex < size)
    {
        minHeapUp(heap, childIndex, size);
    }
    // check if right has child
    if (childIndex + 1 < size)
    {
        minHeapUp(heap, childIndex + 1, size);
    }
}

void minHeapDown(node *heap, int nodeIndex, int size)
{
    int childIndex = 2 * nodeIndex + 1;
    if (childIndex < size)
    {
        minHeapDown(heap, childIndex, size);
    }
    if (childIndex + 1 < size)
    {
        minHeapDown(heap, childIndex + 1, size);
    }
  
    int minIndex = nodeIndex;
    for (int i = 0; i < 2 && childIndex + i < size; i++)
    {
 
        if (heap[childIndex + i].sum_key < heap[minIndex].sum_key)
        {
            minIndex = childIndex + i;
        }
    }
  
    if (minIndex != nodeIndex)
    {
        swapNode(&heap[minIndex], &heap[nodeIndex]);
    }
}

//build the heap from the array
void buildHeap(node *heap, int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        minHeapDown(heap, i, size);
    }
}


