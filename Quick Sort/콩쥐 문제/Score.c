#include "Score.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int CompareScore(const void *_elem1, const void *_elem2)
{
	Score* elem1 = (Score*)_elem1;
	Score* elem2 = (Score*)_elem2;

	if(elem1->score > elem2->score)
		return 1;
	else if(elem1->score < elem2->score)
		return -1;
	else
		return 0;
}

int main(void)
{
	int Length = sizeof DataSet / sizeof DataSet[0];
	int i = 0;
	clock_t start, end;

	start = clock();
	qsort((void*)DataSet, Length, sizeof (Score), CompareScore);
	end = clock();

	printf("%d %f \n", DataSet[17213].number, DataSet[17213].score);
	printf("%d %f \n", DataSet[0].number, DataSet[0].score);
	printf("%3lf sec\n", (double)(end - start)/(double) 1000);

	return 0;
}