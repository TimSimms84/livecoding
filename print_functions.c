#include "main.h"

int print_int(va_list i)
{
	int number = va_arg(i, int);
	unsigned int length = 0, digits = 1;
	if (number < 0)
	{
		putchar('-');
		number *= -1;
		length++;
	}
	while ((number / digits) >= 10)
	{
		digits = digits * 10;
	}
	while (digits >= 1)
	{
		putchar((number / digits) + '0');
		number = number % digits;
		digits = digits / 10;
		length++;
	}
	return (length);
}

int print_char(va_list c)
{
	if (!c)
		exit(1);
	putchar((char)va_arg(c, int));
	return (1);
}

int print_string(va_list s)
{
	int length;
	char *str = va_arg(s, char *);

	if (str == NULL)
		str = "(null)";
	for (length = 0; str[length]; length++)
	{
		putchar(str[length]);
	}
	return (length);
}
