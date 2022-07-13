#include "main.h"

/**
 * get_print - selects the right printing function
 * depending on the conversion specifier passed to _printf
 * @s: character that holds the conversion specifier
 * Description: the function loops through the structs array
 * func_arr[] to find a match between the specifier passed to _printf
 * and the first element of the struct, and then the approriate
 * printing function
 * Return: a pointer to the matching printing function
 */
int (*get_print(char s))(va_list, signals_t *)
{
	ph func_arr[] = {
		{'i', _int},
		{'s', _string},
		{'c', _char},
		{'d', _int},
		{'u', _unsigned},
		{'x', _hex},
		{'X', _hex_big},
		{'b', _binary},
		{'o', _octal},
		{'R', _rot13},
		{'r', _rev},
		{'S', _bigS},
		{'p', _address},
		{'%', _percent}
		};
	int signals = 14;

	register int i;

	for (i = 0; i < signals; i++)
		if (func_arr[i].c == s)
			return (func_arr[i].f);
	return (NULL);
}
