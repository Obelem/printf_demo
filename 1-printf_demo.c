#include <stdio.h>
#include <stdarg.h>

int my_putchar(int var, int count);

int _printf(const char *format, ...)
{
	va_list args;
	int i, dec, count = 0;

	va_start(args, format);
	
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%' && format[i - 1] != '%')
		{
			putchar(format[i]);
			count++;
		}	
		if (format[i] == '%' && format[i + 1] == 'd')
		{
			dec = va_arg(args, int);
			count = my_putchar(dec, count);
		}
		if (format[i] == '%' && format[i + 1] == 'i')
		{
			dec = va_arg(args, int);
			count = my_putchar(dec, count);
		}
	}
	putchar('\n');

	va_end(args);
	printf("count is: %d\n", count);
	return count;
}

//converts integer to character and counts it
//returns the value of count
int my_putchar(int var, int count) {
	/* print '-' for negative numbers */
	if (var < 0) 
	{
		putchar('-');
		var = var * -1;
		count++;
        }
	      
	/* Print Zero */
	if (var == 0)
	{
		putchar('0');
		count++;
	}
		  
	/* First remove the last digit of number and print 
	 *  the remaining digits using recursion, then print
	 *  the last digit
	 */
	if (var/10)
	{	
		count++;
		my_putchar(var/10, count);
	}

	putchar(var%10 + '0');
	count++;

	return count;
}

//driver code
int main(void)
{
	_printf("**%d**%i", 76, 98);
	return 0;
}
