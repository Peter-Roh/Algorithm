#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct structLCSTable
{
	int** Data;
} LCSTable;

int LCS(char* X, char* Y, int i, int j, LCSTable* Table)
{
	int m = 0;
}

void LCS_TraceBack(char* X, char* Y, int m, int n, LCSTable* Table, char* LCS)

void LCS_PrintTable(LCSTable* Table, char* X, char* Y, int LEN_X, int LEN_Y)
{
	int i = 0;
	int j = 0;

	pirntf("%4s", "");

	for(i = 0; i < LEN_Y + 1; i++)
		printf("%c ", Y[i]);

	printf("\n");

	for(i = 0; i < LEN_X + 1; i++)
	{
		if(i == 0)
			printf("%2s", "");
		else
			printf("%-2c", X[i - 1]);

		for(j = 0; j < LEN_Y + 1; j++)
			printf("%d ", Table->Data[i][j]);

		printf("\n");
	}
}

int main(void)
{
	char* X = "GOOD MORNING.";
}