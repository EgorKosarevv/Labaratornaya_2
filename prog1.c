#include <stdio.h>
#include <stdlib.h>
void clear()
{
	system("@cls||clear");
}
int main()
{
	int* mas = 0;
	int i, j;
	int min, max, n;
	int choice;
	srand(time(NULL));
	setlocale(0, "rus");
	FILE* file = 0;
	fopen_s(&file, "..\\textFile.txt", "w");
	printf(" �������� ������ �������� �������:\n 1) ��������� ������� �� ��������� �����\n 2) ���� ������� � ����������\n 3) ����������� ������� �� �����\n");
	printf(" ������� �����: ");
	scanf_s("%d", &choice);
	if (choice == 1)
	{
		clear();
		printf(" �� ������� ��������� ������� �� ��������� �����\n");
		printf(" ������� ������ �������: ");
		scanf_s("%d", &n);
		if (n <= 0)
		{
			printf(" ������! ������� ���������� ������");
			return 0;
		}
		printf(" ������� ����������� �������� �������: ");
		scanf_s("%d", &min);
		printf(" ������� ������������ �������� �������: ");
		scanf_s("%d", &max);
		if (min >= max)
		{
			printf(" ������! ������� ���������� ��������");
			return 0;
		}
		mas = malloc(n * sizeof(int));
		for (i = 0; i < n; i++)
		{
			mas[i] = (min + (max - min) * rand() / RAND_MAX);
		}
		printf(" ������ ������������");
		fprintf(file, "n = %d\n", n);
		for (i = 0; i < n; i++)
		{
			fprintf(file, "%d\n", mas[i]);
		}
		fclose(file);
	}
	if (choice == 2)
	{
		clear();
		printf(" �� ������� ���� ������� � ����������\n");
		printf(" ������� ������ �������: ");
		scanf_s("%d", &n);
		if (n <= 0)
		{
			printf(" ������! ������� ���������� ������");
			return 0;
		}
		printf(" ��������� ������ ������ �������\n");
		mas = malloc(n * sizeof(int));
		fprintf(file, "n = %d\n", n);
		for (i = 0; i < n; i++)
		{
			printf(" mas[%d] = ", i);
			scanf_s("%d", &mas[i]);
		}

		for (i = 0; i < n; i++)
		{
			fprintf(file, "%d\n", mas[i]);
		}
		fclose(file);
		printf(" ������ ������������\n");	
	}
	if (choice == 3)
	{
		clear();
		printf(" �� ������� ����������� ������� �� �����\n");
		printf(" ������ ������� ���������� �� �����\n");
		FILE* file1 = 0;
		fopen_s(&file1, "mas.txt", "r");
		fscanf_s(file1, "n = %d\n", &n);
		mas = malloc(n * sizeof(int));
		for (i = 0; i < n; i++)
		{
			mas[i] = 0;
		}
		for (i = 0; i < n; i++)
		{
			fscanf_s(file1, "%d\n", &(mas[i]));
		}
		fclose(file1);
		fprintf(file, "n = %d\n", n);
		for (i = 0; i < n; i++)
		{
			fprintf(file, "%d\n", mas[i]);
		}
		fclose(file);
	}
	if (choice > 4 || choice <= 0)
	{
		clear();
		printf(" ������! ������� ���������� ������\n\n");
		return 0;
	}
	return 0;
}