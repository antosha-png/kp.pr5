#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "load.h"

int main()
{
	system("chcp 1251");
	srand(time(NULL));
	int menu = 0;
	do
	{
		system("cls");
		printf("Выберите структуру хранения: \n");
		printf("1. Массив\n");
		printf("2. Матрица\n");
		scanf("%i", &menu);
		while (getchar() != '\n');
#ifdef _Linux
		switch (menu)
		{
		case 1:
		{
			LoadRun("libA.so");
			break;
		}
		case 2:
		{
			LoadRun("libM.so");
			break;
		}
		}
#else 
		switch (menu)
		{
		case 1:
		{
			LoadRun("libA.dll");
			break;
		}
		case 2:
		{
			LoadRun("libM.dll");
			break;
		}
		}
#endif
	} while (menu != 1 && menu != 2);
	getchar();
	return 0;
}



