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
	char *n;
	char *s;
	char *str0;
	char *str1;
	char *str2;
	char *str3;
	char *str4;
	char *str5;

	str0 = "Character:[";
	str1 = "]";
	str2 = "String:[";
	str3 = "]";
	str4 = "Percent:[";
	str5 = "]";
	n = "(nil)";
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				c = (char)va_arg(args, int);
				write(STDOUT_FILENO, str0, strlen(str0));
				write(STDOUT_FILENO, &c, 1);
				write(STDOUT_FILENO, str1, strlen(str1));
			}
			else if (format[i + 1] == 's')
			{
				s = va_arg(args, char *);
				write(STDOUT_FILENO, str2, strlen(str2));
				if (s == NULL)
				{
					write(STDOUT_FILENO, n, strlen(n));
				}
				else
				{
					write(STDOUT_FILENO, s, strlen(s));
				}
				write(STDOUT_FILENO, str3, strlen(str3));
			}
			else if (format[i + 1] == '%')
			{
				write(STDOUT_FILENO, str4, strlen(str4));
				write(STDOUT_FILENO, "%", 1);
				write(STDOUT_FILENO, str5, strlen(str5));
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
