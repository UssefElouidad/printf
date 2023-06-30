#include "main.h"

/**
 * print_integer - Prints a given integer
 * @num: integer to print
 * Return: Number count
 */
static int print_integer(int num)
{
	int count = 0;

	if (num < 0)
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

/**
 * print_format- Prints a given format
 * @format: Character string
 * @args: List of all arguments
 * Return: Count.
 */

int print_format(const char *format, va_list args)
{
	int count = 0;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'd':
				case 'i':
					count += print_integer(va_arg(args, int));
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
