#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>

int _printf(const char *format, ...);

/**
 * struct signals - struct for checking the following
 *
 * @plus: '+'
 * @space: ' '
 * @hash: '#'
 */

typedef struct signals
{
	int plus;
	int space;
	int hash;
} signals_t;

/**
 * struct printHandler - struct for function decision
 *
 * @c: Specifies format
 * @f: Pointer
 */

typedef struct printHandler
{
	char c;
	int (*f)(va_list ap, signals_t *f);
} ph;

int (*get_print(char s))(va_list, signals_t *);
char *convert(unsigned long int num, int base, int lowercase);
int _int(va_list l, signals_t *f);
void _number(int n);
int print_unsigned(va_list l, signals_t *f);
int count_digit(int i);
int _hex(va_list l, signals_t *f);
int _hex_big(va_list l, signals_t *f);
int _binary(va_list l, signals_t *f);
int _octal(va_list l, signals_t *f);
int get_signal(char s, signals_t *f);
int _string(va_list l, signals_t *f);
int _char(va_list l, signals_t *f);
int _rot13(va_list l, signals_t *f);
int _rev(va_list l, signals_t *f);
int _bigS(va_list l, signals_t *f);
int _address(va_list l, signals_t *f);
int _percent(va_list l, signals_t *f);

#endif /* MAIN_H */
