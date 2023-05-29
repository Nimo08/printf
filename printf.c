#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
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
			num_chars += _printf_helper(&format[i], args);
			switch (format[i])
			{
				case 'c':
					num_chars += _printf_char(args);
					break;
				case 's':
					num_chars += _printf_string(args);
					break;
				case '%':
					num_chars += _printf_percent();
					break;
				default:
					if (write(1, &format[i - 1], 2) == -1)
						return (-1);
					num_chars += 2;
					break;
			}
		}
		else
		{
			if (write(1, &format[i], 1) == -1)
				return (-1);
			num_chars++;
		}
		i++;
	}
	va_end(args);
	return (num_chars);
}
