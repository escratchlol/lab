#include <stdio.h>
#include <locale.h>
#include <math.h>

#define N 10

unsigned char get_byte(const void* x6, int i);

int main()
{
	setlocale(LC_ALL, "Ru");

	puts("задание 1");
	printf("указатель на char: %lu \n", sizeof(char*));
	printf("указатель на int: %lu \n", sizeof(int*));
	printf("указатель на double: %lu \n", sizeof(double*));
	// адреса имеют одинаковый размер, так как они хранятся в памяти как целые числа, которые указывают на конкретное место в памяти. Размер указателя зависит от архитектуры процессора (32-битная или 64-битная).

	puts("задание 2");
	float PI = 3.14159, * p1, * p2;
	p1 = p2 = &PI;
	printf("По адресу p1=%p хранится *p1=%g\n", p1, *p1);
	printf("По адресу p2=%p хранится *p2=%g\n", p2, *p2);
	// p1 и p2 указывают на один и тот же адрес памяти, где хранится значение переменной PI. Поэтому вывод будет одинаковым для обоих указателей.

	puts("задание 3");
	int* pа, x = 5;
	pа = &x;
	printf("По адресу %p хранится *ptr=%g\n", pа, *pа);
	pа++;
	printf("По адресу %p хранится *ptr=%g\n", pа, *pа);
	pа--;
	printf("По адресу %p хранится *ptr=%g\n", pа, *pа);
	// При инкременте указателя pа, он указывает на следующий элемент типа int в памяти. При декременте указатель возвращается к исходному адресу. Вывод покажет разные адреса, но значение *pа будет неверным, так как %g используется для вывода чисел с плавающей запятой, а *pа является целым числом. Для int стоит использовать %d
	puts("3.1");
	double* pа1, x1 = 5;
	pа1 = &x1;
	printf("По адресу %p хранится *ptr=%g\n", pа1, *pа1);
	pа1++;
	printf("По адресу %p хранится *ptr=%g\n", pа1, *pа1);
	pа1--;
	printf("По адресу %p хранится *ptr=%g\n", pа1, *pа1);
	// в данном случае все корректно и прыжок составляяеь 8 байт, так как размер double равен 8 байт.

	puts("char");
	char* pа2, x2 = 5;
	pа2 = &x;
	printf("По адресу %p хранится *ptr=%d\n", pа2, *pа2);
	pа2++;
	printf("По адресу %p хранится *ptr=%d\n", pа2, *pа2);
	pа2--;
	printf("По адресу %p хранится *ptr=%d\n", pа2, *pа2);

	puts("long double");
	long double* pа3, x3 = 5;
	pа3 = &x3;
	printf("По адресу %p хранится *ptr=%Lf\n", pа3, *pа3);
	pа3++;
	printf("По адресу %p хранится *ptr=%Lf\n", pа3, *pа3);
	pа3--;
	printf("По адресу %p хранится *ptr=%Lf\n", pа3, *pа3);

	puts("short unsigned int");
	short unsigned int* pа4, x4 = 5;
	pа4 = &x4;
	printf("По адресу %p хранится *ptr=%hu\n", pа4, *pа4);
	pа4++;
	printf("По адресу %p хранится *ptr=%hu\n", pа4, *pа4);
	pа4--;
	printf("По адресу %p хранится *ptr=%hu\n", pа4, *pа4);

	puts("_Bool");
	_Bool* pа5, x5 = 5;
	pа5 = &x5;
	printf("По адресу %p хранится *ptr=%d\n", pа5, *pа5);
	pа5++;
	printf("По адресу %p хранится *ptr=%d\n", pа5, *pа5);
	pа5--;
	printf("По адресу %p хранится *ptr=%d\n", pа5, *pа5);

	puts("задание 4");
	float array[N] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10 };
	float* ptr_a;
	puts("4.1");
	printf("array =  %p\n", array);
	printf("&array[0] =  %p\n", &array[0]);
	printf("&array =  %p\n", &array);
	// array, &array[0] и &array указывают на один и тот же адрес памяти, так как array является указателем на первый элемент массива.
	puts("4.2");
	ptr_a = array;
	printf("начало %p    ptr_a =  %g\n", ptr_a, *ptr_a);
	ptr_a++;
	printf("ptr_a++ %p    ptr_a =  %g\n", ptr_a, *ptr_a);
	ptr_a += 4;
	printf("ptr_a+4 %p    ptr_a =  %g\n", ptr_a, *ptr_a);
	ptr_a -= 2;
	printf("ptr_a-2 %p    ptr_a =  %g\n", ptr_a, *ptr_a);
	puts("4.3");
	for (ptr_a = array; ptr_a < array + 10; ptr_a += 2)
	{
		printf("ptr_a =  %p    *ptr_a =  %g\n", ptr_a, *ptr_a);
	}
	puts("4.4");
	for (ptr_a = array + N - 1; ptr_a >= array; ptr_a--)
	{
		printf("ptr_a =  %p    *ptr_a =  %g\n", ptr_a, *ptr_a);
	}

	puts("задание 5");

	int x6 = 0x12345678; // переменная, инициализированная значением 0x12345678
	int* prt;           // указатель для исследуемой переменной
	unsigned char* a1, * a2, * a3, * a4; // указатели на байты
	unsigned char* a;   // указатель на байт

	prt = &x6; // получение адреса переменной
	a = (unsigned char*)prt; // преобразование типа для получения указателя на один байт

	a1 = a + 3; // получение 4-го байта числа x
	a2 = a + 2; // получение 3-го байта
	a3 = a + 1; // получение 2-го байта
	a4 = a;     // получение 1-го байта числа x

	// Вывод байтов в hex-формате
	printf("%.2x %.2x %.2x %.2x\n", *a1, *a2, *a3, *a4);
	// B)  с наибольшего адреса("little-end" - прямое размещение байтов))
	puts("5.1");
	for (int i = 0; i < (int)sizeof(x6); i++)
	{
		printf("Байт по смещению %d: %02X\n", i, get_byte(&x6, i));
	}

	puts("5.2");
	int     i_val = 12345;
	float   f_val = 12345.0f;
	double  d_val = 12345.0;

	printf("\nint (4 байта):\n");
	for (int i = 0; i < (int)sizeof(i_val); i++) {
		printf("%02X ", get_byte(&i_val, i));
	}
	printf("\n");

	printf("\nfloat (4 байта):\n");
	for (int i = 0; i < (int)sizeof(f_val); i++) {
		printf("%02X ", get_byte(&f_val, i));
	}
	printf("\n");

	printf("\ndouble (8 байт):\n");
	for (int i = 0; i < (int)sizeof(d_val); i++) {
		printf("%02X ", get_byte(&d_val, i));
	}
	printf("\n");

	puts("дз");
	printf("Размер int: %d байт\n", size_int());
	return 0;
}

unsigned char get_byte(const void* x6, int i)
{
	return ((unsigned char*)x6)[i];
}

int size_int() {
	int* p = NULL;
	return (char*)(p + 1) - (char*)p;
}
