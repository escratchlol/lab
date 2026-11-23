#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>

typedef double(*TFun)(double);
typedef struct {
	double x;
	double y;
} Point;

TFun chooseFunction(int choice);
double funS(double x);
double funY(double x);
double funV(double x);
void plot(double x0, double x1, TFun f);
double goldenSectionMax(TFun f, double a, double b, double eps);
void readFromFile(TFun f);
void writeToFile(double x0, double x1, double step, TFun f);
void describeFunction(TFun f, double a, double b);
Point* makePoints(TFun f, double a, double b, double step, int* outN);
void printPoint(const Point* p);
void printPoints(const Point* arr, int n);
void twoDimensionalArray(TFun f, double a, double b, double step);
void rangeXY(TFun f, double a, double b, double step);
int tabulate(TFun f, double x1, double x2, double step, int type);
double calculate(TFun ptrf, double* x, int n);

int main()
{
	setlocale(LC_ALL, "Russian");
	puts("Задание 1");
	int choice;
	double x;
	printf("Выберите функцию:\n");
	printf("1. y = log(|sqrt(x^3)|)\n");
	printf("2. v = { sqrt(tg(x^2 - 1)), если x > 1\n");
	printf("        -2x, если 0 <= x <= 1\n");
	printf("        exp(cos(x)), если x < 0 }\n");
	printf("3. s = (x - 1)/(x + 1) + (1/3)((x - 1)/(x + 1))^3 + (1/5)((x - 1)/(x + 1))^5 + (1/7)((x - 1)/(x + 1))^7\n");
	if (scanf("%d", &choice) != 1) return 1;
	TFun selectedFunction = chooseFunction(choice);
	if (selectedFunction == NULL)
	{
		printf("Неверный выбор.\n");
		return 1;
	}
	printf("Введите значение x: ");
	if (scanf("%lf", &x) != 1) return 1;
	double result = selectedFunction(x);
	printf("Результат: %lf\n", result);

	puts("Задание 2");
	int action;
	do {
		printf("\n===== МЕНЮ =====\n");
		printf("1. Вычислить значение функции\n");
		printf("2. Табулировать\n");
		printf("3. Выполнить операцию\n");
		printf("0. Выход\n");
		printf("Выбор: ");
		if (scanf("%d", &action) != 1) {
			int c;
			while ((c = getchar()) != '\n' && c != EOF);
			if (c == EOF) break;
			continue;
		}

		if (action == 0) {
			printf("Выход из программы.\n");
			break;
		}

		if (action == 1) {
			int choice1;
			printf("Выберите функцию:\n");
			printf("1. y = log(|sqrt(x^3)|)\n");
			printf("2. v = { sqrt(tg(x^2 - 1)), если x > 1\n");
			printf("        -2x, если 0 <= x <= 1\n");
			printf("        exp(cos(x)), если x < 0 }\n");
			printf("3. s = (x - 1)/(x + 1) + (1/3)((x - 1)/(x + 1))^3 + (1/5)((x - 1)/(x + 1))^5 + (1/7)((x - 1)/(x + 1))^7\n");
			scanf("%d", &choice1);
			TFun f = chooseFunction(choice1);
			if (!f) continue;
			double x1;
			printf("Введите x: ");
			scanf("%lf", &x1);
			printf("f(%.4lf) = %.6lf\n", x1, f(x1));
		}
		else if (action == 2) {
			int num, type;
			double a, b, step;
			printf("\nВыберите функцию:\n");
			printf("1. Y(x)\n");
			printf("2. V(x)\n");
			printf("3. S(x)\n");
			printf("Ваш выбор: ");
			scanf("%d", &num);
			TFun tf = chooseFunction(num);
			if (!tf) { printf("Неверный выбор.\n"); continue; }

			printf("Тип интервала:\n");
			printf("1. [a, b]\n2. (a, b)\n3. [a, b)\n4. (a, b]\n");
			printf("Выбор: ");
			scanf("%d", &type);

			printf("Начало интервала: "); scanf("%lf", &a);
			printf("Конец интервала: ");  scanf("%lf", &b);
			printf("Шаг: ");              scanf("%lf", &step);
			if (step <= 0) { printf("Шаг должен быть > 0\n"); continue; }
			if (b < a) { printf("Конец интервала меньше начала\n"); continue; }

			tabulate(tf, a, b, step, type);
		}
		else if (action == 3) {
			int choice2;
			printf("Выберите функцию:\n");
			printf("1. y = log(|sqrt(x^3)|)\n");
			printf("2. v = { sqrt(tg(x^2 - 1)), если x > 1\n");
			printf("        -2x, если 0 <= x <= 1\n");
			printf("        exp(cos(x)), если x < 0 }\n");
			printf("3. s = (x - 1)/(x + 1) + (1/3)((x - 1)/(x + 1))^3 + (1/5)((x - 1)/(x + 1))^5 + (1/7)((x - 1)/(x + 1))^7\n");
			scanf("%d", &choice2);
			TFun f = chooseFunction(choice2);
			if (!f) continue;
			int op;
			printf("\nОперация:\n");
			printf("1. Записать значения в dat.txt\n");
			printf("2. Рассчитать по значениям из dat.txt\n");
			printf("3. Построить график\n");
			printf("4. Максимум методом золотого сечения\n");
			printf("5. Описать функцию на интервале\n");
			printf("6. Массив точек Point + печать\n");
			printf("7. Двумерный массив [x, y]\n");
			printf("8. Размах по осям\n");
			printf("Выбор: ");
			scanf("%d", &op);

			double a, b, step;
			switch (op) {
			case 1:
				printf("Начало, конец, шаг: ");
				scanf("%lf %lf %lf", &a, &b, &step);
				writeToFile(a, b, step, f);
				break;
			case 2:
				readFromFile(f);
				break;
			case 3:
				printf("Начало и конец интервала: ");
				scanf("%lf %lf", &a, &b);
				if (b <= a) { printf("Некорректный интервал\n"); break; }
				plot(a, b, f);
				break;
			case 4: {
				double eps;
				printf("Интервал [a; b] и точность: ");
				scanf("%lf %lf %lf", &a, &b, &eps);
				if (b < a || eps <= 0) { printf("Некорректные данные\n"); break; }
				double xmax = goldenSectionMax(f, a, b, eps);
				printf("Максимум: x = %.6lf, f(x) = %.6lf\n", xmax, f(xmax));
				break;
			}
			case 5:
				printf("Интервал [a; b]: ");
				scanf("%lf %lf", &a, &b);
				if (b <= a) { printf("Некорректный интервал\n"); break; }
				describeFunction(f, a, b);
				break;
			case 6: {
				printf("Интервал [a; b] и шаг: ");
				scanf("%lf %lf %lf", &a, &b, &step);
				int n;
				Point* arr = makePoints(f, a, b, step, &n);
				printf("Массив точек (%d):\n", n);
				printPoints(arr, n);
				free(arr);
				break;
			}
			case 7:
				printf("Интервал [a; b] и шаг: ");
				scanf("%lf %lf %lf", &a, &b, &step);
				twoDimensionalArray(f, a, b, step);
				break;
			case 8:
				printf("Интервал [a; b] и шаг: ");
				scanf("%lf %lf %lf", &a, &b, &step);
				rangeXY(f, a, b, step);
				break;
			default:
				printf("Неверная операция.\n");
			}
		}
		else {
			printf("Неверный выбор.\n");
		}
	} while (1);

	puts("Задание 3");
	printf("Введите количество точек: ");
	int n;
	if (scanf("%d", &n) != 1 || n <= 0) {
		printf("Неверное n\n");
		return 1;
	}
	printf("Введите %d значений x:\n", n);
	double* arr_x = (double*)malloc(n * sizeof(double));
	if (!arr_x) return 1;
	for (int i = 0; i < n; i++) {
		printf("x[%d]: ", i);
		scanf("%lf", &arr_x[i]);
	}
	printf("Выберите функцию:\n");
	printf("1. y = log(|sqrt(x^3)|)\n");
	printf("2. v = { sqrt(tg(x^2 - 1)), если x > 1\n");
	printf("        -2x, если 0 <= x <= 1\n");
	printf("        exp(cos(x)), если x < 0 }\n");
	printf("3. s = (x - 1)/(x + 1) + (1/3)((x - 1)/(x + 1))^3 + (1/5)((x - 1)/(x + 1))^5 + (1/7)((x - 1)/(x + 1))^7\n");
	scanf("%d", &choice);
	selectedFunction = chooseFunction(choice);
	if (selectedFunction == NULL)
	{
		printf("Неверный выбор.\n");
		free(arr_x);
		return 1;
	}
	x = calculate(selectedFunction, arr_x, n);
	printf("Результат: %lf\n", x);
	free(arr_x);

	return 0;
}

double funY(double x)
{
	return log(fabs(sqrt(pow(x, 3))));
}

double funV(double x)
{
	if (x > 1)
		return sqrt(tan(x * x - 1));
	if (x <= 1 && x >= 0)
		return -2 * x;
	if (x < 0)
		return exp(cos(x));
	return NAN;
}

double funS(double x)
{
	return (x - 1) / (x + 1)
		+ (1.0 / 3.0) * pow((x - 1) / (x + 1), 3)
		+ (1.0 / 5.0) * pow((x - 1) / (x + 1), 5)
		+ (1.0 / 7.0) * pow((x - 1) / (x + 1), 7);
}

TFun chooseFunction(int choice)
{
	switch (choice)
	{
	case 1:
		return funY;
	case 2:
		return funV;
	case 3:
		return funS;
	default:
		return NULL;
	}
}

void plot(double x0, double x1, TFun f)
{
	enum { SCREENW = 60, SCREENH = 40 };
	char screen[SCREENW][SCREENH];
	double x, y[SCREENW];
	double ymin = 0, ymax = 0;
	double hx, hy;
	int i, j;
	int xz, yz;

	hx = (x1 - x0) / (SCREENW - 1);
	for (i = 0, x = x0; i < SCREENW; ++i, x += hx) {
		y[i] = f(x);
		if (!isfinite(y[i])) continue;
		if (y[i] < ymin) ymin = y[i];
		if (y[i] > ymax) ymax = y[i];
	}
	hy = (ymax - ymin) / (SCREENH - 1);
	if (hy == 0) hy = 1;
	yz = (int)floor(ymax / hy + 0.5);
	xz = (int)floor((0. - x0) / hx + 0.5);

	for (j = 0; j < SCREENH; ++j)
		for (i = 0; i < SCREENW; ++i) {
			if (j == yz && i == xz) screen[i][j] = '+';
			else if (j == yz) screen[i][j] = '-';
			else if (i == xz) screen[i][j] = '|';
			else screen[i][j] = ' ';
		}

	for (i = 0; i < SCREENW; ++i) {
		if (!isfinite(y[i])) continue;
		j = (int)floor((ymax - y[i]) / hy + 0.5);
		if (j >= 0 && j < SCREENH) screen[i][j] = '*';
	}

	for (j = 0; j < SCREENH; ++j) {
		for (i = 0; i < SCREENW; ++i) putchar(screen[i][j]);
		putchar('\n');
	}
}

void writeToFile(double x0, double x1, double step, TFun f)
{
	if (step <= 0 || x1 < x0) { printf("Некорректный интервал или шаг\n"); return; }
	FILE* fp = fopen("dat.txt", "w");
	if (!fp) { printf("Не удалось открыть dat.txt\n"); return; }
	for (double x = x0; x <= x1 + 1e-9; x += step)
		fprintf(fp, "%lf,%lf\n", x, f(x));
	fclose(fp);
	printf("Записано в dat.txt\n");
}

void readFromFile(TFun f)
{
	FILE* fp = fopen("dat.txt", "r");
	if (!fp) { printf("Не удалось открыть dat.txt\n"); return; }
	double x;
	char line[256];
	printf("Значения из dat.txt:\n");
	while (fgets(line, sizeof(line), fp)) {
		if (sscanf(line, "%lf", &x) == 1)
			printf("x = %8.4lf  ->  y = %8.4lf\n", x, f(x));
	}
	fclose(fp);
}

double goldenSectionMax(TFun f, double a, double b, double eps)
{
	double phi = (sqrt(5.0) - 1) / 2;
	double x1 = b - phi * (b - a);
	double x2 = a + phi * (b - a);
	double f1 = f(x1), f2 = f(x2);
	while ((b - a) > eps) {
		if (f1 < f2) {
			a = x1; x1 = x2; f1 = f2;
			x2 = a + phi * (b - a); f2 = f(x2);
		}
		else {
			b = x2; x2 = x1; f2 = f1;
			x1 = b - phi * (b - a); f1 = f(x1);
		}
	}
	return (a + b) / 2;
}

void describeFunction(TFun f, double a, double b)
{
	int n = 200;
	double step = (b - a) / (n - 1);
	int increasing = 1, decreasing = 1;
	int hasPos = 0, hasNeg = 0;
	double prev = f(a);
	for (int i = 1; i < n; i++) {
		double cur = f(a + i * step);
		if (cur < prev) increasing = 0;
		if (cur > prev) decreasing = 0;
		if (cur > 0) hasPos = 1;
		if (cur < 0) hasNeg = 1;
		prev = cur;
	}
	printf("Монотонность: ");
	if (increasing) printf("возрастающая\n");
	else if (decreasing) printf("убывающая\n");
	else printf("немонотонная\n");

	printf("Знаки: ");
	if (hasPos && hasNeg) printf("знакопеременная\n");
	else if (hasPos) printf("положительная\n");
	else if (hasNeg) printf("отрицательная\n");
	else printf("нулевая\n");

	int even = 1, odd = 1, checked = 0;
	for (int i = 1; i <= 20; i++) {
		double x = a + i * step;
		if (x > 0 && -x >= a && -x <= b) {
			checked++;
			if (fabs(f(-x) - f(x)) > 1e-6) even = 0;
			if (fabs(f(-x) + f(x)) > 1e-6) odd = 0;
		}
	}
	if (!checked) printf("Симметрия: на этом интервале не проверить\n");
	else if (even) printf("Симметрия: чётная\n");
	else if (odd) printf("Симметрия: нечётная\n");
	else printf("Симметрия: отсутствует\n");
}

Point* makePoints(TFun f, double a, double b, double step, int* outN)
{
	if (step <= 0 || b < a) { *outN = 0; return NULL; }
	int cap = (int)((b - a) / step) + 2;
	Point* arr = malloc(cap * sizeof(Point));
	if (!arr) { *outN = 0; return NULL; }
	int n = 0;
	for (double x = a; x <= b + 1e-9; x += step) {
		arr[n].x = x;
		arr[n].y = f(x);
		if (++n >= cap) break;
	}
	*outN = n;
	return arr;
}

void printPoint(const Point* p)
{
	printf("(x = %8.4lf, y = %8.4lf)\n", p->x, p->y);
}

void printPoints(const Point* arr, int n)
{
	for (int i = 0; i < n; i++) printPoint(&arr[i]);
}

void twoDimensionalArray(TFun f, double a, double b, double step)
{
	if (step <= 0 || b < a) { printf("Некорректный интервал или шаг\n"); return; }
	int n = (int)((b - a) / step) + 1;
	double** m = malloc(n * sizeof(double*));
	for (int i = 0; i < n; i++) m[i] = malloc(2 * sizeof(double));
	for (int i = 0; i < n; i++) {
		m[i][0] = a + i * step;
		m[i][1] = f(m[i][0]);
	}
	printf("Двумерный массив [x, y]:\n");
	for (int i = 0; i < n; i++)
		printf("  [%8.4lf, %8.4lf]\n", m[i][0], m[i][1]);
	for (int i = 0; i < n; i++) free(m[i]);
	free(m);
}

void rangeXY(TFun f, double a, double b, double step)
{
	if (step <= 0 || b < a) { printf("Некорректный интервал или шаг\n"); return; }
	double ymin = f(a), ymax = f(a);
	for (double x = a; x <= b + 1e-9; x += step) {
		double y = f(x);
		if (y < ymin) ymin = y;
		if (y > ymax) ymax = y;
	}
	printf("Размах по X: [%.4lf; %.4lf], размах = %.4lf\n", a, b, b - a);
	printf("Размах по Y: [%.4lf; %.4lf], размах = %.4lf\n", ymin, ymax, ymax - ymin);
}

int tabulate(TFun f, double x1, double x2, double step, int type) {
	int flag = 0;
	printf("Табулирование на ");
	switch (type) {
	case 1: printf("[%.4lf, %.4lf]\n", x1, x2); break;
	case 2: printf("(%.4lf, %.4lf)\n", x1, x2); break;
	case 3: printf("[%.4lf, %.4lf)\n", x1, x2); break;
	case 4: printf("(%.4lf, %.4lf]\n", x1, x2); break;
	default:
		printf("(неверный тип интервала)\n");
		return 0;
	}

	printf("+------------+----------------+\n");
	printf("|      x     |      F(x)      |\n");
	printf("+------------+----------------+\n");

	int n = (int)floor((x2 - x1) / step + 1e-9);
	double EPS = 1e-9;

	for (int i = 0; i <= n; i++) {
		double x = x1 + i * step;

		if (x > x2 + EPS) break;

		int is_left_bound = fabs(x - x1) < EPS;
		int is_right_bound = fabs(x - x2) < EPS;

		if (type == 2 && (is_left_bound || is_right_bound)) continue;
		if (type == 3 && is_right_bound) continue;
		if (type == 4 && is_left_bound)  continue;

		double y = f(x);
		if (isnan(y) || isinf(y)) {
			printf("| %10.4lf | не определена   |\n", x);
		}
		else {
			printf("| %10.4lf | %14.6lf |\n", x, y);
			flag = 1;
		}
	}
	printf("+------------+----------------+\n");
	return flag;
}

double calculate(TFun ptrf, double* x, int n) {
	int i = 0;
	int imax = 0;
	for (i = 0; i < n; i++) {
		if (ptrf(x[i]) > ptrf(x[imax])) {
			imax = i;
		}
	}
	return x[imax];
}
