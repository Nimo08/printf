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
	int i = 0, num_chars = 0;
	char c;
	char *s;

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
					num_chars++;
					break;
				case 's':
					s = va_arg(args, char *);
					if (s == NULL)
					{
						write(STDOUT_FILENO, "(null)", 6);
						num_chars += 6;
					}
					write(STDOUT_FILENO, s, strlen(s));
					num_chars += strlen(s);
					break;
				case '%':
					write(STDOUT_FILENO, "%", 1);
					num_chars++;
					break;
				default:
					write(STDOUT_FILENO, "\n", 1);
					return (-1);
			}
			i++;
		}
		else
		{
			write(STDOUT_FILENO, &format[i], 1);
			num_chars++;
		}
		i++;
	}
	if (format[i] != '\0' && format[i] != 'c' && format[i] != 's' && format[i] != '%')
	{
		write(STDOUT_FILENO, "(NULL)", 6);
		
	}
	va_end(args);
	return (num_chars);
}
