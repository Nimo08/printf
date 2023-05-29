#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int _printf_char(va_list args);
int _printf_string(va_list args);
int _printf_percent(va_list args);
int _printf_int(va_list args);

#endif /*MAIN_H*/
