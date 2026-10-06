#include <stdio.h>
#include <locale.h>
void prac1();
void prac2();
void prac3();
void dz4();
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
    dz4();
    return 0;
}
void prac1()
{
    char c = '!';
    int i = 2;
    float f = 3.14f;
    double d = 5e-12;

    printf("char:   %c\n", c);
    printf("int:    %d\n", i);
    printf("float:  %.2f\n", f);
    printf("double: %e\n", d);

    printf("\nввод значений\n");

    printf("введите символ (char): ");
    scanf(" %c", &c);

    printf("введите целое число (int): ");
    scanf("%d", &i);

    printf("введите число с плавающей точкой (float): ");
    scanf("%f", &f);

    printf("введите число double: ");
    scanf("%lf", &d);

    printf("\nвы ввели:\n");
    printf("char:   %c\n", c);
    printf("int:    %d\n", i);
    printf("float:  %f\n", f);
    printf("double: %e\n", d);

    printf("\nзадача 1a\n");
    double num;
    printf("введите вещественное число: ");
    scanf("%lf", &num);
    int num_int = (int)num;
    double num_frac = num - num_int;
    printf("целая часть: %d\n", num_int);
    printf("дробная часть: %g\n", num_frac);

    printf("\nзадача 1b\n");
    char c1;
    printf("введите символ: ");
    scanf(" %c", &c1);
    printf("код в 16-ричной системе: %x\n", c1);
    printf("код в 10-ричной системе: %d\n", c1);

    printf("\nзадача 1c\n");
    int i1;
    printf("введите целое число i: ");
    scanf("%d", &i1);
    double otv = 1.0 / i1;
    printf("1/%d:=%g\n", i1, otv);

}

void prac2() 
{
    int a = 11;
    int b = 3;

    int x;
    float y;
    double z;

    printf("неявное преобразование\n");
    printf("\n11/3:\n");
    x = a / b;
    y = a / b;
    z = a / b;

    printf("x (int):    %d\n", x);
    printf("y (float):  %f\n", y);
    printf("z (double): %lf\n", z);

    printf("\nпояснение: 11 / 3 = 3.666..., но так как a и b типа int, программа выполняет целочисленное деление, т.е. результат равен 3 потому что дробная часть (.666) теряется еще до записи в переменную.\n");

    printf("\nявное преобразование\n");
    printf("\n11/3:\n");
    y = (float)a / b;
    z = (double)a / b;

    printf("y (float, с приведением):  %f\n", y);
    printf("z (double, с приведением): %lf\n", z);

    printf("\nпояснение: я присвоила числам типы данных float и double и теперь программа считает их не целыми а дробными\n");
    printf("т.е. целое число 11 стало 11.0 и деление стало 11.0 / 3.0. в результате сохраняется дробная часть\n");
}
void prac3()
{
    int N;
    printf("введите трехзначное число: ");
    scanf("%d", &N);

    int first = N / 100;
    int second = (N / 10) % 10;
    int last = N % 10;

    int sum = first + second + last;
    int naoborot = last * 100 + second * 10 + first;

    printf("Последняя цифра: %d, первая цифра: %d, сумма цифр: %d, число наоборот: %d\n", last, first, sum, naoborot);
}

void dz4() 
{
    int A, B, uslovie;
    printf("введите номер кнопки, которую нажал игрок A: ");
    scanf("%d", &A);
    printf("введите номер кнопки, которую нажал игрок B: ");
    scanf("%d", &B);
    uslovie = (A % 2 == 0 && B % 2 == 1) || (A % 2 == 1 && B % 2 == 0);
    printf("игрок A нажал %s кнопку.\n", (A % 2 == 0) ? "ЧЁТНУЮ" : "НЕЧЁТНУЮ");
    printf("игрок B нажал %s кнопку.\n", (B % 2 == 0) ? "ЧЁТНУЮ" : "НЕЧЁТНУЮ");
    printf("победили ли в раунде? (1 - да, 0 - нет): %d\n", uslovie);
}