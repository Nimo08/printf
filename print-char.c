#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * _printf_char - prints char
 * @args: va_list containing char
 * Return: num_chars
 */
int _printf_char(va_list args)
{
	char c;

	c = (char)va_arg(args, int);
	if (write(1, &c, 1) == -1)
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
		s = "(null)";
	}
	while (s[len] != '\0')
	{
		len++;
	}
	if (write(1, s, len) == -1)
		return (-1);
	return (len);
}
/**
 * _printf_percent - prints %
 * Return: num_chars
 */
int _printf_percent(void)
{
	if (write(1, "%", 1) == -1)
		return (-1);
	return (1);
}

