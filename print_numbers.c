#include "main.h"

/**
 * _int - prints an integer
 * @l: va_list of arguments from _printf
 * @f: pointer to the struct flags determining
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int _int(va_list l, signals_t *f)
{
	int n = va_arg(l, int);
	int res = count_digit(n);

	if (f->space == 1 && f->plus == 0 && n >= 0)
		res += putchar(' ');
	if (f->plus == 1 && n >= 0)
		res += putchar('+');
	if (n <= 0)
		res++;
	_number(n);
	return (res);
}

/**
 * _unsigned - prints an unsigned integer
 * @l: va_list of arguments from _printf
 * @f: pointer to the struct flags determining
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int _unsigned(va_list l, signals_t *f)
{
	unsigned int u = va_arg(l, unsigned int);
	char *str = convert(u, 10, 0);

	(void)f;
	return (puts(str));
}

/**
 * _number - helper function that loops through
 * an integer and prints all its digits
 * @n: integer to be printed
 */
void _number(int n)
{
	unsigned int n1;

	if (n < 0)
	{
		putchar('-');
		n1 = -n;
	}
	else
		n1 = n;

	if (n1 / 10)
		_number(n1 / 10);
	putchar((n1 % 10) + '0');
}

/**
 * count_digit - returns the number of digits in an integer
 * for _printf
 * @i: integer to evaluate
 * Return: number of digits
 */
int count_digit(int i)
{
	unsigned int d = 0;
	unsigned int u;

	if (i < 0)
		u = i * -1;
	else
		u = i;
	while (u != 0)
	{
		u /= 10;
		d++;
	}
	return (d);
}
