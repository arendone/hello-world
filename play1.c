#include <unistd.h>
#include <stdarg.h>

void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	printint(char *format, ...);
void	ft_putstr_fd(char *s, int fd);

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

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	printint(char *format, ...)
{
	va_list args;
	va_start(args, format);
	if (*(format + 1) == 'd')
	{
		int num = va_arg(args, int);
		ft_putnbr_fd(num, 1);
	}
	else if (*(format + 1) == 'c')
	{
		char c = (char) va_arg(args, int);
		ft_putchar_fd(c, 1);
	}
	else if (*(format + 1) == 's')
	{
		char *s = va_arg(args, char *);
		ft_putstr_fd(s, 1);
	}
	else
		write(1, "error", 5);
	va_end(args);
}



int main(void)
{
	printint("%d", 4563);
	printint("%c", 'f');
	printint("%d", 4563);
	printint("%s", "hola");
	return 0;
}