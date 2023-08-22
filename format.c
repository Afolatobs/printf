#include "main.h"

/**
 * _printf - the function
 * @format: the format string
 * Return: an integer
 * @args: the argument list
 */
int print_formatted_string(const char *format, va_list args);

int _printf(const char *format, ...)
{
int char_count = 0;
va_list args;
va_start(args, format);

char_count = print_formatted_string(format, args);

va_end(args);
return (char_count);
}

/**
 * print_formatted_string - prints the formatted string
 * @format: the format string
 * @args: arguments for format specifiers
 * Return: the number of characters printed
 */
int print_formatted_string(const char *format, va_list args)
{
int char_count = 0;

while (*format)
{
if (*format != '%')
{
_putchar(*format);
char_count++;
}
else
{
format++;
if (*format == '\0')
break;
if (*format == 'c')
{
int c = va_arg(args, int);
_putchar(c);
char_count++;
}
else if (*format == 's')
{
char *str = va_arg(args, char *);
while (*str)
{
_putchar(*str);
char_count++;
str++;
}
}
else if (*format == '%')
{
_putchar('%');
char_count++;
}
}
format++;
}
return (char_count);
}
