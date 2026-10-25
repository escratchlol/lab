#include <stdio.h>
#include <locale.h>
#include <math.h>

#define ROW 9
#define COL 9
#define PI 3.14159265358979

int mult(int a, int b);
int sum(int a, int b);
int count_even(int n);
double vx(int k, double d1, double d2, double a);
double vy(int k, double d1, double d2, double a);
int in_quad(double x, double y, double d1, double d2, double a);
void draw_figure(char sym, double d1, double d2, double ang);

int main()
{
	setlocale(LC_ALL, "Ru");

	puts("задание 1 (таблица Пифагора):");
	for (int row = 1; row <= ROW; ++row)
	{
		for (int col = 1; col <= COL; col++)
		{
			printf("%5d", mult(col, row));
		}
		printf("\n");
	}

	puts("\nзадание 1.2 (левый нижний треугольник):");
	for (int row = 1; row <= ROW; ++row)
	{
		for (int col = 1; col <= row; col++)
		{
			printf("%5d", mult(col, row));
		}
		printf("\n");
	}

	puts("\nзадание 1.3 (вариант 15, таблица сложения):");
	for (int a = 1; a <= 9; a++)
	{
		for (int b = 1; b <= 9; b++)
		{
			printf("%d + %d = %2d   ", a, b, sum(a, b));
		}
		printf("\n");
	}


	puts("\nзадание 2 (количество чётных цифр):");
	while (1)
	{
		int num;
		char again;
		printf("Введите число: ");
		scanf("%d", &num);
		int cnt = count_even(num);
		printf("Чётных цифр: %d\n", cnt);
		printf("Продолжить? (Да - y, нет - n): ");
		scanf(" %c", &again);
		if (again == 'n')
		{
			break;
		}
	}


	puts("\nзадание 3 (четырёхугольник по диагоналям и углу):");
	while (1)
	{
		char sym;
		double d1, d2, ang;
		printf("Введите символ, из которого будет строиться фигура: ");
		scanf(" %c", &sym);
		printf("Введите d1: ");
		scanf("%lf", &d1);
		printf("Введите d2: ");
		scanf("%lf", &d2);
		printf("Введите угол между диагоналями (в градусах): ");
		scanf("%lf", &ang);

		draw_figure(sym, d1, d2, ang);

		int cont;
		printf("\nПродолжить? (Да - введите любое число, Нет - введите 0): ");
		scanf("%d", &cont);
		if (cont == 0)
		{
			break;
		}
	}

	return 0;
}


int mult(int a, int b)
{
	return a * b;
}

int sum(int a, int b)
{
	return a + b;
}

int count_even(int n)
{
	if (n < 0)
	{
		n = -n;
	}
	if (n == 0)
	{
		return 1;
	}
	int cnt = 0;
	while (n > 0)
	{
		if ((n % 10) % 2 == 0)
		{
			cnt++;
		}
		n /= 10;
	}
	return cnt;
}

void draw_figure(char sym, double d1, double d2, double ang)
{
	if (d1 <= 0 || d2 <= 0 || ang <= 0 || ang >= 180)
	{
		puts("ошибка: d1 и d2 должны быть больше 0, угол от 0 до 180");
		return;
	}

	double ymax = fmax(vy(2, d1, d2, ang), 0);
	double ymin = fmin(vy(4, d1, d2, ang), 0);
	double xmax = fmax(vx(3, d1, d2, ang), vx(2, d1, d2, ang));
	double xmin = fmin(vx(1, d1, d2, ang), vx(4, d1, d2, ang));

	printf("\n");
	for (int r = (int)ceil(ymax); r >= (int)floor(ymin); r--)
	{
		for (int cx = (int)floor(xmin * 2); cx <= (int)ceil(xmax * 2); cx++)
		{
			if (in_quad(cx * 0.5, r, d1, d2, ang))
			{
				printf("%c", sym);
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}

double vx(int k, double d1, double d2, double a)
{
	double rad = a * PI / 180;
	switch (k)
	{
	case 1:
		return -0.4 * d1;
	case 2:
		return 0.6 * d2 * cos(rad);
	case 3:
		return 0.6 * d1;
	default:
		return -0.4 * d2 * cos(rad);
	}
}

double vy(int k, double d1, double d2, double a)
{
	double rad = a * PI / 180;
	switch (k)
	{
	case 2:
		return 0.6 * d2 * sin(rad);
	case 4:
		return -0.4 * d2 * sin(rad);
	default:
		return 0;
	}
}

int in_quad(double x, double y, double d1, double d2, double a)
{
	int pos = 0, neg = 0;
	for (int k = 1; k <= 4; k++)
	{
		int next = (k == 4) ? 1 : k + 1;
		double x1 = vx(k, d1, d2, a), y1 = vy(k, d1, d2, a);
		double x2 = vx(next, d1, d2, a), y2 = vy(next, d1, d2, a);
		double cross = (x2 - x1) * (y - y1) - (y2 - y1) * (x - x1);
		if (cross > 1e-9)
		{
			pos = 1;
		}
		if (cross < -1e-9)
		{
			neg = 1;
		}
	}
	return !(pos && neg);
}
