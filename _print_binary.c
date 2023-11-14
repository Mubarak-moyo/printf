#include "main.h"

/**
 * print_binary - prints an unsigned integer in binary format.
 * @args: va_list of arguments.
 *
 * Return: Number of characters printed.
 */
int print_binary(va_list args)
{
	unsigned int digit = va_arg(args, unsigned int);
	int count = 0;
	int binary[32];
	int i = 0;

	if (digit == 0)
	{
	count += write(1, "0", 1);
	return (count);
	}

	while (digit > 0)
	{
	binary[i] = digit % 2;
	digit /= 2;
	i++;
	}

	for (i = i - 1; i >= 0; i--)
	{
	count += write(1, (binary[i] == 0) ? "0" : "1", 1);
	}

	return (count);
}
