#include <stdio.h>
#include <stdlib.h>

#include "heap.h"


node heap[20];
int main()
{
    //read from file
      FILE *fptr;
      int a[20][10];
      fptr = fopen("f.dat", "r");
      if (fptr == NULL)
      {
            printf("Error!");
            exit(1);
      }
      for (int i = 0; i < 20; i++)
      {
            for (int j = 0; j < 10; j++)
            {
                  fscanf(fptr, "%d", &a[i][j]);
            }
      }
      fclose(fptr);

      //build heap
      for (int i = 0; i < 20; i++)
      {
            heap[i].sum_key = 0;
            for (int j = 0; j < 3; j++)
            {
                  heap[i].key[j] = a[i][j];
                  heap[i].sum_key += a[i][j];
            }
            for (int j = 0; j < 7; j++)
            {
                  heap[i].content[j] = a[i][j + 3];
            }
      }
      buildHeap(heap, 20);

      //print heap
      for (int i = 0; i < 20; i++)
      {
            // printf("%d ", heap[i].sum_key);
            for (int j = 0; j < 3; j++)
            {
                  if(heap[i].key[j] < 10)
                        printf("0%d ", heap[i].key[j]);
                  else
                        printf("%d ", heap[i].key[j]);
            }
            for (int j = 0; j < 7; j++)
            {
                  if(heap[i].content[j] < 10)
                        printf("0%d ", heap[i].content[j]);
                  else
                        printf("%d ", heap[i].content[j]);
            }
            printf("\n");


      }
      return 0;
}

