#include <stdio.h>

void BubbleSort(int DataSet[], int Length)
{
	int i = 0;
	int j = 0;
	int temp = 0;
	int flag;

	for(i = 0; i < Length - 1; i++)
	{
		flag = 0;

		for(j = 0; j < Length - (i + 1); j++)
		{
			if(DataSet[j] > DataSet[j + 1])
			{
				temp = DataSet[j + 1];
				DataSet[j + 1] = DataSet[j];
				DataSet[j] = temp;
				flag = 1;
			}
		}

		if(flag == 0)
		{
			return;
		}
	}
}

int main(void)
{
	int DataSet[] = {6, 4, 2, 3, 1, 5};
	int DataSet2[] = {1, 2, 3, 4, 5, 6, 7};
	int Length = sizeof DataSet / sizeof DataSet[0];
	int Length2 = sizeof DataSet2 / sizeof DataSet2[0];
	int i = 0;

	BubbleSort(DataSet, Length);

	for(i = 0; i < Length; i++)
	{
		printf("%d ", DataSet[i]);
	}

	printf("\n");

	BubbleSort(DataSet2, Length2);

	for(i = 0; i < Length2; i++)
	{
		printf("%d ", DataSet2[i]);
	}

	printf("\n");

	return 0;
}