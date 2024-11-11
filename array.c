#include "array.h"
#include <stdio.h>
#include <stdlib.h>
void randArrayInput(int* a, int size)
{
	for (int i = 0; i < size; i++)
		a[i] = rand() % 51 - rand() % 51;
}
void outputArray(int* a, int size)
{
	for (int i = 0; i < size; i++)
		printf("%i. %i\n", i + 1, a[i]);
}
int sumArray(int* a, int x, int y)
{
	int sum = 0;
	for (int i = x; i <= y; i++)
		sum += a[i];
	return sum;
}