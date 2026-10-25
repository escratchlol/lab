#include <stdio.h>
#include <locale.h>


float calculator(float x, char c, float y);
int is_num(char c);
int age(int num);

int main()

{
	setlocale(LC_ALL, "Russian");
	char c;
	printf("Введите символ: ");
	scanf("%c", &c);
	puts("заданиe 1:");
	int result = is_num(c);
	switch (result)
	{
	case 1:
		puts("Это цифра");
		break;
	case 0:
		puts("Это буква");
		break;
	default:
		puts("неизвестный символ");
		break;
	}


	puts("задание 2:");
	puts("Введите два числа и символ между ними: ");
	float x, y;
	char c1;
	scanf("%f %c %f", &x, &c1, &y);
	if (can_cal(x, c1, y))
	{
		printf("= %f\n", calculator(x, c1, y));
	}
	else
	{
		puts("Ошибка");
	}



	puts("задание 3:");
	int num;
	printf("Введите число месяцев ребенка: ");
	scanf("%d", &num);

	int result3 = age(num);
	switch (result3)
	{
	case -1:
		puts("Ошибка");
		break;
	case 1:
		puts("Новорожденный");
		break;
	case 2:
		puts("Младенец");
		break;
	case 3:
		puts("Ранее детсво");
		break;
	case 4:
		puts("Дошкольник");
		break;
	case 5:
		puts("школьник");
		break;
	case 6:
		puts("Подросток");
		break;
	case 7:
		puts("Взрослый");
		break;
	default:
		break;
	}


}

int can_cal(float x, char c, float y)
{
	switch (c)
	{
	case '+': case '-': case '*':
		return 1;
		break;
	case '/':
		if (y == 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	default:
		return 0;
	}
}
int is_num(char c)
{
	switch (c)
	{
	case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
		return 1;
		break;
	default:
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= 'а' && c <= 'я') || (c >= 'А' && c <= 'Я'))
		{
			return 0;
		}
		else
		{
			return -1;
		}
		return 0;
	}
}

float calculator(float x, char c, float y)
{
	switch (c)
	{
	case '+':
		return x + y;
		break;
	case '-':
		return x - y;
		break;
	case '*':
		return x * y;
		break;
	case '/':
		return x / y;
	}
}

int age(int num)
{
	if (num < 0) {
		return -1;
	}

	if (num >= 0 && num < 2) {
		return 1;
	}

	int year = num / 12;
	switch (year)
	{
	case 0:
		return 2;
		break;
	case 1: case 2:
		return 3;
		break;
	case 3: case 4: case 5: case 6: case 7:
		return 4;
		break;
	case 8: case 9: case 10: case 11: case 12:
		return 5;
		break;
	case 13: case 14: case 15: case 16: case 17:
		return 6;
		break;
	default:
		return 7;
	}
}
