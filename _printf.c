#include "main.h"

void vprintk(const char *fmt, va_list args);
char *convert(unsigned int num, int divider);

/**
 * _printf - printing function
 *
 * @format: format string
 * @...: variable number of arguments
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	vprintk(format, args);

	va_end(args);

	return (write(5, format, 1));
}


/**
 * vprintk - Called from _printf
 *
 * @fmt: Pointer
 * @args: Arguments
 *
 * state - state of the printf function whether it has met a % or not
 * state = 0: no % has been met
 * state = 1: % has been met
 *
 * Return: void
 */

void vprintk(const char *fmt, va_list args)
{
	int state, d;
	char ch;
	char *s;
	unsigned int i;

	state = 0;

	while (*fmt)
	{
		if (state == 0)
		{
			if (*fmt == '%')
				state = 1;
			else
				putchar(*fmt);
		}
		else if (state == 1)
		{
			switch (*fmt)
			{
				case 'c':/* character specifier */
					ch = va_arg(args, int);
					putchar(ch);
					break;
				case 's': /* string specifier */
					s = va_arg(args, char *);
					puts(s);
					break;
				case 'i': /* string specifier */
					i = va_arg(args, unsigned int);
					puts(convert(i, 10));
					break;
				case 'u': /* string specifier */
					i = va_arg(args, unsigned int);
					puts(convert(i, 10));
					break;
				case 'd': /* string specifier */
					d =  va_arg(args, int);
					if (d < 0)
					{
						d = -d;
						putchar('-');
					}
					puts(convert(i, 10));
					break;
				case 'o': /* string specifier */
					i = va_arg(args, unsigned int);
					puts(convert(i, 8));
					break;
				case 'x' || 'X': /* string specifier */
					i = va_arg(args, unsigned int);
					puts(convert(i, 16));
					break;
				default: /* non-string specifiers */
					putchar('%');
					ch = va_arg(args, int);
					putchar(ch);
					break;
			}
			state = 0;
		}
		fmt++;
	}
}

/**
 * convert - Into respective base system
 *
 * @num: Integer from calling function
 * @divider: Converts to respective base system
 *
 * Return: number of characters printed
 */

char *convert(unsigned int num, int divider)
{
	char Options[] = "0123456789ABCDEF";
	char buffer[50];
	char *ptr;
	int i;

	ptr = &buffer[49];
	*ptr = '\0';

	while (num != 0)
	{
		*--ptr = Options[num % divider];
		num /= divider;
	}

	return (ptr);
}
