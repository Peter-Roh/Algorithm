#include <stdio.h>
#include <ArrayStack.c>

void Swap(int* A, int* B)
{
	int Temp = *A;
	*A = *B;
	*B = Temp;
}

int Partition(int DataSet[], int Left, int Right)
{
	int First = Left;
	int Pivot;
	if((DataSet[First] > DataSet[First + 1]) && (DataSet[First + 1] > DataSet[First + 2]))
	{
		Swap(&DataSet[First + 1], &DataSet[First]);
	}
	else if((DataSet[First] < DataSet[First + 1]) && (DataSet[First + 1] < DataSet[First + 2]))
	{
		Swap(&DataSet[First + 1], &DataSet[First]);
	}
	else if((DataSet[First] > DataSet[First + 1]) && (DataSet[First + 1] < DataSet[First + 2]))
		if(DataSet[First] < DataSet[First + 2])
		{
			Pivot = DataSet[First];
		}
		else
		{
			Swap(&DataSet[First + 2], &DataSet[First]);
		}
	else if((DataSet[First] < DataSet[First + 1]) && (DataSet[First + 1] > DataSet[First + 2]))
		if(DataSet[First] < DataSet[First + 2])
		{
			Swap(&DataSet[First + 2], &DataSet[First]);
		}
		else
			Pivot = DataSet[First];

	Pivot = DataSet[First];
	++Left;

	while(Left <= Right)
	{
		while(DataSet[Left] <= Pivot && Left < Right)
			++Left;
		while(DataSet[Right] > Pivot && Left <= Right)
			--Right;
		if(Left < Right)
			Swap(&DataSet[Left], &DataSet[Right]);
		else
			break;
	}

	Swap(&DataSet[First], &DataSet[Right]);

	return Right;
}

void QuickSort(int DataSet[], int Left, int Right)
{
	int i;

	if(Left < Right)
	{
		int Index = Partition(DataSet, Left, Right);

		for(i = ; i ; i--)

		QuickSort(DataSet, Left, Index - 1);
		QuickSort(DataSet, Index + 1, Right);
	}
}

int main(void)
{
	int i = 0;

	ArrayStack* Stack = NULL;
	AS_CreateStack(&Stack, 6);

	AS_Push(Stack, 6);
	AS_Push(Stack, 4);
	AS_Push(Stack, 2);
	AS_Push(Stack, 3);
	AS_Push(Stack, 1);
	AS_Push(Stack, 5);

	int Length = AS_GetSize(Stack);

	ArrayStack* Temp = NULL;
	AS_CreateStack(&Temp, 2 * Length);


	QuickSort(DataSet, 0, Length - 1);

	for(i = 0; i < Length; i++)
	{
		printf("%d ", DataSet[i]);
	}

	printf("\n");

	return 0;
}