#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string containing the characters and the specifiers
 * Description: this function will call the get_print() function that will
 * determine which printing function to call depending on the conversion
 * specifiers contained into fmt
 * Return: length of the formatted output string
 */
int _printf(const char *format, ...)
{
	int (*ptr)(va_list, signals_t *);
	const char *p;
	va_list arguments;
	signals_t signals = {0, 0, 0};

	register int count = 0;

	va_start(arguments, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				count += putchar('%');
				continue;
			}
			while (get_signal(*p, &signals))
				p++;
			ptr = get_print(*p);
			count += (ptr)
				? pfunc(arguments, &signals)
				: _printf("%%%c", *p);
		} else
			count += putchar(*p);
	}
	putchar(-1);
	va_end(arguments);
	return (count);
}
