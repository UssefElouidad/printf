#include "main.h"
#include <stdarg.h>
#include <stddef.h>

/**
* _printf - Produces output according to a format
* @format: The format string
*
* Return: The number of characters printed
*/
int print_format(const char *format, va_list args)
{
	int count = 0;

	if (format == NULL || (format[0] == '%' && !format[1] == '\0'))
		return (-1);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					_putchar(va_arg(args, int));
					count++;
					break;
				case 's':
					count += _puts(va_arg(args, char *));
					break;
				
				case '%':
					_putchar('%');
					count++;
					break;
				default:
					_putchar('%');
					_putchar(*format);
					count += 2;
					break;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
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


