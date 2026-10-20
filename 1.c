#include <stdio.h>
#include <locale.h>
#include <math.h>

void task1(int m, int n);
void task1A(int n, int m);
void task2(double step);

int main() {
    setlocale(LC_ALL, "Ru");

    printf("Задание 1\n\n");
    int m, n;
    printf("Введите m: ");
    scanf("%d", &m);
    printf("Введите n: ");
    scanf("%d", &n);
    task1(m, n);

    printf("\nЗадание 1A\n\n");
    int nA, mA;
    printf("Введите степень n: ");
    scanf("%d", &nA);
    printf("Введите целое число m: ");
    scanf("%d", &mA);
    task1A(nA, mA);

    printf("\nЗадание 2\n\n");
    double step;
    printf("y = 1.8*x^2 - sin(10*x)\n");
    printf("Введите шаг табуляции: ");
    scanf("%lf", &step);
    task2(step);

    return 0;
}

void task1(int m, int n) {
    int s = 0;
    int k = 0;
    for (int i = m; i <= n; i++) {
        s += i;
        k++;
    }
    printf("Результат: %d\n", s);
    printf("Выполнено итераций: %d\n", k);
}

void task1A(int n, int m) {
    for (int i = 0; i <= n; i++) {
        long long res = (long long)pow(2, i);
        printf("2^%2d = %4lld\n", i, res);
    }

    int k_pow = 0;
    while (pow(2, k_pow) < 1024) {
        k_pow++;
    }
    printf("Результат: %dK\n", k_pow);

    int i = 0;
    while (pow(2, i) <= m) {
        printf("%.1fK\n", pow(2, i));
        i++;
    }
}

void task2(double step) {
    double a = 0.2;
    double b = 2.2;
    double x, y;

    printf("|   x   |  f(x)  |\n");
    for (x = a; x <= b + 1e-9; x += step) {
        y = 1.8 * pow(x, 2) - sin(10 * x);
        printf("| %5.2f | %6.3f |\n", x, y);
    }
}
