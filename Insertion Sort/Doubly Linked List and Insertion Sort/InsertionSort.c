#include <stdio.h>
#include <string.h>
#include "DoublyLinkedList.h"

void DLL_InsertionSort(Node **phead)
{
	Node *head = *phead;
	Node *search = head;
	Node *next = search->NextNode;
	Node *find = head;
	ElementType e1, e2;

	while (next)
	{
		e1 = search->Data;
		e2 = next->Data;

		if (e1 <= e2)
		{
			search = next;
			next = next->NextNode;
			continue;
		}

		search->NextNode = next->NextNode;
		if(next->NextNode != NULL)
			next->NextNode->PrevNode = search;

		while (find != search->NextNode)
		{
			e1 = find->Data;

			if (e1 > e2)
			{
				next->NextNode = find;
				next->PrevNode = find->PrevNode;

				if (find->PrevNode != NULL)
					find->PrevNode->NextNode = next;

				find->PrevNode = next;

				if (find == head)
					head = next;

				find = head;
				break;
			}

			find = find->NextNode;
		}

		next = search->NextNode;
	}

	*phead = head;
}

int main(void)
{
	int i = 0;
	int Count = 0;
	Node* List = NULL;
	Node* NewNode = NULL;
	Node* Current = NULL;

	NewNode = DLL_CreateNode(6);
	DLL_AppendNode(&List, NewNode);

	NewNode = DLL_CreateNode(4);
	DLL_AppendNode(&List, NewNode);

	NewNode = DLL_CreateNode(8);
	DLL_AppendNode(&List, NewNode);

	NewNode = DLL_CreateNode(2);
	DLL_AppendNode(&List, NewNode);

	NewNode = DLL_CreateNode(3);
	DLL_AppendNode(&List, NewNode);

	NewNode = DLL_CreateNode(1);
	DLL_AppendNode(&List, NewNode);

	NewNode = DLL_CreateNode(5);
	DLL_AppendNode(&List, NewNode);

	NewNode = DLL_CreateNode(7);
	DLL_AppendNode(&List, NewNode);

	Count = DLL_GetNodeCount(List);
	for(i = 0; i < Count; i++)
	{
		Current = DLL_GetNodeAt(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}

	printf("\n");

	DLL_InsertionSort(&List);

	Count = DLL_GetNodeCount(List);
	for(i = 0; i < Count; i++)
	{
		Current = DLL_GetNodeAt(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}

	for(i = 0; i < Count; i++)
	{
		Current = DLL_GetNodeAt(List, 0);

		if(Current != NULL)
		{
			DLL_RemoveNode(&List, Current);
			DLL_DestroyNode(Current);
		}
	}

	return 0;
}