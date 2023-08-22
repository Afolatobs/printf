#include "main.h"

/**
*_printf - the function
*@format: the format string
*Return: an interger
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
write(1, &c, 1);
char_count++;
}
else if (*format == 's')
{
char *str = va_arg(args, char *);
for (len = 0; str[len]; len++)
write(1, &str[len], 1);
char_count += len;
}
else if (*format == '%')
{
write(1, format, 1);
char_count++;
}
}
else
{
write(1, format, 1);
char_count++;
}
format++;
}
va_end(args);
return (char_count);
}
