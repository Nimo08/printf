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
		case 'c':
			return (_printf_char(args));
		case 's':
			return (_printf_string(args));
		case '%':
			return (_printf_percent());
		case 'd':
		case 'i':
			return (_printf_int(args));
		default:
			if (write(1, format - 1, 2) == -1)
				return (-1);
			return (2);
	}
}
