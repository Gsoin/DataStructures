#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int sum_key;
	int key[3];
	int content[7];
} node;

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
    // if found new minIndex
    // swap vals
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
    // check if left has child
    if (childIndex < size)
    {
        minHeapDown(heap, childIndex, size);
    }
    // check if right has child
    if (childIndex + 1 < size)
    {
        minHeapDown(heap, childIndex + 1, size);
    }
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
    // if found new minIndex
    // swap vals
    if (minIndex != nodeIndex)
    {
        swapNode(&heap[minIndex], &heap[nodeIndex]);
    }
}

int main(void)
{
    FILE *fp = fopen("f.dat", "r");
    node *heap = loadDat(fp);
    fclose(fp);

    minHeapDown(heap, 0, 20);
    minHeapUp(heap, 0, 20);

    // print heap
    for (int i = 0; i < ROWS; i++)
    {
        printNode(heap[i]);
    }
    return 0;
}
