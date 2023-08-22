#include "main.h"

/**
 * _printf - the function
 * @format: the format string
 * Return: an integer
 */
int _printf(const char *format, ...)
{
int len, char_count = 0;
va_list args;
va_start(args, format);

while (*format)
{
if (*format == '%')
{
format++;
if (*format == '\0')
break;
if (*format == 'c')
{
char c = va_arg(args, int);
_putchar(c);
char_count++;
}
else if (*format == 's')
{
char *str = va_arg(args, char *);
for (len = 0; str[len]; len++)
_putchar(str[len]);
char_count += len;
}
else if (*format == '%')
{
_putchar('%');
char_count++;
}
}
else
{
_putchar(*format);
char_count++;
}
format++;
}
va_end(args);
return (char_count);
}
