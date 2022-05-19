#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int _printf(const char *format, ...)
{
	va_list args;
	char *str;
	char charac;
	int i, j, count = 0;

	//The count variable counts the number characters printed
	va_start(args, format);
	
	for (i = 0; format[i] != '\0'; i++)
	{
		// Prints characters not associated with format specifiers	
		if (format[i] != '%' && format[i - 1] != '%')
		{
			putchar(format[i]);
			count++;
		}
		//Prints characters
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			charac = va_arg(args, int);
			putchar(charac);
			count++;
		}
		//Prints strings
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			str = va_arg(args, char *);
			for (j = 0; str[j] != '\0'; j++)
			{	
				putchar(str[j]);
				count++;
			}

		}
	}
	putchar('\n');
	va_end(args);
	return count;
}
int main(void)
{
	_printf("%cprint function %s", 'f', " four");
	return 0;
}
