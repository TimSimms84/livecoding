#include "main.h"

int (*specifiercheck(const char *format))(va_list)
{
	unsigned int i;
	specifier p[] = {
		{"c", print_char},
		{"s", print_string},
		{"i", print_int},
		{"d", print_int},
		{NULL, NULL}
	};
	if (!format)
		exit(99);
	for (i = 0; p[i].spec != NULL; i++)
	{
		if (*(p[i].spec) == *format)
		{
			break;
		}
	}
	return (p[i].f);
}


int _printf(const char *format, ...)
{
	va_list ap;
	unsigned int i = 0, length = 0;
	int (*f)(va_list);

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(ap, format);
	while (format[i])
	{
		for (; format[i] != '%' && format[i]; i++)
		{
			putchar(format[i]);
			length++;
		}
		if (!format[i])
			return (length);
		if (format[i + 1] == '%')
		{
			putchar('%');
			i += 2;
			length += 1;
		}
		if (format[i + 1] == '\0')
		{
			i++;
			continue;
		}
		else
		{
			f = specifiercheck(&format[i + 1]);
			if (!f)
			{
				putchar(format[i]);
				putchar(format[i + 1]);
				i += 2;
				length += 2;
			}
			if (f)
			{
				length += f(ap);
				i += 2;
			}
		}
	}
		va_end(ap);
		return (length);

}
