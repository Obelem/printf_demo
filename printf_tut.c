#include "main.h"

int _printf(const char *format, ...)
{
	va_list args;
	int i, count = 0;

	if (format == NULL)
		return -1;
	va_start(args, format);

	for (i = 0; format[i] != '\0': i++)
	{
		if (format[i] != '%')
		{
			putchar(format[i]);
			count++;
		}
		else
		{
			count = check_specifier(format, count, i, args);

			//if count is -1, break out of loop and return count
			if (count == -1)
				break;
			
			//helps ensure format character isn't printed
			i++;
		}
	}
	va_end(args);
	return count;
}
