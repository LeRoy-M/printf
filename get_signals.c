#include "main.h"

/**
 * get_signal - turns on signals if any
 *
 * @s: character that holds the signals specifier
 * @f: pointer to the struct signals
 *
 * Return: 1 if a flag has been turned on, 0 otherwise
 */
int get_signal(char s, signals_t *f)
{
	int i = 0;

	switch (s)
	{
		case '+':
			(*f).plus = 1;
			i = 1;
			break;
		case ' ':
			(*f).space = 1;
			i = 1;
			break;
		case '#':
			(*f).hash = 1;
			i = 1;
			break;
	}

	return (i);
}
