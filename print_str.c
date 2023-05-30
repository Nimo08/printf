#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * _printf_S - prints a string
 * @args: va_list containing args
 * Return: S
 */
int _printf_S(va_list args)
{
	char *S;
	int len = 0;
	char str1[3];
	char str2[];

	S = va_arg(args, char *);
	if (S == NULL)
		S = "(null)";
	while (S[len] != '\0')
	{
		if (S[len] < 32 || S[len] >= 127)
		{
			str1[3] = { '\\', 'x', '\0' };
			str2[] = "0123456789ABCDEF";
			str1[2] = str2[(S[len] >> 4) & 0x0F];
			if (write(1, str1, 2) == -1)
				return (-1);
			return (2);
			str1[2] = str2[S[len] & 0x0F];
			if (write(1, str1 + 2, 1) == -1)
				return (-1);
			return (1);
			len++;
		}
		else
		{
			if (write(1, &S[len], 1) == -1)
				return (-1);
			return (1);
			len++;
		}
	}
	return (len);
}
