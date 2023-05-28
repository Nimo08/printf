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

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					num_chars += _printf_char(args);
					break;
				case 's':
					num_chars += _printf_string(args);
					break;
				case '%':
					num_chars += _printf_percent(args);
					break;
				default:
					if (write(STDOUT_FILENO, &format[i - 1], 1) == -1)
						return (-1);
					num_chars++;
					if (write(STDOUT_FILENO, &format[i], 1) == -1)
						return (-1);
					num_chars++;
					break;
			}
		}
		else
		{
			if (write(STDOUT_FILENO, &format[i], 1) == -1)
				return (-1);
			num_chars++;
		}
		i++;
	}
	va_end(args);
	return (num_chars);
}
/**
 * _printf_char - prints char
 * @args: va_list containing char
 * Return: num_chars
 */
int _printf_char(va_list args)
{
	char c;

	c = (char)va_arg(args, int);
	if (write(STDOUT_FILENO, &c, 1) == -1)
		return (-1);
	return (1);
}
/**
 * _printf_string - prints string
 * @args: va_list containing string
 * Return: num_chars
 */
int _printf_string(va_list args)
{
	char *s;
	int len = 0;

	s = va_arg(args, char *);
	if (s == NULL)
	{
		return (0);
	}
	while (s[len] != '\0')
	{
		len++;
	}
	if (write(STDOUT_FILENO, s, len) == -1)
		return (-1);
	return (len);
}
/**
 * _printf_percent - prints %
 * @args: va_list
 * Return: num_chars
 */
int _printf_percent(va_list args)
{
	(void) args;
	if (write(STDOUT_FILENO, "%", 1) == -1)
		return (-1);
	return (1);
}
