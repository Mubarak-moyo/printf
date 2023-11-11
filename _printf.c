#include "main.h"
#include <stdio.h>

/**
 * _printf - Custom printf function
 * @format: Format string
 * Return: Number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%' && (*(format + 1) == 'c' || *(format + 1) == 's'))
        {
            format++; /* Move past '%' */
            switch (*format)
            {
            case 'c':
                count += putchar(va_arg(args, int));
                break;
            case 's':
                count += puts(va_arg(args, char *));
                break;
            default:
                count += putchar('%'); /* Handle '%%' */
                break;
            }
        }
        else
        {
            count += putchar(*format);
        }

        format++;
    }

    va_end(args);

    return count;
}

