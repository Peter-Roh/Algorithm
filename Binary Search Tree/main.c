#include "binarySearchTree.h"

int main() {
    int data[] = {14, 23, 7, 10, 33, 56, 80, 66, 70};
    BST_TREE* bstTree = bstCreate();

    for(int i = 0; i < sizeof(data) / sizeof(int); i++) {
        bstInsert(bstTree, data[i]);
    }

    int delKey[] = {33, 7, 14};

    for(int i = 0; i < sizeof(delKey) / sizeof(int); i++) {
        bstDelete(bstTree, delKey[i]);
    }

    int retrieveKey[] = {14, 23, 7};

    for(int i = 0; i < sizeof(retrieveKey) / sizeof(int); i++) {
        TREE_NODE* node = bstSearch(bstTree, retrieveKey[i]);
        if(node) {
            printf("Key: %d, Founded: %d\n", retrieveKey[i], node -> data);
        }
        else {
            printf("No data for key: %d\n", retrieveKey[i]);
        }
    }

    bstDestroy(bstTree);

    return 0;
}
