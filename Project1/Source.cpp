#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale>
int main(void) {
    srand(time(NULL));
    setlocale(LC_ALL, "russian");
    int i, min = 0, max, n;
    int* a;
    printf("¬ведите размер массива: ");
    scanf("%d", &n);
    a = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        a[i] = rand() % 100;
        printf("%d\n", a[i]);
    }
    max = a[0];
    min = a[0];
    for (i = 0; i < n; i++) {
        if (max < a[i]) {
            max = a[i];
        }
        if (min > a[i]) {
            min = a[i];
        }
    }



    printf("\nразница = %d\n", max - min);
    system("pause");
}
