#include <stdio.h>
#include <locale.h>

void task1_1_pifagor();      
void task1_2_triangle();   
void task1_3_addition();       
void task2_digit_analysis();  
void task3_rectangle();          

int main() {
    setlocale(LC_ALL, "Ru");
    char choice;

    do {
        printf("ВЫБЕРИТЕ ЗАДАНИЕ ДЛЯ ПРОВЕРКИ:\n");
        printf("1 - Таблица Пифагора (Задание 1.1)\n");
        printf("2 - Нижний левый треугольник (Задание 1.2)\n");
        printf("3 - Таблица сложения (Задание 1.3)\n");
        printf("4 - Анализ цифр числа (Задание 2)\n");
        printf("5 - Пустой прямоугольник (Задание 3)\n");
        printf("0 - Выход\n");
        printf("Ваш выбор: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1': task1_1_pifagor(); break;
            case '2': task1_2_triangle(); break;
            case '3': task1_3_addition(); break;
            case '4': task2_digit_analysis(); break;
            case '5': task3_rectangle(); break;
            case '0': printf("Выход из программы...\n"); break;
            default: printf("Неверный ввод! Попробуйте снова.\n"); break;
        }
    } while (choice != '0');

    return 0;
}

void task1_1_pifagor() {
    int row, col;
    printf("\n--- Таблица Пифагора ---\n");

    printf("    ");
    for (col = 1; col <= 9; col++) printf("%4d", col);
    printf("\n");

    for (row = 1; row <= 9; row++) {
        printf("%3d ", row);
        for (col = 1; col <= 9; col++) {
            printf("%4d", row * col);
        }
        printf("\n");
    }
}

void task1_2_triangle() {
    int row, col;
    printf("\n--- Нижний левый треугольник ---\n");

    for (row = 9; row >= 1; row--) {
        for (col = 1; col <= row; col++) {
            printf("%5d", col * row);
        }
        printf("\n");
    }
}

void task1_3_addition() {
    printf("\n--- Полная таблица сложения ---\n");
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {

            printf("%d + %d = %2d\t", i, j, i + j);
        }
        printf("\n");
    }
}

void task2_digit_analysis() {
    char str[100]; 
    printf("\n--- Анализ цифр длинного числа ---\n");
    printf("Введите число: ");
    scanf("%s", str);

    int len = 0;
    while (str[len] != '\0') len++; 

    int count_3 = 0;
    int count_even = 0;
    int count_gt_5 = 0;
    int sum_odd = 0;
    int sum_ge_7 = 0;
    long long prod_non_zero = 1;
    int sum_even_no_last = 0;
    int has_duplicates = 0;

    for (int i = 0; i < len; i++) {
        int digit = str[i] - '0'; 

        if (digit == 3) count_3++;
        if (digit % 2 == 0) count_even++;
        if (digit > 5) count_gt_5++;
        if (digit % 2 != 0) sum_odd += digit;
        if (digit >= 7) sum_ge_7 += digit;
        if (digit != 0) prod_non_zero *= digit;
        
        if (i < len - 1 && digit % 2 == 0) sum_even_no_last += digit;

        if (i > 0 && str[i] == str[i-1]) has_duplicates = 1;
    }

    printf("\nРезультаты анализа:\n");
    printf("1) Количество цифр 3: %d\n", count_3);
    
    int last_digit = str[len - 1] - '0';
    int count_last = 0;
    for (int i = 0; i < len; i++) {
        if ((str[i] - '0') == last_digit) count_last++;
    }
    printf("2) Повторений последней цифры (%d): %d\n", last_digit, count_last);

    printf("3) Количество четных цифр: %d\n", count_even);
    printf("4) Количество цифр > 5: %d\n", count_gt_5);
    printf("5) Сумма нечетных цифр: %d\n", sum_odd);
    printf("6) Сумма цифр >= 7: %d\n", sum_ge_7);
    printf("7) Произведение цифр (без 0): %lld\n", prod_non_zero);

    if (len >= 2) {
        int penultimate = str[len - 2] - '0';
        int second = str[1] - '0';
        printf("8) Произведение предпоследней (%d) и второй (%d): %d\n", penultimate, second, penultimate * second);
    } else {
        printf("8) Недостаточно цифр для вычисления.\n");
    }

    printf("9) Сумма четных цифр (без последней): %d\n", sum_even_no_last);
    printf("10) Есть ли рядом стоящие одинаковые цифры? %s\n", has_duplicates ? "Да" : "Нет");

    if (len % 2 == 0) {
        int half = len / 2, sum1 = 0, sum2 = 0;
        for (int i = 0; i < half; i++) sum1 += (str[i] - '0');
        for (int i = half; i < len; i++) sum2 += (str[i] - '0');
        printf("11) Сумма первой половины (%d) %s сумме второй (%d)\n", sum1, (sum1 == sum2) ? "равна" : "не равна", sum2);
    } else {
        printf("11) Число нечетной длины, нельзя разделить ровно пополам.\n");
    }

    int sum_even_pos = 0, sum_odd_pos = 0;
    for (int i = 0; i < len; i++) {

        int pos = len - i; 
        if (pos % 2 == 0) sum_even_pos += (str[i] - '0');
        else sum_odd_pos += (str[i] - '0');
    }
    printf("12) Произведение сумм четных и нечетных разрядов: %d\n", sum_even_pos * sum_odd_pos);
}


void task3_rectangle() {
    char symbol;
    int height, width;

    printf("\n--- Рисование пустого прямоугольника ---\n");
    printf("Введите символ для рисования: ");
    scanf(" %c", &symbol); 
    printf("Введите высоту: ");
    scanf("%d", &height);
    printf("Введите ширину: ");
    scanf("%d", &width);

    printf("\nРезультат:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                printf("%c", symbol);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
