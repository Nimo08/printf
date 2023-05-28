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
	int i = 0, num_chars = 0, write_val, write_val1, write_val2;
	char *s, c;

	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					c = (char)va_arg(args, int);
					write_val = write(STDOUT_FILENO, &c, 1);
					if (write_val < 0)
						return (-1);
					num_chars += write_val;
					break;
				case 's':
					s = va_arg(args, char *);
					if (s == NULL)
					{
						write(STDOUT_FILENO, "(NULL)", 6);
						num_chars += 6;
					}
					write_val = write(STDOUT_FILENO, s, strlen(s));
					if (write_val < 0)
						return (-1);
					num_chars += write_val;
					break;
				case '%':
					write_val = write(STDOUT_FILENO, "%", 1);
					if (write_val < 0)
						return (-1);
					num_chars += write_val;
					break;
				default:
					write_val1 = write(STDOUT_FILENO, &format[i - 1], 1);
					write_val2 = write(STDOUT_FILENO, &format[i], 1);
					if (write_val1 < 0 || write_val2 < 0)
						return (-1);
					num_chars += write_val1 + write_val2;
					break;
			}
		}
		else
		{
			write_val = write(STDOUT_FILENO, &format[i], 1);
			if (write_val < 0)
				return (-1);
			num_chars += write_val;
		}
		i++;
	}
	va_end(args);
	return (num_chars);
}
