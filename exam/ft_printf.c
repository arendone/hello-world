#include "ft_printf.h"
#include <limits.h>

 /*
static size_t	num_digits(int n, int base)
{
	size_t	digits;

	digits = 1;
	while (n / base)
	{
		digits++;
		n /= base;
	}
	return (digits);
}*/

static int printf_s(char *s)
{
	int ret;
	int i;

	ret = 0;
	i = 0;

	if (s == NULL)
		return (write(1, "(null)", 6));

	while(s[i])
	{
		ret += write(1, &s[i], 1);
		i++;
	}
	return ret;

}

static void printf_d(int d, int *ret)
{
	char nbr;

	if (d == -INT_MIN)
	{
		*ret += write(1, "-2147483648", 11 );
		return ;
	}
	if ( d < 0)
	{
		*ret += write(1, "-", 1);
		d *= (-1);
	}
	if( d / 10)
		printf_d(d/10, ret);
	nbr = '0' + d % 10;
	*ret += write(1, &nbr, 1);
	return ;
}

static void printf_x(unsigned int x, int *ret)
{
	char *base = "0123456789abcdef";

	if(x > 15)
	{
		printf_x(x / 16, ret);
		x = x % 16;
	}
	*ret += write(1, &base[x], 1);
}

static void printf_p(unsigned long ptr, int *ret)
{
	char *base = "0123456789abcdef";

	if(ptr > 15)
	{
		printf_p(ptr / 16, ret);
		ptr = ptr % 16;
	}
	*ret += write(1, &base[ptr], 1);
}

int ft_printf(const char *fmt, ...)
{
	int i;
	int ret;
	va_list ap;
	char *s;
	int d;
	unsigned int x;
	char c;
	unsigned long ptr;

	ret = 0;
	i = 0;
	va_start(ap, fmt);
	while (fmt[i])
	{
		if( fmt[i] != '%')
		{
			ret += write(1, &fmt[i], 1);
		}
		else{
			i++;

			if (fmt[i] == 'c')
			{
				c = (char)va_arg(ap, int);
				ret += write(1,&c, 1);
			}
			if(fmt[i] == 's')
			{
				s = va_arg(ap, char *);
				ret += printf_s(s);
			}
			if(fmt[i] == 'd' || fmt[i] == 'i')
			{
				d = va_arg(ap, int);
				//if (d < 0)
				//	ret++;
				//ret += num_digits(d, 10);			
				printf_d(d, &ret);
			}

			if(fmt[i] == 'x')
			{
				x = va_arg(ap, unsigned int);
				//ret += num_digits(x, 16);
				printf_x(x, &ret);
			}
			if(fmt[i] == 'p')
			{
				ptr = (unsigned long)va_arg(ap, void *);
				if (ptr == 0)
					ret += write(1, "0x0", 3);
				else
				{
					ret += write(1, "0x", 2);
					//ret += 12;
					printf_p(ptr, &ret);
				}				
			}
			if(fmt[i] == '%')
			{
				ret += write(1,"%", 1);
			}			
		}
		i++;

	}	
	va_end(ap);
	return ret;
}