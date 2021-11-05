#include <unistd.h>
#include <stdarg.h>

void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	checkformat(char format, va_list args);
void	ft_putstr_fd(char *s, int fd);
void	ft_printf(char *str, ...);

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	d;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	i = 0;
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * (-1);
	}
	if (n <= 9)
	{
		d = '0' + n;
		write(fd, &d, 1);
	}
	else
	{
		ft_putnbr_fd(((n - (n % 10)) / 10), fd);
		d = '0' + (n % 10);
		write(fd, &d, 1);
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

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
			checkformat(str[i+1], args);
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
	ft_printf("Quiero imprimir el numero %d por favor y la letra %c y la letra %c tambien\n", 42, 'A', 'Z');
	return 0;
}