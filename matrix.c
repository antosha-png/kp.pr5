#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

int** createMatrix(int row, int col)
{
	int** m = malloc((sizeof(int*) * row));
	if (!m)
		return NULL;
	else
	{
		for (int i = 0; i < row; i++)
		{
			if (!(m[i] = malloc(sizeof(int) * col)))
				return NULL;
		}
		return m;
	}
}
void randArrayInput(int* a, int size)
{
	for (int i = 0; i < size; i++)
		a[i] = rand() % 51 - rand() % 51;
}
void randMatrixInput(int** m, int row, int col)
{
	for (int i = 0; i < row; i++)
		randArrayInput(m[i], col);
}
void outputMatrix(int** m, int row, int col)
{
	printf("\t");
	for (int j = 0; j < col; j++)
		printf("(%i)\t", j + 1);
	printf("\n");
	for (int i = 0; i < row; i++)
	{
		printf("%i)\t", i + 1);
		for (int j = 0; j < col; j++)
			printf("%i\t", m[i][j]);
		printf("\n");
	}
}
int sumArray(int* a, int x, int y)
{
	int sum = 0;
	for (int i = x; i <= y; i++)
		sum += a[i];
	return sum;
}
int sumMatrixCol(int** m, int row, int x, int y)
{
	int sum = 0;
	for (int i = 0; i < row; i++)
		sum += sumArray(m[i], x, y);
	return sum;
}