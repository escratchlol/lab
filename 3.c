#include <stdio.h>
#include <locale.h>
#define D 2.54
#define P 2.32166

#define M 1.852
#define S 1.609
#define R 1.475
#define ST 7.468
#define G 7.4126
void prac1();
void prac2();
void prac3();
void dz3();
int main() {
    setlocale(LC_ALL, "Ru");
    printf("Практика 3\n");
    printf("\nЗадание 1\n");
    prac1();
    printf("\nЗадание 2\n");
    prac2();
    printf("\nЗадание 3\n");
    prac3();
    printf("\nДомашнее задание\n");
    dz3();
    return 0;
}
void prac1()
{
    int num;
    puts("введите число");
    scanf("%d", &num);
    printf("введено число %d\n", num);
    int mun;
    puts("введите еще число");
    scanf("%d", &mun);
    printf("введено еще число %d\n", mun);
    printf("сумма %d\n", num + mun);
    printf("разность %d\n", num - mun);
    printf("произведение %d\n", num * mun);
    printf("частное %d\n", mun / num);
    printf("остаток от деления %d\n", mun % num);
}
void prac2()
{
    int dym;
    float result;
    float result1;
    printf("перевод дюймов\n");
    printf("введите значение в дюймах: ");
    scanf("%d", &dym);

    result = D * dym;
    printf("%d английских дюймов – это %.2f см\n", dym, result);

    result1 = P * dym;
    printf("%d испанских пульгад – это %.2f см\n", dym, result1);

    printf("\nАльтернативное задание 2А: мили в км\n");
    printf("введите количество миль: ");
    scanf("%d", &dym);

    printf("\n%d миль — это:\n", dym);
    printf("морская миля:        %.3f км\n", M * dym);
    printf("сухопутная миля:     %.3f км\n", S * dym);
    printf("римская миля:        %.3f км\n", R * dym);
    printf("старорусская миля:   %.3f км\n", ST * dym);
    printf("географическая миля: %.4f км\n", G * dym);
}
void prac3()
{
    int a, b;
    printf("Введите число a: ");
    scanf("%d", &a);
    printf("Введите число b: ");
    scanf("%d", &b);

    printf("\n");
    printf("| %-5s | %-5s | %-5s |\n", "a*b", "a+b", "a-b");
    printf("| %-2d*%-2d | %-2d+%-2d | %-2d-%-2d |\n", a, b, a, b, a, b);
    printf("| %-5d | %-5d | %-5d |\n", a * b, a + b, a - b);
}
void dz3()
{
    const float kolichestvo = 63241.0f;

    float light_years;
    float au;

    printf("введите число световых лет: ");
    scanf("%f", &light_years);

    au = light_years * kolichestvo;

    printf("\n%.2f световых лет = %.2f a.e.\n", light_years, au);
}