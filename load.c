#include "load.h"

void LoadRun(const char* const s) {
	LIB_HANDLE lib;
	lib = LOAD_LIBRARY(s); //�������� ���������� � ������;
	if (!lib)
	{
		printf("������ �������� ����������\n", s);
		return;
	}

	if (strcmp(s, "libA.dll") == 0 || strcmp(s, "libA.so") == 0)
	{
		
		void (*input)(int*, int);
		void (*output)(int*, int);
		int (*sum)(int*, int, int);
		input = (void (*)(int*, int))LOAD_FUNCTION(lib, "randArrayInput"); //��������� ��������� �� ������� �� ����������;
		output = (void (*)(int*, int))LOAD_FUNCTION(lib, "outputArray"); //��������� ��������� �� ������� �� ����������;
		sum = (int (*)(int*, int, int))LOAD_FUNCTION(lib, "sumArray"); //��������� ��������� �� ������� �� ����������;

		if (input == NULL || output == NULL || sum == NULL)
			{
				printf("������ �������� �������\n");
				CLOSE_LIBRARY(lib);
				return;
			}

		int M[SIZE], x, y;
		input(M, SIZE);
		output(M, SIZE);
		getchar();

		printf("������� �������� [X, Y] ��� ���������� ����� ���������\n");
		printf("X: ");
		while (scanf("%i", &x) == 0 || x <= 0 || x > SIZE)
		{
			printf("������� ���������� X: ");
			while (getchar() != '\n');
		}
		printf("Y: ");
		while (scanf("%i", &y) == 0 || y <= 0 || y > SIZE)
		{
			printf("������� ���������� Y: ");
			while (getchar() != '\n');
		}

		int sum_;
		if (x < y)
		{
			sum_ = sum(M, x - 1, y - 1);
			printf("����� [%i, %i] ��������� ����� %i", x, y, sum_);
		}
		else
		{
			sum_ = sum(M, y - 1, x - 1);
			printf("����� [%i, %i] ��������� ����� %i", y, x, sum_);
		}
		
	}
	else if (strcmp(s, "libM.dll") == 0 || strcmp(s, "libM.so") == 0)
	{
		int** (*create)(int, int);
		void (*input)(int**, int, int);
		void (*output)(int**, int, int);
		int (*sum)(int**, int, int, int);
		input = (void (*)(int**, int, int))LOAD_FUNCTION(lib, "randMatrixInput"); //��������� ��������� �� ������� �� ����������;
		output = (void (*)(int**, int, int))LOAD_FUNCTION(lib, "outputMatrix"); //��������� ��������� �� ������� �� ����������;
		sum = (int (*)(int**, int, int, int))LOAD_FUNCTION(lib, "sumMatrixCol"); //��������� ��������� �� ������� �� ����������;
		create = (int** (*)(int, int))LOAD_FUNCTION(lib, "createMatrix"); //��������� ��������� �� ������� �� ����������;
		if (input == NULL || output == NULL || sum == NULL || create == NULL)
		{
			printf("������ �������� �������\n");
			CLOSE_LIBRARY(lib);
			return;
		}
		int** S;
		if (!(S = create(CNT, SIZE)))
		{
			perror("������ ��������� ������");
			CLOSE_LIBRARY(lib);
			return;
		}
		int x, y;
		input(S, CNT, SIZE);
		output(S, CNT, SIZE);
		getchar();

		printf("������� �������� [X, Y] ��� ���������� ����� ��������� � ���� ��������\n");
		printf("X: ");
		while (scanf("%i", &x) == 0 || x <= 0 || x > SIZE)
		{
			printf("������� ���������� X: ");
			while (getchar() != '\n');
		}
		printf("Y: ");
		while (scanf("%i", &y) == 0 || y <= 0 || y > SIZE)
		{
			printf("������� ���������� Y: ");
			while (getchar() != '\n');
		}

		int sum_;
		if (x < y)
		{
			sum_ = sum(S, CNT, x - 1, y - 1);
			printf("����� [%i, %i] �������� ����� %i", x, y, sum_);
		}
		else
		{
			sum_ = sum(S, CNT, y - 1, x - 1);
			printf("����� [%i, %i] �������� ����� %i", y, x, sum_);
		}
	}
	else 
	{
		printf("������ ���������� �� ����������");
	}
	CLOSE_LIBRARY(lib); //�������� ����������;
}