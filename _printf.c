#include "main.h"

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    char temp_char;
    char *temp_str;

    va_start(args, format);

    while (*format)
	{
        if (*format == '%') {
            format++;
            if (*format == 'c') {
                temp_char = (char)va_arg(args, int);
                count += write(1, &temp_char, 1);
            } else if (*format == 's') {
                temp_str = va_arg(args, char *);
                count += write(1, temp_str, strlen(temp_str));
            } else if (*format == '%') {
                count += write(1, "%", 1);
            } else {
                count += write(1, "%", 1);
                count += write(1, format, 1);
            }
        } else {
            count += write(1, format, 1);
        }

        format++;
    }

    va_end(args);

    return count;
}
