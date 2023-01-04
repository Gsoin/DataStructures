#include <stdio.h>
// creating structure that conatin the key of the object and the position of that object in the original array
struct s
{
    int key;
    int pos;
};
// creating max_heap
struct s *create_max_heap(struct s a[], int n)
{
    int heapsize = n;
    int j;
    for (j = n / 2; j >= 0; j--)
    {
        maxheapify(a, j, heapsize);
    }
    return a;
}
// function to max_heapify the struct array
void maxheapify(struct s a[], int i, int heapsize)
{
    struct s temp;
    int largest, left, right, k;
    left = (2 * i + 1);
    right = ((2 * i) + 2);
    if (left >= heapsize)
        return;
    else
    {
        if (left < (heapsize) && a[left].key > a[i].key)
            largest = left;
        else
            largest = i;
        if (right < (heapsize) && a[right].key > a[largest].key)
            largest = right;
        if (largest != i)
        {
            temp = a[i];
            a[i] = a[largest];
            a[largest] = temp;
            maxheapify(a, largest, heapsize);
        }
    }
}
int main()
{

    FILE *f;
    f = fopen("f.dat", "r");

    int a[20][10];
    int i, j;
    // input in 20*10 matrix
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 10; j++)
        {
            fscanf(f, "%d", &a[i][j]);
        }
    }
    // creating array of object each object conatin key and it's position in input array
    struct s k[20];
    for (i = 0; i < 20; i++)
    {
        k[i].pos = i;
        int sum = 0;
        for (j = 0; j < 3; j++)
        {
            sum = sum + a[i][j];
        }
        k[i].key = sum;
    }
    // creating max heap on the basis of key
    create_max_heap(k, 5);
    // printing of array as their position in max_heap
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 10; j++)
        {
            printf("%d ", a[k[i].pos][j]);
        }
        printf("\n");
    }
}