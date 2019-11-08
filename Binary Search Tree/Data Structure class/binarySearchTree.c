#include "binarySearchTree.h"

BST_TREE* bstCreate() {
    BST_TREE* tree = (BST_TREE*)malloc(sizeof(BST_TREE));
    if(tree) {
        tree->root = NULL;
        tree->count = 0;
    }

    return tree;
}

void bstDestroy(BST_TREE* tree) {
    if(tree) {
        _bstDestroy(tree->root);
        tree->count = 0;

        free(tree);
    }
}

static void _bstDestroy(TREE_NODE* root) {
    if (root) {
        _bstDestroy(root->left);
        _bstDestroy(root->right);
        free(root);
    }
}

TREE_NODE* _bstInsert(TREE_NODE* tree, TREE_NODE* newNode) {
    if(tree == NULL)
        return newNode;

    if(newNode -> data < tree -> data)
        tree -> left = _bstInsert(tree -> left, newNode);
    else
        tree -> right = _bstInsert(tree -> right, newNode);

    return tree;
}

bool bstInsert(BST_TREE* tree, int data) {
    TREE_NODE* new = (TREE_NODE*)malloc(sizeof(TREE_NODE));
    if(new) {
        new -> data = data;
        new -> left = NULL;
        new -> right = NULL;
    }

    tree -> root = _bstInsert(tree -> root, new);

    return true;
}

static TREE_NODE* _bstDelete(TREE_NODE* tree, int data, int* success) {
    if(tree == NULL) {
        *success = false;
        return tree;
    }

    if(data < tree -> data)
        tree -> left = _bstDelete(tree -> left, data, success);
    else if(data > tree -> data)
        tree -> right = _bstDelete(tree -> right, data, success);
    else {
        TREE_NODE* delPtr = NULL;
        *success = true;

        if(!tree -> right) {
            delPtr = tree;
            tree = tree -> left;
            free(delPtr);
            return tree;
        }
        else if(!tree -> left) {
            delPtr = tree;
            tree = tree -> right;
            free(delPtr);
            return tree;
        }
        else {
            for(delPtr = tree -> left; delPtr -> right != NULL; delPtr = delPtr -> right);
            tree -> data = delPtr -> data;
            tree -> left = _bstDelete(tree -> left, delPtr -> data, success);
        }
    }

    return tree;
}

bool bstDelete(BST_TREE* tree, int key) {
    int* success;

    tree -> root = _bstDelete(tree -> root, key, success);

    return success;
}

static TREE_NODE* _bstSearch(TREE_NODE* tree, int key) {
    if(tree == NULL)
        return NULL;

    if(key < tree -> data)
        return _bstSearch(tree -> left, key);
    else if(key > tree -> data)
        return _bstSearch(tree -> right, key);
    else if(key == tree -> data)
        return tree;
}

TREE_NODE* bstSearch(BST_TREE* tree, int key) {
    return _bstSearch(tree -> root, key);
}

bool bstEmpty(BST_TREE* tree) {
    if(bstCount(tree) == 0)
        return true;
    else
        return false;
}

int bstCount(BST_TREE* tree) {
    return tree -> count;
}
