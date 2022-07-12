#include "main.h"

/**
 * _string - loops through a string and prints
 * every character
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int _string(va_list l, signals_t *f)
{
	char *s = va_arg(l, char *);

	(void)f;

	if (!s)
		s = "(null)";
	return (puts(s));
}

/**
 * _char - prints a character
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int _char(va_list l, signals_t *f)
{
	(void)f;
	putchar(va_arg(l, int));
	return (1);
}
