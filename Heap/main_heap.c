#include "heap.h"

int main(void) {
    int size = 10;
    Heap* heap = heapCreate(size);
    int arr[10] = {5, 6, 4, 1, 3, 8, 7, 9, 2, 10};

    for(int i = 0; i < 10; i++) {
        InsertHeap(heap, arr[i]);
    }

    printf("%d\n", heap -> heapAry[0]);

    int* pDataOut = (int*)malloc(sizeof(int));
    *pDataOut = 10;

    DeleteHeap(heap, pDataOut);

    printf("%d\n", heap -> heapAry[0]);

    free(pDataOut);
    free(heap -> heapAry);
    free(heap);

    return 0;
}
