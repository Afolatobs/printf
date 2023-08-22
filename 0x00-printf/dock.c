#include "main.h"

/**
 * _printf - variadic function
 * @format: paramater
 * Return: 0
 */

int _printf(const char *format, ...)
{
	int format_style, str_len = 0;

	va_list format_punch;
		if (format == NULL)
			return (-1);
	va_start(format_punch, format);
		for (; *format; format++)
		{
			if (*format != '%')
			{
				write(1, format, 1);
					format_style++;
			}
			else
			{
				format++;
				if (*format == '\0')
					break;
				else if (*format == '%')
				{
					write(1, format, 1);
						format_style++;
				}
				else if (*format == 'c')
				{
					char c = va_arg(format_punch, int);
						write(1, &c, 1);
				}
				else if (*format == 's')
				{
				char *form = va_arg(format_punch, char*);
					for (str_len = 0 ; form[str_len] != '\0' ; str_len++)
						write(1, form, str_len);
							format_style += str_len;
								format_style++;
				}
			}
		}	format++;
	va_end(format_punch);
	return (format_style);
}

/**
 *main - function to printfs
 *Return: 0
 */
int main(void)
{
	printf("femi\n");
	printf("%c\n", 'V');
	printf("%s\n", "string");
	printf("%%\n");
	return (0);
}
