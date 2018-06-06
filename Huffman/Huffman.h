#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <stdio.h>
#include <stdlib.h>
#include "PriorityQueue.h"

#define MAX_CHAR 256
#define MAX_BIT 8

typedef unsigned int UINT;
typedef unsigned char UCHAR;

typedef struct TagSymbolInfo
{
	UCHAR Symbol;
	int Frequency;
} SymbolInfo;

typedef struct TagHuffmanNode
{
	SymbolInfo Data;
	struct TagHuffmanNode* Left;
	struct TagHuffmanNode* Right;
} HuffmanNode;

typedef struct TagBitBuffer
{
	UCHAR* Buffer;
	UINT Size;
} BitBuffer;

typedef struct TagHuffmanCode
{
	UCHAR Code[MAX_BIT];
	int Size;
} HuffmanCode;

