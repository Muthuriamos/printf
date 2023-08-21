#include "main.h"

int print_char(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    char c = va_arg(types, int);
    return handle_write_char(c, buffer, flags, width, precision, size);
}

int print_string(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    char *str = va_arg(types, char *);
    if (str == NULL)
        str = (precision >= 6) ? "      " : "(null)";
    int length = 0;
    while (str[length] != '\0' && (precision < 0 || length < precision))
        length++;
    int padding = (width > length) ? width - length : 0;
    if (!(flags & F_MINUS))
        while (padding-- > 0)
            write(1, " ", 1);
    write(1, str, length);
    if (flags & F_MINUS)
        while (padding-- > 0)
            write(1, " ", 1);
    return (width > length) ? width : length;
}

int print_percent(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    UNUSED(types);
    UNUSED(buffer);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);
    return write(1, "%%", 1);
}

int print_int(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    int i = BUFF_SIZE - 2;
    int is_negative = 0;
    long int n = convert_size_number(va_arg(types, long int), size);
    if (n == 0)
        buffer[i--] = '0';
    buffer[BUFF_SIZE - 1] = '\0';
    unsigned long int num = (n < 0) ? ((-1) * n) : n;
    while (num > 0)
    {
        buffer[i--] = (num % 10) + '0';
        num /= 10;
    }
    i++;
    return write_number((n < 0), i, buffer, flags, width, precision, size);
}

int print_binary(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    unsigned int n = va_arg(types, unsigned int);
    unsigned int m = 2147483648;
    unsigned int a[32];
    int count = 0;
    for (int i = 0; i < 32; i++)
    {
        a[i] = (n / m) % 2;
        m /= 2;
    }
    for (int i = 0, sum = 0; i < 32; i++)
    {
        sum += a[i];
        if (sum || i == 31)
        {
            char z = '0' + a[i];
            write(1, &z, 1);
            count++;
        }
    }
    return count;
}
