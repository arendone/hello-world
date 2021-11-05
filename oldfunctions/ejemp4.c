#include <stdio.h>
#include <stdarg.h>

int	FindMax(int n, ...)
{
	int	i;
	int	val;
	int	largest;
	va_list	vl;
	va_start(vl,n);
	largest = va_arg(vl, int);
	for(i = 1; i < n; i++)
	{
		val = va_arg(vl, int);
		largest = (largest > val)?largest:val;
	}
	va_end(vl);
	return (largest);
}

int main ()
{
	int m;
	m = FindMax(7,45,-56,45,56,0,33,111);
	printf("The largest value is: %d\n",m);
	return 0;
}