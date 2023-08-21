#include "main.h"

int print_unsigned_common(va_list types, char buffer[], char map_to[], int flags, int width, int size)
{
    int i = BUFF_SIZE - 2;
    unsigned long int num = convert_size_unsgnd(va_arg(types, unsigned long int), size);
    if (num == 0)
        buffer[i--] = '0';
    buffer[BUFF_SIZE - 1] = '\0';
    while (num > 0)
    {
        buffer[i--] = map_to[num % 16];
        num /= 16;
    }
    i++;
    return write_unsgnd(0, i, buffer, flags, width, 0, size);
}

int print_unsigned(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    return print_unsigned_common(types, buffer, "0123456789", flags, width, size);
}

int print_octal(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    int i = BUFF_SIZE - 2;
    unsigned long int num = convert_size_unsgnd(va_arg(types, unsigned long int), size);
    if (num == 0)
        buffer[i--] = '0';
    buffer[BUFF_SIZE - 1] = '\0';
    while (num > 0)
    {
        buffer[i--] = (num % 8) + '0';
        num /= 8;
    }
    if (flags & F_HASH && num != 0)
        buffer[i--] = '0';
    i++;
    return write_unsgnd(0, i, buffer, flags, width, 0, size);
}

int print_hexadecimal_common(va_list types, char buffer[], char map_to[], int flags, int width, char flag_ch, int size)
{
    return print_unsigned_common(types, buffer, map_to, flags, width, size);
}

int print_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    return print_hexadecimal_common(types, buffer, "0123456789abcdef", flags, width, 'x', size);
}

int print_hexa_upper(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    return print_hexadecimal_common(types, buffer, "0123456789ABCDEF", flags, width, 'X', size);
}
