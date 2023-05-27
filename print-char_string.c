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
	const char *s;
	
	if (format == NULL)
	{
		return (-1);
	}
	va_start(args, format);
	while (format[i] != '\0' && format != NULL)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					c = (char)va_arg(args, int);
					if (write(STDOUT_FILENO, &c, 1) < 0)
					{
						return (-1);
					}
					num_chars++;
					break;
				case 's':
					s = va_arg(args, const char *);
					if (s == NULL)
					{
						if (write(STDOUT_FILENO, "(NULL)", 6) < 0)
						{
							return (-1);
						}
						num_chars += 6;
					}
					else
					{
					    if (write(STDOUT_FILENO, s, strlen(s)) < 0)
						{	
							return (-1);
						}
					}
					num_chars += strlen(s);
					break;
				case '%':
					if (write(STDOUT_FILENO, "%", 1) < 0)
					{
						return (-1);
					}
					num_chars++;
					break;
				default:
					write(STDOUT_FILENO, &format[i - 1], 2);
                                        num_chars += 2;
					break;
			}
		}
		else
		{
			if (write(STDOUT_FILENO, &format[i], 1) < 0)
			{
				return (-1);
			}
			num_chars++;
		}
		i++;
	}
	va_end(args);
	return (num_chars);
}
