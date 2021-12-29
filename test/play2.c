#include "libft.h"
#include <stdarg.h>

void	checkformat(char format, va_list args);

void	checkformat(char format, va_list args)
{
	if (format == 'd')
	{
		int num = va_arg(args, int);
		ft_putnbr_fd(num, 1);
	}
	else if (format == 'c')
	{
		char c = (char) va_arg(args, int);
		ft_putchar_fd(c, 1);
	}
	else
		write(1, "error", 5);
}

void	ft_printf(char *str, ...)
{
	int	i;
	va_list args;
	
	va_start(args, str);
	if (str == NULL)
		return ;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			//checkformat(str[i+1], args);
            if (str[i+1] == 'd')
	        {
		        int num = va_arg(args, int);
		        ft_putnbr_fd(num, 1);
	        }
	        else if (str[i+1] == 'c')
	        {
		        char c = (char) va_arg(args, int);
		        ft_putchar_fd(c, 1);
	        }
	        else
		        write(1, "error", 5);
			i = i + 2;
		}
		else
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	va_end(args);
}


int main(void)
{
	/*printint("%d", 4563);
	printint("%c", 'f');
	printint("%d", 4563);
	printint("%s", "hola");*/
	ft_printf("Quiero imprimir el numero %d por favor\n", 42);
	ft_printf("Quiero imprimir la letra %c por favor\n", 'A');
	ft_printf("Quiero imprimir el numero %d por favor y la letra %d y la letra %c tambien\n", 42, 7, 'Z');
    ft_printf("Quiero imprimir los numeros %d, %d y %d tambien\n", 42, 7, -4);
	return 0;
}