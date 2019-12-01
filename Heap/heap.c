#include <math.h>
#include "heap.h"

Heap* heapCreate(int size) {
    Heap* heap = (Heap*)malloc(sizeof(Heap));

    if(!heap)
        return NULL;

    heap -> maxSize = (int)pow(2, ceil(log2(size))) - 1;
    heap -> heapAry = (int*)calloc(heap -> maxSize, sizeof(int));
    heap -> size = 0;

    return heap;
}

void InsertHeap(Heap *pHeap, ElementType data) {
    if(pHeap -> size >= pHeap -> maxSize) {
        printf("Heap is full!\n");
        return;
    }

    pHeap -> heapAry[pHeap -> size++] = data;
    ReheapUp(pHeap, pHeap -> size - 1);
}

void ReheapUp(Heap *pHeap, int idx) {
    int parentIdx = 0;
    ElementType curData = 0;

    if(idx <= 0 || idx >= pHeap -> size) return;

    curData = pHeap -> heapAry[idx];
    parentIdx = (idx - 1) / 2;

    while(idx > 0 && curData > pHeap -> heapAry[parentIdx]) {
        pHeap -> heapAry[idx] = pHeap -> heapAry[parentIdx];
        idx = parentIdx;
        parentIdx = (idx - 1)/ 2;
    }

    pHeap -> heapAry[idx] = curData;
}

int DeleteHeap(Heap *pHeap, ElementType *pDataOut) {
    if(pHeap -> size <= 0) {
        printf("Heap is empty!\n");
        return 0;
    }

    *pDataOut = pHeap -> heapAry[0];
    pHeap -> heapAry[0] = pHeap -> heapAry[--pHeap -> size];
    ReheapDown(pHeap, 0);

    return 1;
}

void ReheapDown(Heap *pHeap, int idx) {
    ElementType curData = 0;

    if(idx < 0 || idx >= pHeap -> size) return;

    curData = pHeap -> heapAry[idx];

    while(idx * 2 + 1 < pHeap -> size) {
        int maxChild = idx * 2 + 1;
        if(maxChild + 1 < pHeap -> size && pHeap -> heapAry[maxChild + 1] > pHeap -> heapAry[maxChild])
            maxChild++;

        if(pHeap -> heapAry[maxChild] > curData) {
            pHeap -> heapAry[idx] = pHeap -> heapAry[maxChild];
            idx = maxChild;
        }
        else
            break;
    }

    pHeap -> heapAry[idx] = curData;
}

void BuildHeap(Heap* pHeap) {
    for(int i = 1; i < pHeap -> size; i++)
        ReheapUp(pHeap, i);
}

int heapCount(Heap* heap) {
    return heap -> size;
}

bool heapFull(Heap* heap) {
    if(heap -> maxSize == heap -> size)
        return true;
    else
        return false;
}

bool heapEmpty(Heap* heap) {
    if(heap -> size == 0)
        return true;
    else
        return false;
}
