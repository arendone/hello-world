#include "ft_printf.h"
#include <limits.h>

int main(void)
{
	int res;
	char	*str = "Hello 42Heilbronn";
	int		d = -2147483648;
	int		x = 0xABcc45;

	res =ft_printf("%x\n", 16);
	printf("%d", res);
	res =printf("%x\n", 16);
	printf("%d", res);
	//ft_printf("%p", 16);
	//printf("%p", 0x00000016);
	//ft_printf(" Ret: %d \n", ft_printf("%s", str));
	//ft_printf(" Ret: %d \n", ft_printf("%d", d));
	//ft_printf(" Ret: %d \n", ft_printf("%x", x));
	//ft_printf(" Ret: %d \n", ft_printf("%p", &str));
	//ft_printf(" Ret: %d \n", ft_printf("%p", &d));
	//printf(" Ret: %d \n", printf("%s", str));
	//printf(" Ret: %d \n", printf("%d", INT_MAX));
	//printf(" Ret: %d \n", printf("%x", x));
	//printf(" Ret: %d \n", printf("%p", &str));
	//printf(" Ret: %d \n", printf("%p", &d));

	return 0;	
}