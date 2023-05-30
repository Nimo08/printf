#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * _printf_un - prints %u
 * @args: va_list containing args
 * Return: len
 */
int _printf_un(va_list args)
{
	unsigned int ink;
	unsigned int tmp;
	int len = 0;
	char num_str[12];
	int num_index;

	ink = va_arg(args, unsigned int);
	if (ink == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	tmp = ink;
	while (tmp != 0)
	{
		tmp /= 10;
		len++;
	}
	num_index = len - 1;
	while (ink != 0)
	{
		num_str[num_index] = (ink % 10) + '0';
		ink /= 10;
		num_index--;
	}
	if (write(1, num_str, len) == -1)
		return (-1);
	return (len);
}
/**
 * _printf_octals - print %o
 * @args: va_list containing args
 * Return: len
 */
int _printf_octals(va_list args)
{
	unsigned int ink1;
	unsigned int tmp1;
	int len1 = 0;
	char num_str1[12];
	int num_index1;

	ink1 = va_arg(args, unsigned int);
	if (ink1 == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	while (tmp1 != 0)
	{
		tmp1 /= 8;
		len1++;
	}
	num_index1 = len1 - 1;
	while (ink1 != 0)
	{
		num_str1[num_index1] = (ink1 % 8) + '0';
		ink1 /= 8;
		num_index1--;
	}
	if (write(1, num_str1, len1) == -1)
		return (-1);
	return (len1);
}
/**
 * _printf_upper_hex - prints %X
 * @args: va_list containing args
 * Return: len
 */
int _printf_upper_hex(va_list args)
{
	unsigned int ink2;
	unsigned int tmp2;
	int len2 = 0;
	char num_str2[12];
	int num_index2;
	int rem;

	ink2 = va_arg(args, unsigned int);
	if (ink2 == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	while (tmp2 != 0)
	{
		tmp2 /= 16;
		len2++;
	}
	num_index2 = len2 - 1;
	while (ink2 != 0)
	{
		rem = ink2 % 16;
		if (rem < 10)
			num_str2[num_index2] = rem + '0';
		else
			num_str2[num_index2] = rem - 10 + 'A';
		ink2 /= 16;
		num_index2--;
	}
	if (write(1, num_str2, len2) == -1)
		return (-1);
	return (len2);
}
/**
 * _printf_lower_hex - prints %x
 * @args: va_list containing args
 * Return: len
 */
int _printf_lower_hex(va_list args)
{
	unsigned int ink3;
	unsigned int tmp3;
	int len3;
	char num_str3[12];
	int num_index3;
	int rem1;

	ink3 = va_arg(args, unsigned int);
	tmp3 = ink3;
	if (ink3 == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	while (tmp3 != 0)
	{
		tmp3 /= 16;
		len3++;
	}
	num_index3 = len3 - 1;
	while (ink3 != 0)
	{
		rem1 = ink3 % 16;
		if (rem1 < 10)
			num_str3[num_index3] = rem1 + '0';
		else
			num_str3[num_index3] = rem1 - 10 + 'a';
		ink3 /= 16;
		num_index3--;
	}
	if (write(1, num_str3, len3) == -1)
		return (-1);
	return (len3);
}
