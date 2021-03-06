#include <stdio.h>
#include <stdarg.h>

void print_ints(int num, ...)
{
	va_list args;
	va_start(args, num);

	for(int i=0; i < num; i++)
	{
		int value = va_arg(args, int);
		printf("%d: %d\n", i, value);
	}
	va_end(args);
}

int main()
{
	print_ints(3, 24, 26, 312);
	print_ints(2, 256, 512);
	print_ints(7, 2, 26, 312, 34, 245, 90, 45);
}