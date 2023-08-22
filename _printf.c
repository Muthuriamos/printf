#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 *_putchar - Helper`function...
 * print_string - Prints a string of characters.
 * @c: character to be written
 * Return: on success, 1. On error, return -1.
*/
int _putchar(char c)
int _printf(const char *format, ...)
int print_string(va_list args)
int print_char(va_list args)
int main ()
{
	return (write(1, &c, 1));

	{
		*c = va_arg(args, int);
		return (_putchar(c));
	}

	{
		char *str = va_arg(args, char *);
		
		int printed = (0);
		
		while (*str)
		{
			printed += _putchar(*str);
			str++;
		}
		return (printed);
	}

	{
		int printed_chars = o;
		va_list args;

		va_start(args, format);
		while (*format) 
		{
			if (*format != '%')
				_putchar_chars += _putchar(*format);
		}
		else
		{
			format++;
			switch (*format)
			{
				case 'c':
					printed_chars += print_char(args);
					break;
				case 's':
					printed_char += print_string(args);
					break;
				case '%':
					printed_char += _putchar('%');
					break;
				case 'd':
				case 'i':
					break;
				case 'u':
					break;
				case 'o':
					break;
				case 'x':
					break;
				case 'p':
					break;
				default:
					printed_chars += _putchar('%');
					printed_chars += _putchar(*format);
					break;
			}
		}
		format++;
	}
	va_end(args);
	return (printed_chars);
}
int main ()

{
	int len = 12;
	char ch = 'H';
	char *str = "I am a string !";
	int negative = -762534;
	unsigned int uns = 2147484671;
	unsigned int octal = 20000001777;
	unsigned int hex = 0x800003FF;
	void *ptr = (void *)0x7ffe637541f0;

	_printf("Let's try to printf a simple sentence.\n");
	_printf("Length:[%d, %i]\n", len, len);
	_printf("Unsigned:[%u]\n", uns);
	_printf("Negative:[%d]\n", negative);
	_printf("Unsigned:[octal:[%o]\n", octal);
	_printf("Unsigned hexadecimal:[%x, %X]\n", hex, hex);
	_printf("Character:[%c]\n", ch);
	_printf("String:[%s]\n", str);
	_printf("Address:[%p]\n", ptr);
	_printf("Percent:[%%]\n",);
	_printf("Len:[%d]\n", len);
	_printf("Uknown:[%r]\n", "This is an unknown format\n");

	return (0);
}
