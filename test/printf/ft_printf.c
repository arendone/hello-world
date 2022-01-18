



#include <stdarg.h>
#include <unistd.h>

int ft_printf(const char *str, ...)
{
	int i;
	va_list ap;

	i = 0;
	va_start(ap, str);
	while 

}

static void ft_x(unsigned int x, int *ret)
{
	char *base = "0123456789abcdef";

	if(x > 16)
	{
		ft_x(x / 16, ret);
		x = x % 16;
	}
	*ret += write(1, &base[x], 1);
}
