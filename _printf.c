#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <limits.h>

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

	va_start(args, format);
	if (!format || !format[0])
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'c':
				count += print_char(va_arg(args, int));
				break;
			case 's':
				count += _puts(va_arg(args, char *));
				break;
			case '%':
				count += print_char('%');
				break;
			case 'd':
			case 'i':
				count += print_integer(va_arg(args, int));
			break;
			default:
				count += print_char('%');
				count += print_char(*format);
				break;
			}
		}
		else
			count += print_char(*format);
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

/**
 * print_char- printsba character
 *@c: character to print
 *Return: 1
 */

int print_char(int c)
{
	_putchar(c);
	return (1);
}

/**
 * print_integer - Prints a given integer
 * @num: integer to print
 * Return: Number count
 */
int print_integer(int num)
{
	int count = 0;

	if (num == -2147483648)
	{
		_putchar('-');
		_putchar('2');
		print_integer(147483648);
		return (1);
	}
	else if (num < 0)
	{
		_putchar('-');
		count++;
		num = -num;
	}
	if (num / 10)
	{
		count += print_integer(num / 10);
	}
	_putchar('0' + (num % 10));
	count++;

	return (count);
}
