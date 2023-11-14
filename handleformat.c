#include "main.h"

/**
 * handle_format - Handles the format specifier.
 * @format: Format string.
 * @args: A va_list of arguments.
 * @count: Pointer to the count of characters printed.
 *
 * Return: Number of characters printed.
 */
int handle_format(const char *format, va_list args, int *count)
{
	switch (*format)
	{
	case 'c':
	return (print_char(args));
	case 's':
	return (print_string(args));
	case '%':
	return (print_percent());
	case 'd':
	case 'i':
	return (print_int(args, count));

	default:
	write(1, "%", 1);
	write(1, format, 1);
	return (2);
	}
}
