#include "load.h"

void LoadRun(const char* const s) {
	LIB_HANDLE lib;
	lib = LOAD_LIBRARY(s); //загрузка библиотеки в память;
	if (!lib)
	{
		printf("Ошибка загрузки библиотеки\n", s);
		return;
	}

	if (strcmp(s, "libA.dll") == 0 || strcmp(s, "libA.so") == 0)
	{
		
		void (*input)(int*, int);
		void (*output)(int*, int);
		int (*sum)(int*, int, int);
		input = (void (*)(int*, int))LOAD_FUNCTION(lib, "randArrayInput"); //получение указателя на функцию из библиотеки;
		output = (void (*)(int*, int))LOAD_FUNCTION(lib, "outputArray"); //получение указателя на функцию из библиотеки;
		sum = (int (*)(int*, int, int))LOAD_FUNCTION(lib, "sumArray"); //получение указателя на функцию из библиотеки;

		if (input == NULL || output == NULL || sum == NULL)
			{
				printf("Ошибка загрузки функции\n");
				CLOSE_LIBRARY(lib);
				return;
			}

		int M[SIZE], x, y;
		input(M, SIZE);
		output(M, SIZE);
		getchar();

		printf("Введите диапазон [X, Y] для нахождения суммы элементов\n");
		printf("X: ");
		while (scanf("%i", &x) == 0 || x <= 0 || x > SIZE)
		{
			printf("Введите корректный X: ");
			while (getchar() != '\n');
		}
		printf("Y: ");
		while (scanf("%i", &y) == 0 || y <= 0 || y > SIZE)
		{
			printf("Введите корректный Y: ");
			while (getchar() != '\n');
		}

		int sum_;
		if (x < y)
		{
			sum_ = sum(M, x - 1, y - 1);
			printf("Сумма [%i, %i] элементов равна %i", x, y, sum_);
		}
		else
		{
			sum_ = sum(M, y - 1, x - 1);
			printf("Сумма [%i, %i] элементов равна %i", y, x, sum_);
		}
		
	}
	else if (strcmp(s, "libM.dll") == 0 || strcmp(s, "libM.so") == 0)
	{
		int** (*create)(int, int);
		void (*input)(int**, int, int);
		void (*output)(int**, int, int);
		int (*sum)(int**, int, int, int);
		input = (void (*)(int**, int, int))LOAD_FUNCTION(lib, "randMatrixInput"); //получение указателя на функцию из библиотеки;
		output = (void (*)(int**, int, int))LOAD_FUNCTION(lib, "outputMatrix"); //получение указателя на функцию из библиотеки;
		sum = (int (*)(int**, int, int, int))LOAD_FUNCTION(lib, "sumMatrixCol"); //получение указателя на функцию из библиотеки;
		create = (int** (*)(int, int))LOAD_FUNCTION(lib, "createMatrix"); //получение указателя на функцию из библиотеки;
		if (input == NULL || output == NULL || sum == NULL || create == NULL)
		{
			printf("Ошибка загрузки функции\n");
			CLOSE_LIBRARY(lib);
			return;
		}
		int** S;
		if (!(S = create(CNT, SIZE)))
		{
			perror("Ошибка выделения памяти");
			CLOSE_LIBRARY(lib);
			return;
		}
		int x, y;
		input(S, CNT, SIZE);
		output(S, CNT, SIZE);
		getchar();

		printf("Введите диапазон [X, Y] для нахождения суммы элементов в этих столбцах\n");
		printf("X: ");
		while (scanf("%i", &x) == 0 || x <= 0 || x > SIZE)
		{
			printf("Введите корректный X: ");
			while (getchar() != '\n');
		}
		printf("Y: ");
		while (scanf("%i", &y) == 0 || y <= 0 || y > SIZE)
		{
			printf("Введите корректный Y: ");
			while (getchar() != '\n');
		}

		int sum_;
		if (x < y)
		{
			sum_ = sum(S, CNT, x - 1, y - 1);
			printf("Сумма [%i, %i] столбцов равна %i", x, y, sum_);
		}
		else
		{
			sum_ = sum(S, CNT, y - 1, x - 1);
			printf("Сумма [%i, %i] столбцов равна %i", y, x, sum_);
		}
	}
	else 
	{
		printf("Данной библиотеки не существует");
	}
	CLOSE_LIBRARY(lib); //выгрузка библиотеки;
}