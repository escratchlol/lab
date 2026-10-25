#include <stdio.h>
#include <locale.h>
#include <math.h>


char symbol(int i, int n, char c1, char c2);
int sum(int m, int n);
double get_power_of_two(int n, int use_k);
void tabulate(double step);
double f(double x);
double sumN(int n);

int main()

{
	setlocale(LC_ALL, "Russian");
	puts("Задание 0");
	int count;
	char c1, c2;
	printf("Введите количество символов: ");
	scanf("%d", &count);
	printf("Введите символ для первой половины:");
	scanf(" %c", &c1);
	printf("Введите символ для второй половины:");
	scanf(" %c", &c2);
	printf("+");
	for (int i = 0; i < count; i++) {
		printf("%c!", symbol(i, count, c1, c2));
	}
	puts("\nЗадание 1");
	int m, n;
	printf("Введите m:");
	scanf("%d", &m);
	printf("Введите n:");
	scanf("%d", &n);
	int s = sum(m, n);
	int k = n - m + 1;
	printf("выполнено %d раз\nсумма = %d\n", k, s);


	puts("\nЗадание 1A (Пункты 1-4)");
	int n_pow;
	printf("Введите степень n: ");
	scanf("%d", &n_pow);

	double last_val = 0;

	for (int i = 0; i <= n_pow; i++) {
		double val = get_power_of_two(i, 0);
		printf("2^%d = %10.0f\n", i, val);

		if (i == n_pow) {
			last_val = val;
		}
	}
	printf("Результат: %.0fK\n", last_val / 1024.0);


	puts("\nЗадание 1A (Пункт 5)");
	int m_val;
	printf("Введите заданное целое число m: ");
	scanf("%d", &m_val);

	for (int i = 0; i <= m_val; i++) {
		double val_k = get_power_of_two(i, 1);
		printf("2^%d = %10.1fK\n", i, val_k);
	}


	puts("задание 2");
	double step;
	printf("Введите шаг табуляции: ");
	scanf("%lf", &step);
	tabulate(step);

	puts("задание 3");
	int n1;
	printf("Введите n: ");
	scanf("%d", &n1);
	double sum_result = sumN(n1);
	printf("Сумма = %.6lf\n", sum_result);


	return 0;
}

char symbol(int i, int n, char c1, char c2) {
	if (i <= n / 2) {
		return c1;
	}
	else {
		return c2;
	}
}

int sum(int m, int n) {
	int s = 0;
	for (int i = m; i <= n; i++) {
		s += i;
	}
	return s;
}

double get_power_of_two(int n, int use_k) {
	double result = 1.0;
	for (int i = 0; i < n; i++) {
		result *= 2.0;
	}

	if (use_k) {
		return result / 1024.0;
	}
	return result;
}

double f(double x) {
	return 1.8 * pow(x, 2) - sin(10 * x);
}

void tabulate(double step) {
	puts("|--------------------------|");
	puts("|      x           F(x)    |");
	puts("|--------------------------|");
	for (double x = 0.2; x <= 2.2 + 0.0001; x += step) {
		printf("|%10.4lf | %12.6lf |\n", x, f(x));
	}
	puts("|--------------------------|");
}

double sumN(int n) {
	double sum = 0.0;
	double s_sin = 0.0;
	for (int i = 1; i <= n; i++) {
		s_sin += sin(i);
		sum += 1.0 / s_sin;
	}
	return sum;
}
