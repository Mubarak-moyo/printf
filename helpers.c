#include "main.h"

int print_char(va_list args) {
    char temp_char = (char)va_arg(args, int);
    return write(1, &temp_char, 1);
}

int print_string(va_list args) {
    char *temp_str = va_arg(args, char *);
    return write(1, temp_str, strlen(temp_str));
}

int print_percent(void) {
    return write(1, "%", 1);
}
