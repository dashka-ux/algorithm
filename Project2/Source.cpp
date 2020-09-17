#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>
int main(void) {
    srand(time(NULL));
    int i, j, sum = 0;
    int massive[5][5];
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            massive[i][j] = rand() % 100;
            printf("%4d", massive[i][j]);
        }
        printf("\n");
    }
    i = 0;
    for (j = 0; j < 5; ++j) {
        for (i = 0; i < 5; ++i)
        {
            sum += massive[i][j];




        }

        printf("\n%d\n", sum);
        sum = 0;
    }
    system("pause");
}
