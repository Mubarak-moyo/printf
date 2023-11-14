#include "main.h"

/**
 * _printf - This is a custom printf function.
 * @format: This is the format string.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
	if (*format == '%')
	{
	format++;
	switch (*format)
	{
	case 'c':
		count += print_char(args);
		break;
	case 's':
		count += print_string(args);
		break;
	case '%':
		count += print_percent();
		break;
	default:
		count += write(1, "%", 1);
		count += write(1, format, 1);
		break;
	}
	}
	else
	{
		count += write(1, format, 1);
	}

		format++;
	}

	va_end(args);

	return (count);
}
