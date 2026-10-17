#include <stdio.h>
#include <locale.h>
#include <math.h>
#define e    2.71828182845904523536
#define M_PI 3.14159265358979323846

double prac1(double gr);
double prac2(double x);
int    prac3a(int A, int B);
int    prac3b(int A, int B, int C);
double dz5(double x, double y, double z);

int main() {
    setlocale(LC_ALL, "Ru");
    printf("Практика 4\n");

    printf("\nЗадание 1\n");
    double gr;
    printf("введите угол в градусах: ");
    scanf("%lf", &gr);
    double sin_val = prac1(gr);
    printf("%g град = %.6f\n", gr, sin_val);

    printf("\nЗадание 2\n");
    double x;
    printf("введите значение x: ");
    scanf("%lf", &x);
    double y = prac2(x);
    printf("\nрезультат:\n");
    printf("значение x: %.1f\n", x);
    printf("вычисленное значение функции y: %.1f\n", y);

    printf("\nЗадание 3\n");
    int A, B, C;
    printf("Введите числа A, B и C: ");
    scanf("%d %d %d", &A, &B, &C);

    int uA = prac3a(A, B);
    int uB = prac3b(A, B, C);
    printf("условие выполнено (1 - да, 0 - нет): %d\n", uA);
    printf("условие выполнено (1 - да, 0 - нет): %d\n", uB);

    printf("\nДомашнее задание\n");
    double dx = 2.444;
    double dy = 0.869 * pow(10, -2);
    double dz = -0.13 * pow(10, 3);
    double h = dz5(dx, dy, dz);
    printf("h = %.5f\n", h);

    return 0;
}

double prac1(double gr) {
    double rad = gr * M_PI / 180.0;
    return sin(rad);
}

double prac2(double x) {
    const double k = -4.0;
    double a = log(fabs(-k * x));
    double b = exp(2.0 * x) + a * x;
    return x * pow(a, 3.0) + pow(b, 2.0);
}

int prac3a(int A, int B) {
    return (A % 2 == 0 && B % 2 != 0) || (A % 2 != 0 && B % 2 == 0);
}

int prac3b(int A, int B, int C) {
    return (A % 3 == 0) && (B % 3 == 0) && (C % 3 == 0);
}

double dz5(double x, double y, double z) {
    double num1 = pow(x, y + 1) + pow(e, y - 1);
    double mun1 = 1 + x * fabs(y - tan(z));
    double drob1 = num1 / mun1;

    double num2 = drob1 * (1 + fabs(y - x));
    double drob2 = pow(fabs(y - x), 2) / 2;
    double drob3 = pow(fabs(y - x), 3) / 3;

    return num2 + drob2 - drob3;
}
