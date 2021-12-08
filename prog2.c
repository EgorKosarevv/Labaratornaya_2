#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void clear()
{
	system("@cls||clear");
}
int bubble_sort(int* a, int N)
{
	int i, j, tmp;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}
int insert_sort(int* mas, int N1)
{
	int k, i, tmp;
	for (i = 1; i < N1; i++)
	{
		tmp = mas[i];
		k = i - 1;
		while (k >= 0 && mas[k] > tmp)
		{
			mas[k + 1] = mas[k];
			k = k - 1;
		}
		mas[k + 1] = tmp;
	}
}
int quick_sort(int* a, int left, int right)
{
	int i, j;
	int tmp, pivot;
	i = left;
	j = right;
	pivot = a[(left + (right - left) / 2)];
	do {
		while (a[i] < pivot) {
			i++;
		}
		while (a[j] > pivot) {
			j--;
		}
		if (i <= j) {
			if (a[i] > a[j]) {
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
			i++;
			if (j > 0) {
				j--;
			}
		}
	} while (i <= j);

	if (i < right) {
		quick_sort(a, i, right);
	}
	if (j > left) {
		quick_sort(a, left, j);
	}
}
int norma1(int* mas, int N)
{
	int i;
	int norma1 = 0;
	for (i = 0; i <N; i++)
	{
		norma1 += abs(mas[i]);
	}
	printf("Первая норма вектора равна %d\n\n", norma1);
}
int norma2(int* mas, int N1)
{
	int i;
	int sum = 0;
	double norma2 = 0;
	for (i = 0; i < N1; i++)
	{
		sum += pow(abs(mas[i]),2);
		norma2 = sqrt(sum);
	}
	printf("Вторая норма вектора равна %lf\n\n", norma2);
}
int Gelderovaya_norma(int* mas, int N1, int p)
{
	int i;
	double sum = 0;
	double normaG = 0;
	for (i = 0; i < N1; i++)
	{
		sum += pow(abs(mas[i]), p);
		normaG = pow(sum,pow (p,-1));
	}
	printf("Гельдеровая норма вектора равна %lf\n\n", normaG);
}
int beskonechnaya_norma(int* mas, int n)
{
	int a;
	int i;
	int modul;
	int max = 0;
	for (i = 0; i < n; i++)
	{
		modul = abs(mas[i]);
		if (modul > max)
		{
			max = modul;
		}
	}
	printf("Бесконечная норма вектора равна %d\n\n", max);
}
int normirovka(int* mas, int N1)
{
	int i;
	int sum = 0;
	double koren;
	for (i = 0; i < N1; i++)
	{
		sum += pow(abs(mas[i]), 2);
		koren = sqrt(sum);
	}
	printf("Нормировка вектора: \n\n");
	for (i = 0; i < N1; i++)
	{
		printf("mas[%d] = %lf\n",i, mas[i] / koren);
	}
	printf("\n\n\n");
}
int main()
{
	int* mas;
	int i;
	int min, max, n;
	double start, stop, t;
	int choice, sort;
	srand(time(NULL));
	setlocale(0, "rus");
	FILE* file = 0;
	fopen_s(&file, "..\\textFile.txt", "r");
	fscanf_s(file, "n = %d\n", &n);
	mas = malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
	{
		mas[i] = 0;
	}
	for (i = 0; i < n; i++)
	{
		fscanf_s(file, "%d\n", &(mas[i]));
	}
	fclose(file);
		do
		{
		    printf("Выберите нужное действие:\n1) Печать\n2) Сортировка\n3) Сброс\n4) Выход\n5) Вычислить первую норму вектора\n6) Вычислить вторую норму вектора\n7) Вычислить Гельдеровую норму вектора\n8) Вычислить бесконечную норму вектора\n9) Нормировка вектора\n");
			printf("Введите число: ");
			do
			{
				scanf_s("%d", &choice);
				if (choice > 9 || choice <= 0)
				{
					printf("Ошибка! Введите корректные данные");
					return 0;
				}
			} while (choice > 9 || choice <= 0);
			if (choice == 1)
			{
				clear();
				printf("Исходный массив:\n");
				for (i = 0; i < n; i++)
				{
					printf("mas[%d] = %d\n", i, mas[i]);
				}
				printf("\n\n\n");
			}
			if (choice == 2)
			{
				clear();
				printf("Выберите нужную сортировку:\n1) Сортировка пузырьком\n2) Сортировка вставкой\n3) Быстрая сортировка\n");
				printf("Введите число: ");
				do
				{
					scanf_s("%d", &sort);
					if (sort > 3 || sort <= 0)
					{
						printf("Ошибка! Введите корректные данные");
						return 0;
					}
				} while (sort > 3 || sort <= 0);
				if (sort == 1)
				{
					clear();
					printf("Сортировка массива пузырьком:\n");
					start = clock();
					bubble_sort(mas, n - 1);
					stop = clock();
					t = ((double)(stop - start)) / CLK_TCK;
					printf(Время выполнения сортировки равно %lf\n\n\n\n", t);
				}
				else if (sort == 2)
				{
					clear();
					printf("Сортировка массива вставкой:\n");
					start = clock();
					insert_sort(mas, n);
					stop = clock();
					t = ((double)(stop - start)) / CLK_TCK;
					printf("Время выполнения сортировки равно %lf\n\n\n\n", t);
				}
				else if (sort == 3)
				{
					clear();
					printf("Быстрая сортировка массива:\n");
					start = clock();
					quick_sort(mas, 0, n - 1);
					stop = clock();
					t = ((double)(stop - start)) / CLK_TCK;
					printf("Время выполнения сортировки равно %lf\n\n\n\n", t);
				}
			}
			if (choice == 3)
			{
				clear();
				printf("Сортировка массива сброшена\n\n\n\n");
				return main();
			}
			if (choice == 4)
			{
				clear();
				printf("Выход из программы осуществлен\n\n");
				return 0;
			}
			if (choice == 5)
			{
				clear();
				norma1(mas, n);
			}
			if (choice == 6)
			{
				clear();
				norma2(mas, n);
			}
			if (choice == 7)
			{
				clear();
				printf("Введите степень: ");
				do
				{
					scanf_s("%d", &p);
					if (p <= 0)
					{
						printf("Ошибка! Введите корректные значения ");
						return 0;
					}
				} while (p <= 0);
				Gelderovaya_norma(mas, n, p);
			}
			if (choice == 8)
			{
				clear();
				beskonechnaya_norma(mas, n);
			}
			if (choice == 9)
			{
				clear();
				normirovka(mas, n);
			}		       
		} while (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice ==6 || choice == 7 || choice ==8 || choice == 9);
		free(mas);
		return 0;
}
