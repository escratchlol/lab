#include <stdio.h>
#include <locale.h>
#include <math.h>

#define N 10
#define LEFT 0.2
#define RIGHT 2.2

float Zero_to_negative(float a);
float average(float A[], int n);
double x_a(int i);
double f(double x);
double summ_mas(double A[], int n, int flag);
int count_mas(double A[], int n, int flag);
int sum_index_max(float A[], int n);

int main()
{
    setlocale(LC_ALL, "Ru");

    puts("задание 1");
    float A[N];
    float temp;
    float R[N];

    for (int i = 0; i < N; i++)
    {
        printf("a[%d] = ", i + 1);
        scanf("%f", &temp);
        A[i] = temp;
    }

    for (int i = 0; i < N; i++)
    {
        R[i] = Zero_to_negative(A[i]);
    }

    for (int i = 0; i < N; i++)
    {
        printf("|  %d  |   %.4f |  %.4f  |\n", i, A[i], R[i]);
    }
    printf("\nСреднее арифметическое: %f", average(R, N));


    puts("\n\nзадание 2");

    double B[100];
    for (int i = 0; i < 100; i++)
    {
        B[i] = f(x_a(i));
    }

    printf("Число положительных элементов= %d\n Число отрицательных элементов = % d\n сумма положительных элементов= %.4f\n сумма отрицательных элементов= %.4f\n", count_mas(B, 100, 1), count_mas(B, 100, 0), summ_mas(B, 100, 1), summ_mas(B, 100, 0));
    printf("среднее всех чисел= %.4f\n", (summ_mas(B, 100, 1) + summ_mas(B, 100, 0)) / (count_mas(B, 100, 1) + count_mas(B, 100, 1)));

    puts("\n\nзадание 3");
    printf("индекс максимального элемента= %d\n", index_max(R, N));
    printf("сумма индексов, начиная с максимального элемента= %d\n", sum_index_max(R, N));

    return 0;

}

float Zero_to_negative(float a) {
    if (a < 0)
        return 0;
    else
        return a;
}

float average(float A[], int n) {
    float s = 0;
    for (int i = 0; i < n; i++)
        s += A[i];
    return s / n;
}

double x_a(int i) {
    double x = LEFT + (RIGHT - LEFT) * i / 99.0;
    return x;
}

double f(double x) {
    return 1.8 * x * x - sin(10 * x);
}

double summ_mas(double A[], int n, int flag) {
    double s = 0;
    for (int i = 0; i < n; i++)
        if (flag == 0 && A[i] < 0)
            s += A[i];
        else if (flag == 1 && A[i] > 0)
            s += A[i];
    return s;
}

int count_mas(double A[], int n, int flag) {
    double s = 0;
    for (int i = 0; i < n; i++)
        if (flag == 0 && A[i] < 0)
            s += 1;
        else if (flag == 1 && A[i] > 0)
            s += 1;
    return s;
}

int index_max(float A[], int n) {
    int imax = 0;
    for (int i = 1; i < n; i++)
        if (A[i] > A[imax])
            imax = i;
    return imax;
}

int sum_index_max(float A[], int n) {
    int imax = index_max(A, n);
    int sum = 0;
    for (int i = imax; i < n; i++)
        sum += i;
    return sum;
}
