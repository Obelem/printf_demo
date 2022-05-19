#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...)
{
	va_list args;
	char *str;
	char chara;
	int i, j;

	/*The count variable counts the number characters printed*/
	va_start(args, format);
	
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			putchar(format[i]);
			continue;
		}
		if (format[i + 1] == '%')
		{
			putchar(format[i]);
			i++;
			continue;
		}
		if (format[i + 1] == 'c')
		{
			chara = va_arg(args, int);
			putchar(chara);
			i++;
			continue;
		}
		if (format[i + 1] == 's')
		{
			str = va_arg(args, char *);
			for (j = 0; str[j] != '\0'; j++)
				putchar(str[j]);
			i++;
		}
	}

	va_end(args);
	return 0;
}



/*
int main(void)
{
	_printf("Negative:[%d]\n", -762534);
	return 0;
}*/
