#include <stdio.h>
#include <string.h>
#include <time.h>
#include "Score.h"

void InsertionSort(Score DataSet[], int Length)
{
	int i = 0;
	int j = 0;
	Score value;

	for(i = 1; i < Length; i++)
	{
		if(DataSet[i - 1].score <= DataSet[i].score)
		{
			continue;
		}

		value = DataSet[i];

		for(j = 0; j < i; j++)
		{
			if(DataSet[j].score > value[0].score)
			{
				memmove(&DataSet[j + 1], &DataSet[j], sizeof(DataSet[0]) * (i - j));
				DataSet[j] = value;
				break;
			}
		}
	}
}

int main(void)
{
	int Length = sizeof DataSet / sizeof DataSet[0];
	int i = 0;
	clock_t start, end;

	start = clock();
	InsertionSort(DataSet, Length);
	end = clock();

	printf("%d %f \n", DataSet[17213].number, DataSet[17213].score);
	printf("%d %f \n", DataSet[0].number, DataSet[0].score);
	printf("%3lf sec\n", (double)(end - start)/(double) 1000);

	return 0;
}