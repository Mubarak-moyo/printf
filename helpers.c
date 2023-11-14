#include "main.h"

/**
 * print_char - Function that prints a chracter.
 * @args: va_list of arguments.
 *
 * Return: The number of characters printed.
 */
int print_char(va_list args)
{
	char temp_char = (char)va_arg(args, int);

	return (write(1, &temp_char, 1));
}

/**
 * print_string - Function that prints a string.
 * @args: This is the va_list of arguments.
 *
 * Return: The number of characters printed.
 */
int print_string(va_list args)
{
	char *temp_str = va_arg(args, char *);

	return (write(1, temp_str, strlen(temp_str)));
}

/**
 * print_percent - Function that prints percent.
 *
 * Return: The number of characters printed.
 */
int print_percent(void)
{
	return (write(1, "%", 1));
}

/**
 * print_int - prints an integer.
 * @args: va_list of arguments.
 * Return: NUmber of characters printed.
 */
int print_int(va_list args)
{
	int digit = va_arg(args, int);
	char buffer[12];
	int count = 0;

	count = sprintf(buffer, "%d", digit);
	write(1, buffer, count);

	return (count);
}
