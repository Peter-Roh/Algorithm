#include <stdio.h>
#include <string.h>

void ARY_MoveToFront(int DataSet[], int length, int target)
{
	int match = 0;
	int i;

	for(i = 0; i < length; i++)
	{
		if(DataSet[i] == target)
		{
			match = DataSet[i];
			memmove(&DataSet[1], &DataSet[0], sizeof(DataSet[0]) * i);
			DataSet[0] = match;
		}
	}
}

int main(void)
{
	int DataSet[] = {71, 5, 13, 1, 2, 48, 222, 136, 3, 15};
	int i;
	int length = sizeof DataSet / sizeof DataSet[0];

	for(i = 0; i < length; i++)
	{
		printf("%d ", DataSet[i]);
	}

	printf("\n");
	ARY_MoveToFront(DataSet, length, 222);

	for(i = 0; i < length; i++)
	{
		printf("%d ", DataSet[i]);
	}

	printf("\n");

	return 0;
}