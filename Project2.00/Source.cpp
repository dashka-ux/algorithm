#define _CRT_SECURE_NO_WARNINGS
#include <random>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
void shell(int* items, int count) {
	int i, j, gap, k;
	int x, a[5];
	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

	for (k = 0; k < 5; k++) {
		gap = a[k];
		for (i = gap; i < count; ++i) {
			x = items[i];
			for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
				items[j + gap] = items[j];
			items[j + gap] = x;

		}
	}
}

void qs(int* items, int left, int right) {
	int i, j;
	int x, y;
	i = left; j = right;
	x = items[(left + right) / 2 - 20];
	do {
		while ((items[i] < x) && (i < right))i++;
		while ((x < items[j]) && (j > left))j--;
		if (i <= j) {
			y = items[i];
			items[i] = items[j];
			items[j] = y;
			i++; j--;
		}

	} while (i <= j);
	if (left < j) qs(items, left, j);
	if (i < right) qs(items, i, right);
}
int cmpfunc(const int* i, const int* j) {
	return *i - *j;

}
int main() {
	FILE* sort;
	sort = fopen("C:\\sortt.txt", "a");
	int n;
	srand(time(NULL));
	printf("Enter lenght:");
	scanf("%d", &n);
	fprintf(sort, "NUMBER OF ELEMENTS = %d\n", n);
	int* arr_random = new int[n];
	int* arr_vozrast = new int[n];
	int* arr_ubiva = new int[n];
	int* arr_pila = new int[n];
	int* arr_random_3 = new int[n];
	int* arr_random_2 = new int[n];
	int* arr_vozrast_2 = new int[n];
	int* arr_vozrast_3 = new int[n];
	int* arr_ubiva_3 = new int[n];
	int* arr_ubiva_2 = new int[n];
	int* arr_pila_2 = new int[n];
	int* arr_pila_3 = new int[n];
	for (int i = 0; i < n; i++) {
		arr_random[i] = rand() % 100;
		arr_random_2[i] = arr_random[i];
		arr_random_3[i] = arr_random[i];
	}
	for (int i = 0; i < n; i++) {
		arr_vozrast[i] = i;
		arr_vozrast_2[i] = arr_vozrast[i];
		arr_vozrast_3[i] = arr_vozrast[i];
	}
	for (int i = 0; i < n; i++) {
		arr_ubiva[i] = n - i;
		arr_ubiva_2[i] = arr_ubiva[i];
		arr_ubiva_3[i] = arr_ubiva[i];
	}
	for (int i = 0; i < n; i++) {
		if (i <= n / 2) {
			arr_pila[i] = i;
			arr_pila_2[i] = arr_pila[i];
			arr_pila_3[i] = arr_pila[i];
		}
		if (i > n / 2) {
			arr_pila[i] = n - i;
			arr_pila_2[i] = arr_pila[i];
			arr_pila_3[i] = arr_pila[i];
		}
	}


	double start = clock();
	shell(arr_random, n);
	double end = clock();
	fprintf(sort, "Time shell random = %lf\n", (end - start) / CLOCKS_PER_SEC);

	int left = 0;
	double start_new = clock();
	qs(arr_random_2, left, n - 1);
	double end_new = clock();
	fprintf(sort, "Time qsort random = %lf\n", (end_new - start_new) / CLOCKS_PER_SEC);
	start = clock();
	qsort(arr_random_3, n, sizeof(int), (int(*)(const void*, const void*))cmpfunc);
	end = clock();
	fprintf(sort, "Standart qsort random = %lf\n", (end - start) / CLOCKS_PER_SEC);
	start = clock();
	shell(arr_vozrast, n);
	end = clock();
	fprintf(sort, "Time shell vozrast = %lf\n", (end - start) / CLOCKS_PER_SEC);

	start = clock();
	qs(arr_vozrast_2, left, n - 1);
	end = clock();
	fprintf(sort, "Time qsort vozrast = %lf\n", (end - start) / CLOCKS_PER_SEC);
	start = clock();
	qsort(arr_vozrast_3, n, sizeof(int), (int(*)(const void*, const void*))cmpfunc);
	fprintf(sort, "Standart qsort vozrast = %lf\n", (end - start) / CLOCKS_PER_SEC);
	end = clock();
	start = clock();
	shell(arr_pila, n);
	end = clock();
	fprintf(sort, "Time shell pila = %lf\n", (end - start) / CLOCKS_PER_SEC);

	start = clock();
	qs(arr_pila_2, left, n - 1);
	end = clock();
	fprintf(sort, "Time qsort pila = %lf\n", (end - start) / CLOCKS_PER_SEC);
	start = clock();
	qsort(arr_pila_3, n, sizeof(int), (int(*)(const void*, const void*))cmpfunc);
	end = clock();
	fprintf(sort, "Standart qsort pila = %lf\n", (end - start) / CLOCKS_PER_SEC);

	start = clock();
	shell(arr_ubiva, n);
	end = clock();
	fprintf(sort, "Time shell ubiva = %lf\n", (end - start) / CLOCKS_PER_SEC);

	start = clock();
	qs(arr_ubiva_2, left, n - 1);
	end = clock();
	fprintf(sort, "Time qsort ubiva = %lf\n", (end - start) / CLOCKS_PER_SEC);
	start = clock();
	qsort(arr_ubiva_3, n, sizeof(int), (int(*)(const void*, const
		void*))cmpfunc);
	end = clock();
	fprintf(sort, "Standart qsort ubiva = %lf\n", (end - start) / CLOCKS_PER_SEC);


	return 0;

}