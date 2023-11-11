#include "main.h"

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
		{
		char temp = (char)va_arg(args, int);
                count += write(1, &temp, 1);
                break;
		}
            case 's':
                count += write(1, va_arg(args, char *), 1);
                break;
            default:
                count += write(1, "%", 1); /* Handle '%%' */
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

    return count;
}

