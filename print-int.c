#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * _printf_int - prints %d %i
 * @args: va_list containing args
 * Return: num_int
 */
int _printf_int(va_list args)
{
	int ink, x;
	int num_int = 0, num_len = 0, is_neg = 0;
	char str_int[12];
	char *len1 = 0;
	
	ink = va_arg(args, int);
	if (ink == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		len1++;
		return (1);
	}
	if (ink < 0)
	{
		is_neg = 1;
		ink = -ink;
		num_int++;
	}
	while (ink != 0)
	{
		str_int[num_len] = (ink % 10) + '0';
		ink /= 10;
		num_len++;
	}
	if (is_neg)
	{
		str_int[num_len] = '-';
		num_len++;
	}
	x = num_len - 1;
	while (x >= 0)
	{
		if (write(1, &str_int[x], 1) == -1)
			return (-1);
		len1++;
		num_int++;
		x--;
	}
	return (num_int);
}
