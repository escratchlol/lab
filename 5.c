#include <stdio.h>
#include <locale.h>
#include <math.h>
#define e    2.71828182845904523536
#define M_PI 3.14159265358979323846

void prac1();
void prac2();
void prac3();
void dz5();
int main() {
    setlocale(LC_ALL, "Ru");
    printf("Практика 4\n");
    printf("\nЗадание 1\n");
    prac1();
    printf("\nЗадание 2\n");
    prac2();
    printf("\nЗадание 3\n");
    prac3();
    printf("\nДомашнее задание\n");
    dz5();
    return 0;
}

void prac1() {
    double gr;

    printf("введите угол в градусах: ");
    scanf("%lf", &gr);

    double rad = gr * M_PI / 180.0;

    double sin_val = sin(rad);

    printf("%g град = %.6f\n", gr, sin_val);
}

void prac2()
{
    double x;
    const double k = -4.0;

    printf("введите значение x: ");
    scanf("%lf", &x);

    double a = log(fabs(-k * x));

    double b = exp(2.0 * x) + a * x;

    double y = x * pow(a, 3.0) + pow(b, 2.0);

    printf("\nрезультат:\n");
    printf("значение x: %.1f\n", x);
    printf("вычисленное значение функции y: %.1f\n", y);
}

void prac3()
{
    int A, B, C;
    int uslovieA;
    int uslovieB;

    printf("Введите числа A, B и C: ");
    scanf("%d %d %d", &A, &B, &C);

    uslovieA = (A % 2 == 0 && B % 2 != 0) || (A % 2 != 0 && B % 2 == 0);

    uslovieB = (A % 3 == 0) && (B % 3 == 0) && (C % 3 == 0);

    printf("условие выполнено (1 - да, 0 - нет): %d\n", uslovieA);
    printf("условие выполнено (1 - да, 0 - нет): %d\n", uslovieB);
}
void dz5()
{
    double x = 2.444;
    double y = 0.869 * pow(10, -2);
    double z = -0.13 * pow(10, 3);

    double num1 = pow(x, y + 1) + pow(e, y - 1);
    double mun1 = 1 + x * fabs(y - tan(z));

    double drob1 = num1 / mun1;

    double num2 = drob1 * (1 + fabs(y - x));
    double drob2 = (pow(fabs(y - x), 2)) / 2;
    double drob3 = (pow(fabs(y - x), 3)) / 3;

    double h = num2 + drob2 - drob3;
    printf("h = %.5f\n", h);
}