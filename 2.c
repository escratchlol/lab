#include <stdio.h>
#include <locale.h>
void prac1();
void prac2();
void prac3();
void dz2();
int main() {
	setlocale(LC_ALL, "Ru");
	printf("Практика 2\n");
	printf("\nЗадание 1\n");
	prac1();
	printf("\nЗадание 2\n");
	prac2();
	printf("\nЗадание 3\n");
	prac3();
	printf("\nДомашнее задание\n");
	dz2();
	return 0;
}
void prac1()
{
	printf("ЗАДАНИЕ 1\n");
	printf("123\n\n ");
	printf("ЗАДАНИЕ 2\n");
	printf("1\n2\n3\n\n ");
	printf("ЗАДАНИЕ 3\n");
	printf("1\n\t2\n\t\t3\n\n ");
	printf("ЗАДАНИЕ 4\n");
	printf("%1d\n%2d\n%3d\n%4d\n\n ", 1, 2, 3, 4);
	printf("ЗАДАНИЕ 5\n");
	printf("%10.3f\n\n ", 12.234657);
	printf("ЗАДАНИЕ 6\n");
	printf("%10.5f\n\n ", 12.234657);
	printf("ЗАДАНИЕ 7\n");
	printf("Остаток от деления %d на %d равен %d\n\n ", 5, 2, 5 % 2);
	printf("ЗАДАНИЕ 8\n");
	printf("деление %.0f на %.0f равно %.1f\n\n ", 7.0, 5.0, 7.0 / 5.0);
	printf("ЗАДАНИЕ 9\n");
	printf("умножение %.0f на %.0f равно %.0f\n\n ", 2000.0, 4.0, 2000.0 * 4.0);
	printf("ЗАДАНИЕ 10\n");
	printf("%d разделить на %d равно %d\n ", 5, 2000000, 5 / 2000000);
	printf("%f разделить на %f равно %f\n ", 5., 2000000., 5. / 2000000);
	printf("%g разделить на %g равно %g\n ", 5., 2000000., 5. / 2000000);
	printf("%e разделить на %e равно %e\n ", 5., 2000000., 5. / 2000000);
}
void prac2()
{
	int N, K;
	N = 8;
	K = 50;
	printf("Сейчас %d часов %d минут 00 секунд\n", N, K);
	printf("Идет %d минута суток\n", N * 60 + K);
	printf("До полуночи осталось %d часов и %d минут\n", 24 - N - 1, 60 - K);
	printf("С 8.00 прошло %d секунд\n", K * 60);
	printf("Текущий час  = %.2f суток  и текущая минута =  %.2f часа\n", N / 24., K / 60.);
}
void prac3()
{
	int n = 4;
	int l = 13333;
	int k = 4;
	int m = 6;
	printf("Дано:\n%11d\n%11d\nОтвет:\n%+05d.%0*d\n", n, l, n / l, m, (n % l) * 1000000 / l);
}
void dz2()
{
	float X = 7.0f;
	float S = 48.0f;
	float L = 90.0f;

	float length = S * 100.0f / L;
	float cost = length * X;

	printf("Задача:\n");
	printf("Стоимость погонного метра красного шёлка стоит %.0f золотых\n", X);
	printf("Сколько заплатил Грей за ткань для своей бригантины\n");
	printf("если общая площадь парусов на ней %.0f м^2,\n", S);
	printf("а ширина ткани в рулоне %.0f см\n\n", L);

	printf("Решение:\n");
	printf("1) Ширина ткани в метрах: %.0f см / 100 = %.2f м\n", L, L / 100.0f);
	printf("2) Длина ткани: %.0f м^2 / %.2f м = %.2f м\n", S, L / 100.0f, length);
	printf("3) Стоимость: %.2f м * %.0f золотых = %.2f золотых\n\n", length, X, cost);

	printf("Ответ: Грей заплатил %.2f золотых за ткань для парусов бригантины\n", cost);
}