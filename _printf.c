#include "main.h"

/**
 * _printf- Produces an output according to an input format
 *
 *@format: input format specifiers
 *
 * Return: Count
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	count = print_format(format, args);
	va_end(args);

	return (count);
}
