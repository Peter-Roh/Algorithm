#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef int ElementType;

typedef struct tHeap{
    ElementType *heapAry;
    int maxSize;
    int size;
} Heap;

Heap* heapCreate(int size);
void InsertHeap(Heap *pHeap, ElementType data);
void ReheapUp(Heap *pHeap, int idx);
int DeleteHeap(Heap *pHeap, ElementType *pDataOut);
void ReheapDown(Heap *pHeap, int idx);
void BuildHeap(Heap* pHeap);
int heapCount(Heap* heap);
bool heapFull(Heap* heap);
bool heapEmpty(Heap* heap);
