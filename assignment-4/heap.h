typedef struct Node
{
      int sum_key;
      int key[3];
      int content[7];
} node;


void swapNode(node *a, node *b);

void minHeapUp(node *heap, int nodeIndex, int size);


void minHeapDown(node *heap, int nodeIndex, int size);

void buildHeap(node *heap, int size);
