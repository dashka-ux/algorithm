#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale>
struct student {
    char surname[20], name[20], faculty[50];
    int Number;
}stud[4];
int main(void) {
    setlocale(LC_ALL, "russian");
    int i, n;
    for (i = 0; i < 4; i++) {
        printf("введите фамилию,имя,факультет,номер зачетки\n");
        scanf("%20s%20s%20s%20d", stud[i].surname, stud[i].name, stud[i].faculty, &stud[i].Number);
    }
    printf("введите номер зачетки: ");
    scanf("%d", &n);
    for (i = 0; i < 4; i++) {
        if (stud[i].Number == n) {
            printf("%s %s %s %d\n", &stud[i].surname, &stud[i].name, &stud[i].faculty, stud[i].Number);
        }
    }
    system("pause");
}