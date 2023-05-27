#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
/**
 * _printf - prints char, string, %
 * @format: character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0;
	char c;
	char *n =  "(nil)";
	char *s;

	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				c = (char)va_arg(args, int);
				write(STDOUT_FILENO, &c, 1);
			}
			else if (format[i + 1] == 's')
			{
				s = va_arg(args, char *);
				if (s == NULL)
					write(STDOUT_FILENO, n, strlen(n));
				else
					write(STDOUT_FILENO, s, strlen(s));
			}
			else if (format[i + 1] == '%')
			{
				write(STDOUT_FILENO, "%", 1);
				i++;
			}
			else if (format[i] == '%')
			{
				write(STDOUT_FILENO, format + i, 1);
			}
			i++;
		}
		i++;
	}
	va_end(args);
	putchar('\n');
	return (0);
}
