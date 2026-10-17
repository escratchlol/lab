#include <stdio.h>
#include <locale.h>
#include <math.h>  

int prac1(int years);
double prac2(double x);
int prac3(int A, int B);
int dz(float x, float y);


int main() {
    setlocale(LC_ALL, "Ru");
    printf("Задание 1\n\n");
    int years;
    printf("Впишите год: ");
    scanf("%d", &years);
    int year = prac1(years);
    if (year == 1) {
        printf("Год %d високосный\n", years);
    }
    else {
        printf("Год %d не високосный\n", years);
    }
    printf("\nЗадание 2\n\n");

    double x;
    printf("Введите x: ");
    scanf("%lf", &x);
    double F = prac2(x);
    printf("F(%.6g) = %.6f  (%s)\n", x, F,
        (x > 3.6) ? "x > 3.6" : "x <= 3.6");
    printf("\nЗадание 3\n\n");

    int A, B;
    printf("Введите A: ");
    scanf("%d", &A);
    printf("Введите B: ");
    scanf("%d", &B);

    int a = prac3(A, B);
    if (a == 1) {
        printf("Ошибка: деление на ноль\n");
    }
    else {
        printf("%s\n", (A % B == 0) ? "Да" : "Нет");
    }

    printf("\nдз\n\n");
    float x1, y1;
    printf("Введите x: ");
    scanf("%f", &x1);
    printf("Введите y: ");
    scanf("%f", &y1);
    int result = dz(x1, y1);
    if (result == 1) {
        printf("Точка (%.2f, %.2f) принадлежит области\n", x1, y1);
    }
    else {
        printf("Точка (%.2f, %.2f) не принадлежит области\n", x1, y1);
    }
    return 0;

}


int prac1(int years) {
    int a = 0;
    if (years % 4 == 0 && years % 100 != 0 || years % 400 == 0) {
        a = 1;
    }
    else {
        a = 0;
    }
    return a;
}

double prac2(double x) {
    // если x = 4, то F(4) = 45 * 4^2 + 5 = 725
    // если x = 2 , то F(2) = (5* 2)/(10 * 2^2 + 1) = 0,243902
    double F;
    if (x > 3.6) {
        F = 45 * pow(x, 2) + 5;
    }
    else {
        F = (5.0 * x) / (10.0 * pow(x, 2) + 1.0);
    }
    return F;
}


int prac3(int A, int B) {
    int a = 0;
    if (B == 0) {
        a = 1;
    }
    else {
        a = 0;
    }
    return a;
}

int dz(float x, float y) {
    if (x > 6 || x < 0 || y > 6 || y < 0) {
        return -1;
    }
    if (y > -1.0 * x + 6.0) {
        return -1;
    }
    if (y < -2.0 * x + 4.0) {
        return -1;
    }
    return 1;
}