#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * _printf_helper - print format specifiers
 * @format: character string
 * @args: va_list
 * Return: num_chars
 */
int _printf_helper(const char *format, va_list args)
{
	char op = format[0];

	switch (op)
	{
		case 'd':
		case 'i':
			return (_printf_int(args));
		default:
			return (-1);
	}
}
