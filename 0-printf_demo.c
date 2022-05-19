#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int _printf(const char *format, ...)
{
	va_list args;
	char *str;
	char charac;
	int i, j;

	va_start(args, format);
	
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			charac = va_arg(args, int);
			putchar(charac);
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			str = va_arg(args, char *);
			for (j = 0; str[j] != '\0'; j++)
				putchar(str[j]);
		}
	}
	putchar('\n');
	va_end(args);
	return 0;
}
int main(void)
{
	_printf("%c %s %s", 'c', " a string", " my new text");
	return 0;
}
