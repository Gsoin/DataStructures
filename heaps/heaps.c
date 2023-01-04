#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int sum_key;
	int key[3];
	int content[7];
} Node;

void MaxHeapPercolateDown(int nodeIndex, Node heapArray[], int arraySize)
{
	int childIndex = 2 * nodeIndex + 1;
	int value = heapArray[nodeIndex].sum_key;

	while (childIndex < arraySize)
	{
		// Find the max among the node and all the node's children
		int maxValue = value;
		int maxIndex = -1;
		for (int i = 0; i < 2 && i + childIndex < arraySize; i++)
		{
			if (heapArray[i + childIndex].sum_key > maxValue)
			{
				maxValue = heapArray[i + childIndex].sum_key;
				maxIndex = i + childIndex;
			}
		}

		if (maxValue == value)
		{
			return;
		}
		else
		{
			nodeIndex = maxIndex;
			childIndex = 2 * nodeIndex + 1;
		}
	}
}

void Heapsort(Node numbers[], int numbersSize)
{
	// Heapify numbers array
	for (int i = numbersSize / 2 - 1; i >= 0; i--)
	{
		MaxHeapPercolateDown(i, numbers, numbersSize);
	}

	for (int i = numbersSize - 1; i > 0; i--)
	{
		MaxHeapPercolateDown(0, numbers, i);
	}
}

int main(int argc, char *argv[])
{
	FILE *file;
	file = fopen("f.dat", "r");
	int a[20][10];
	Node arr[20];

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			fscanf(file, "%d", &a[i][j]);
		}
	}

	// Fill the heap with array content
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j < 3)
			{
				arr[i].key[j] = a[i][j];
				arr[i].sum_key += a[i][j];
			}
			else
			{
				arr[i].content[j] = a[i][j];
			}
		}
	}

	Heapsort(arr, 20);
	// Print heap
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j < 3)
			{
				printf("%d ", arr[i].key[j]);
			}
			else
			{
				printf("%d ", arr[i].content[j]);
			}
		}
		printf("\n");
	}
	return 0;
}