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
		case 'b':
			return (_printf_binary(args));
		case 'u':
			return (_printf_un(args));
		case 'o':
			return (_printf_octals(args));
		case 'X':
			return (_printf_upper_hex(args));
		case 'x':
			return (_printf_lower_hex(args));
		case 'S':
			return (_printf_S(args));
		default:
			if (write(1, format - 1, 2) == -1)
				return (-1);
			return (2);
	}
}
