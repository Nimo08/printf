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
	char *s;
	int count = 0;

	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
				case 'c':
					c = (char)va_arg(args, int);
					write(STDOUT_FILENO, &c, 1);
					count++;
					break;
				case 's':
					s = va_arg(args, char *);
					if (s[i] == '\0')
					{
						putchar('\n');
					}
					write(STDOUT_FILENO, s, strlen(s));
					count += strlen(s);
					break;
				case '%':
					write(STDOUT_FILENO, "%", 1);	
					count++;
					break;
				default:
					write(STDOUT_FILENO, format + i, 1);
					count++;
					break;
			}
			i++;
		}
		else
		{
			write(STDOUT_FILENO, format + i, 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
