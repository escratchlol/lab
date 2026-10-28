#include <stdio.h>
#include <locale.h>
#include <math.h>

#define PI 3.1415926535

double fa(double x);
double fb(double x);

double asin_n(double x, int N);
double asin_eps(double x, double eps);

double vx(int k, double d1, double d2, double a);
double vy(int k, double d1, double d2, double a);
int in_quad(double x, double y, double d1, double d2, double a);
void draw_figure(char sym, double d1, double d2, double ang);
int param_ok(double d1, double d2, double ang);
double dist(double px, double py, double x1, double y1, double x2, double y2);
char f_char(double x, double y, double d1, double d2, double a, char sym);
double S(double d1, double d2, double a);

int main()
{
    setlocale(LC_ALL, "Ru");

    puts("задание 1");
    double x;
    printf("Введите x: ");
    scanf("%lf", &x);
    double Fa = fa(x);
    double Fb = fb(x);
    printf("Fa=%lf , Fb=%lf\n ", Fa, Fb);
    printf("%lf (произведение)\n%lf (разность квадратов)\n%lf (удвоенная сумма)\n", Fa * Fb, Fa * Fa - Fb * Fb, 2 * Fa + 2 * Fb);



    printf("Fa=%lf , Fb=%lf\n", Fa, Fb);

    int choice;
    while (1) {
        printf("\nВыберите операцию:\n");
        printf("1 - произведение Fa*Fb\n");
        printf("2 - разность квадратов Fa^2(x) - fb^2(x)\n");
        printf("3 - удвоенная сумма 2*Fa + 2*Fb\n");
        printf("0 - вывести все сразу\n");
        printf("-1 - выход\n");
        printf("Ваш выбор: ");

        scanf("%d", &choice);

        if (choice == -1) {
            printf("Выход.\n");
            break;
        }

        switch (choice) {
        case 1:
            printf("Произведение: %lf\n", Fa * Fb);
            break;
        case 2:
            printf("Разность квадратов: %lf\n", Fa * Fa - Fb * Fb);
            break;
        case 3:
            printf("Удвоенная сумма: %lf\n", 2 * Fa + 2 * Fb);
            break;
        case 0:
            printf("%lf (произведение), %lf (разность квадратов), %lf (удвоенная сумма)\n",
                Fa * Fb, Fa * Fa - Fb * Fb, 2 * Fa + 2 * Fb);
            break;
        deFault:
            printf("Неверный выбор! Попробуйте снова.\n");
        }
    }


    puts("\nЗадание 2");

    double x_asin;
    printf("Введите x (|x| < 1) для arcsin: ");
    scanf("%lf", &x_asin);

    int N;
    printf("Введите N (количество членов ряда): ");
    scanf("%d", &N);

    double exact = asin(x_asin);

    printf("\n%3s | %10s | %15s\n", "N", "sin_N", "отклонение");
    printf("----+------------+----------------\n");

    for (int k = 1; k <= N; k++) {
        double approx = asin_n(x_asin, k);
        printf("%3d | %10.4lf | %+15.4e\n", k, approx, approx - exact);
    }

    double eps;
    printf("\nВведите eps для asin_eps: ");
    scanf("%lf", &eps);

    double approx_eps = asin_eps(x_asin, eps);
    printf("\nasin_eps(%.4lf, %g) = %.10lf\n", x_asin, eps, approx_eps);
    printf("Точное значение asin(%.4lf) = %.10lf\n", x_asin, exact);
    printf("Отклонение: %+.4e\n", approx_eps - exact);


    puts("Задание 3");
    int op;
    while (1) {
        char sym;
        double d1, d2, ang;
        printf("\nВведите символ, из которого будет строиться фигура: ");
        scanf(" %c", &sym);
        printf("Введите d1: ");
        scanf("%lf", &d1);
        printf("Введите d2: ");
        scanf("%lf", &d2);
        printf("Введите угол между диагоналями (в градусах): ");
        scanf("%lf", &ang);
        printf("\n\n\n");

        printf("\n--- Меню для четырехугольника ---\n");
        printf("1 - рассчитать площадь\n");
        printf("2 - вывести определение фигуры\n");
        printf("3 - нарисовать фигуру\n");
        printf("0 - выход\n");
        printf("Ваш выбор: ");
        scanf("%d", &op);

        if (op == 0) break;

        switch (op) {
        case 1: {
            if (!param_ok(d1, d2, ang))
            {
                puts("ошибка: d1 и d2 должны быть больше 0, угол от 0 до 180");
            }
            printf("S = %lf", S(d1, d2, ang));
            break;
        }
        case 2:
            printf("Четырёхугольник - это геометрическая фигура (многоугольник), которая состоит из четырёх точек (вершин) и четырёх отрезков (сторон), последовательно соединяющих эти точки. При этом должны соблюдаться два условия: никакие три из данных точек не лежат на одной прямой; соединяющие их отрезки не пересекаются(не имеют общих внутренних точек).\n");
            break;
        case 3: {
            if (!param_ok(d1, d2, ang))
            {
                puts("ошибка: d1 и d2 должны быть больше 0, угол от 0 до 180");
            }
            else {
                double ymax = fmax(fmax(vy(1, d1, d2, ang), vy(2, d1, d2, ang)),
                    fmax(vy(3, d1, d2, ang), vy(4, d1, d2, ang)));
                double ymin = fmin(fmin(vy(1, d1, d2, ang), vy(2, d1, d2, ang)),
                    fmin(vy(3, d1, d2, ang), vy(4, d1, d2, ang)));
                double xmax = fmax(fmax(vx(1, d1, d2, ang), vx(2, d1, d2, ang)),
                    fmax(vx(3, d1, d2, ang), vx(4, d1, d2, ang)));
                double xmin = fmin(fmin(vx(1, d1, d2, ang), vx(2, d1, d2, ang)),
                    fmin(vx(3, d1, d2, ang), vx(4, d1, d2, ang)));

                printf("\n");
                for (int r = (int)ceil(ymax); r >= (int)floor(ymin); r--)
                {
                    for (int cx = (int)floor(xmin * 2); cx <= (int)ceil(xmax * 2); cx++)
                    {
                        putchar(f_char(cx * 0.5, r, d1, d2, ang, sym));
                    }
                    putchar('\n');
                }
            }
            break;
        }
        default:
            printf("Неверный выбор! Попробуйте снова.\n");
        }
    }
    return 0;
}

double fa(double x)
{
    if (x <= 3) {
        return x * x - 3 * x + 9;
    }
    else {
        return 1.0 / (x * x * x + 3);
    }
}


double fb(double x)
{
    return x * exp(sin(pow(x, 2)));
}

double asin_n(double x, int N) {
    double sum = x;

    for (int n = 1; n <= N; n++) {
        double num = 1.0;
        double den = 1.0;
        for (int i = 1; i <= n; i++) {
            num *= (2.0 * i - 1);
            den *= (2.0 * i);
        }
        double term = (num / den) * pow(x, 2 * n + 1) / (2.0 * n + 1);
        sum += term;
    }
    return sum;
}

double asin_eps(double x, double eps) {
    double sum = x;
    int n = 1;
    double term = 1.0;

    while (fabs(term) > eps) {
        double num = 1.0;
        double den = 1.0;
        for (int i = 1; i <= n; i++) {
            num *= (2.0 * i - 1);
            den *= (2.0 * i);
        }
        term = (num / den) * pow(x, 2 * n + 1) / (2.0 * n + 1);
        sum += term;
        n++;
    }
    return sum;
}

double S(double d1, double d2, double a) {
    return 0.5 * d1 * d2 * sin(a * PI / 180.0);
}

int param_ok(double d1, double d2, double ang)
{
    if (d1 <= 0 || d2 <= 0 || ang <= 0 || ang >= 180)
    {
        return 0;
    }
    return 1;
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

double dist(double px, double py, double x1, double y1, double x2, double y2)
{
    double dx = x2 - x1;
    double dy = y2 - y1;
    double t = ((px - x1) * dx + (py - y1) * dy) / (dx * dx + dy * dy);
    if (t < 0)
    {
        t = 0;
    }
    else if (t > 1)
    {
        t = 1;
    }

    double cx = x1 + t * dx;
    double cy = y1 + t * dy;

    double ex = px - cx;
    double ey = py - cy;
    return sqrt(ex * ex + ey * ey);
}

char f_char(double x, double y, double d1, double d2, double a, char sym)
{
    for (int k = 1; k <= 4; k++)
    {
        int next = (k == 4) ? 1 : k + 1;

        double x1 = vx(k, d1, d2, a);
        double y1 = vy(k, d1, d2, a);
        double x2 = vx(next, d1, d2, a);
        double y2 = vy(next, d1, d2, a);

        double ddx = (x - x1) * 2.0;
        double ddy = (y - y1);
        double sx = (x2 - x1) * 2.0;
        double sy = (y2 - y1);

        double t = (ddx * sx + ddy * sy) / (sx * sx + sy * sy);
        if (t < 0) t = 0;
        else if (t > 1) t = 1;

        double ex = ddx - t * sx;
        double ey = ddy - t * sy;

        if (sqrt(ex * ex + ey * ey) < 0.5)
        {
            return sym;
        }
    }
    return ' ';
}
