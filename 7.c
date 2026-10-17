#include <stdio.h>
#include <locale.h>

#define error -123456

float calculator(float x, char c, float y);
int is_num(char c);
int age(int num);

int main()

{
	setlocale(LC_ALL, "Ru");
	char c;
	printf("Введите символ: ");
	scanf("%c", &c);
	puts("задание 1:");
	int result = is_num(c);
	switch (result)
	{
	case 1:
		puts("это цифра");
		break;
	case 0:
		puts("это буква");
		break;
	default:
		puts("неизвестный символ");
		break;
	}


	puts("задание 2:");
	puts("введите два числа и символ между ними: ");
	float x, y;
	char c1;
	scanf("%f %c %f”", &x, &c1, &y);
	float result2 = calculator(x, c1, y);
	if (result2 != error) {
		printf("= %f\n", result2);
	}
	else
	{
		puts("ошибка");
	}


	puts("задание 3:");
	int num;
	printf("введите число месяцев ребенка: ");
	scanf("%d", &num);

	int result3 = age(num);
	switch (result3)
	{
	case -1:
		puts("ошибка");
		break;
	case 1:
		puts("новорожденный");
		break;
	case 2:
		puts("младенец");
		break;
	case 3:
		puts("ранее детсво");
		break;
	case 4:
		puts("дошкольник");
		break;
	case 5:
		puts("школьник");
		break;
	case 6:
		puts("подросток");
		break;
	case 7:
		puts("взрослый");
		break;
	default:
		break;
	}
	return 0;
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
		if (y == 0)
		{
			return error;
		}
		else
		{
			return x / y;
		}
	default:
		return error;
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
