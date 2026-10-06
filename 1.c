#include <stdio.h>
#include <locale.h>
void prac1();
void prac2();
void prac3();
void prac4();
void name();
void date();
void dz1();
int main() {
	setlocale(LC_ALL, "Ru");
	printf("Практика 1\n");
	printf("\nЗадание 1\n");
	prac1();
	printf("\nЗадание 2\n");
	prac2();
	printf("\nЗадание 3\n");
	prac3();
	printf("\nЗадание 4\n");
	prac4();
	printf("\nДомашнее задание\n");
	dz1();
	return 0;
}
void prac1()
{
	setlocale(LC_CTYPE, "RUS");
	puts("Нажмите Enter для продолжения...");

	getchar();

	puts("Продолжение программы");

}
void prac2()
{
	setlocale(LC_CTYPE, "RUS");
	puts("Моя программа,");

	getchar();
	puts("***************************************************");
	puts("*                                                 *");
	puts("*     тема: Разработка консольного приложения     *");
	puts("*                                                 *");
	puts("* выполнила: Лысюк Е.В. (группа бИД262-1)         *");
	puts("*                                                 *");
	puts("***************************************************");

}
void prac3()
{
	setlocale(LC_CTYPE, "RUS");
	puts("Дата рождения");

	getchar();

	puts(" _    _     _   _     _    _ ");
	puts("| |  |_    | |  _|   | |  |_|");
	puts("|_|   _| . |_|  _| . |_|  |_|");

}
void prac4()
{
	name();
	date();
}

void name()
{
	setlocale(LC_CTYPE, "RUS");
	puts("Моя программа,");
	getchar();
	puts("***************************************************");
	puts("*                                                 *");
	puts("*     тема: Разработка консольного приложения     *");
	puts("*                                                 *");
	puts("* выполнила: Лысюк Е.В. (группа бИД262-1)         *");
	puts("*                                                 *");
	puts("***************************************************");

}

void date()
{
	puts(" _    _     _   _     _    _ ");
	puts("| |  |_    | |  _|   | |  |_|");
	puts("|_|   _| . |_|  _| . |_|  |_|");
}
void dz1()
{
	setlocale(LC_CTYPE, "RUS");
	puts("Кораблик:");

	getchar();
	puts("                |\\              ");
	puts("                | \\             ");
	puts("                |  \\            ");
	puts("                |   \\           ");
	puts("                |    \\          ");
	puts("                |     \\         ");
	puts("                |      \\        ");
	puts("                |_______\\       ");
	puts("                |                ");
	puts("      __________|__________      ");
	puts("      \\                   /     ");
	puts("       \\                 /      ");
	puts("        \\_______________/       ");
}
C:\Users\User\source\repos\lab1\lab1\1.c