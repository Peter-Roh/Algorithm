#include "ArrayStack.h"

void Swap(int* A, int* B)
{
	int Temp = *A;
	*A = *B;
	*B = Temp;
}

void QuickSort(int DataSet[], ArrayStack* Stack, int Left, int Right)
{
	int Pivot;
	int Low, High;

	AS_Push(Stack, Right);
	AS_Push(Stack, Left);

	while(!AS_IsEmpty(Stack))
	{
		Left = AS_Pop(Stack);
		Right = AS_Pop(Stack);

		if(Right - Left > 0)
		{
			Pivot = DataSet[Right];
			Low = Left - 1;
			High = Right;

			while(1)
			{
				while(DataSet[++Low] < Pivot);
				while(DataSet[--High] > Pivot);

				if(Low >= High)
					break;

				Swap(&DataSet[Low], &DataSet[High]);
			}

			Swap(&DataSet[Low], &DataSet[Right]);

			AS_Push(Stack, Right);
			AS_Push(Stack, Low+ 1);
			AS_Push(Stack, Low - 1);
			AS_Push(Stack, Left);
		}
	}
}

int main(void)
{
	int DataSet[] = {6, 4, 2, 3, 1, 5};
	int Length = sizeof DataSet / sizeof DataSet[0];

	ArrayStack* Stack = NULL;
	AS_CreateStack(&Stack, Length);

	int i = 0;

	QuickSort(DataSet, Stack, 0, Length - 1);

	for(i = 0; i < Length; i++)
	{
		printf("%d ", DataSet[i]);
	}

	printf("\n");

	return 0;
}