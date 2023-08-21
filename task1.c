#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * main - Entry point
 * _printf - The custom print function that handles %d and %i specifiers
 * @format: The format string containing zero or more directives
 * Return: The number of characters prnted
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int num = va_arg(args, int);

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%' && *(format + 1) == 'd')
		{
			printf("%d", num);
			count++;
			format += 2;
		}
	}
	if (*format == '%' && *(format + 1) == 'i')
	{

		printf("%i", num);
		count++;
		format += 2;
	}
	else
	{
		putchar(*format);
		count++;
		format++;
	}
	{
		va_end(args);
		return (count);
	}
}

int main(void)
{
	int m = 42;
	int n = -123;
	int p = 789;

	int printed = _printf("This is a test: %d, %i, %d\n", m, n, p);

	printf("characters printed: %d\n", printed);

	return (0);

}
