#ifndef MAIN_H
#define MAIN_H

#include<stdarg.h>

int _putchar(char c);
int _printf(const char *format, ...);
int _puts(char *str);
int print_format(const char *format, va_list args);
int print_format_c_s(const char *format, va_list args);

#endif
