#include "ArrayStack.h"

void AS_CreateStack(ArrayStack** Stack, int Capacity)
{
	/* 스택을 자유 저장소에 생성 */
	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));

	/* 입력된 Capacity 만큼의 노드를 자유 저장소에 생성 */
	(*Stack)->Nodes = (Node*)malloc(sizeof(Node)*Capacity);

	/* Capacity 및 Top 초기화 */
	(*Stack)->Capacity = Capacity;
	(*Stack)->Top = 0;
}

void AS_DestroyStack(ArrayStack* Stack)
{
	/* 노드를 자유 저장소에서 해제 */
	free(Stack->Nodes);

	/* 스택을 자유 저장소에서 해제 */
	free(Stack);
}

void AS_Push(ArrayStack* Stack, ElementType Data)
{
	int Position = Stack->Top;

	if(AS_IsFull(Stack) == 1)
	{
		(*Stack).Nodes = (Node*)realloc(Stack->Nodes, sizeof(Node)*ceil(Stack->Capacity*1.3));
		(*Stack).Capacity = (int)ceil((*Stack).Capacity*1.3);
	}

	Stack->Nodes[Position].Data = Data;
	Stack->Top++;
}

ElementType AS_Pop(ArrayStack* Stack)
{
	int Position = --(Stack->Top);
	int temp;

	temp = Stack->Nodes[Position].Data;

	if(AS_GetSize(Stack) < (*Stack).Capacity * 0.7)
	{
		(*Stack).Nodes = (Node*)realloc(Stack->Nodes, sizeof(Node)*ceil(Stack->Capacity*0.7));
		(*Stack).Capacity = (int)ceil(Stack->Capacity*0.7);
	}

	return temp;
}

ElementType AS_Top(ArrayStack* Stack)
{
	int Position = Stack->Top - 1;

	return Stack->Nodes[Position].Data;
}

int AS_GetSize(ArrayStack* Stack)
{
	return Stack->Top;
}

int AS_IsEmpty(ArrayStack* Stack)
{
	return(Stack->Top == 0);
}

int AS_IsFull(ArrayStack* Stack)
{
	return(Stack->Capacity == Stack->Top);
}