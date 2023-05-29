#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * _printf - prints decimal, integer
 * @format: character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int x = 0, num_int = 0;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[x] != '\0')
	{
		if (format[x] == '%')
		{
			x++;
			switch (format[x])
			{
				case 'd':
					num_int += _printf_int(args);
					break;
				case 'i':
					num_int += _printf_int(args);
					break;
				default:
					if (write(1, &format[x - 1], 2) == -1)
						return (-1);
					num_int += 2;
					break;
			}
		}
		else
		{
			if (write(1, &format[x], 1) == -1)
				return (-1);
			num_int++;
		}
		x++;
	}
	va_end(args);
	return (num_int);
}
/**
 * _printf_int - prints %d, %i
 * @args: va_list containing %d, %i
 * Return: num_int
 */
int _printf_int(va_list args)
{
	int ink, i;
	int len = 0, is_neg = 0, num_len = 0;
	char str_int[12];
	char len1 = 0;

	ink = va_arg(args, int);
	if (ink == 0)
	{
		if (write(1, "0", 1) == -1)
		return (-1);
	len++;
	return (1);
	}
	if (ink < 0)
	{
		is_neg = 1;
		ink = -ink;
		num_len++;
	}
	while (ink != 0)
	{
		str_int[len] = (ink % 10) + '0';
		ink /= 10;
		len++;
	}
	if (is_neg)
	{
		str_int[len] = '-';
		len++;
	}
	for (i = len - 1; i >= 0; i--)
	{
		if (write(1, &str_int[i], 1) == -1)
			return (-1);
		len1++;
		num_len++;
	}
	return (num_len);
}
