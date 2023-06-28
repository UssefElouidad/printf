#include "main.h"
#include <stdarg.h>
#include <stddef.h>

/**
 * _printf - Produces output according to a format
 * @format: The format string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char *str;

	va_start(args, format);
	if (!format || !format[0])
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
					count += _putchar(va_arg(args, int));
			}
			else if (*format == 's')
			{
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(null)";
				count += _puts(str);
			}
			else if (*format == '%')
			{
					_putchar('%');
					count++;
			}
			else
			{
					_putchar('%');
					_putchar(*format);
					count += 2;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
/**
 * _puts - Writes a string to stdout
 * @str: The string to write
 *
 * Return: The number of characters written
 */
int _puts(char *str)
{
	int i = 0;

	if (str == NULL)
	{
		_puts("(null)");
		i += 6;
		return (i);
	}
	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}

	return (i);
}
