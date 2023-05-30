#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * _printf_binary - prints %b
 * @args: va_list containing args
 * Return: ink
 */
int _printf_binary(va_list args)
{
	unsigned int bi;
	char buf[32];
	int ink, jum;

	bi = va_arg(args, unsigned int);
	if (bi == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	for (ink = 0; bi > 0; ink++)
	{
		buf[ink] = (bi % 2) + '0';
		bi /= 2;
	}
	for (jum = ink - 1; jum >= 0; jum--)
	{
		if (write(1, &buf[jum], 1) == -1)
			return (-1);
	}
	return (ink);
}

