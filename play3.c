#include "libft.h"
#include <stdarg.h>
#include <stdio.h>

typedef struct s_print
{
    va_list args;
    char    sign;
    int     len_total;
}t_print;

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

t_print *ft_spec_init(t_print *t_spec)
{
    t_spec->sign = 0;
    t_spec->len_total = 0;
    return (t_spec);
}

t_print *ft_spec_reset(t_print *t_spec)
{
    t_spec->sign = 0;
    return (t_spec);
}

int ft_printf(char *format, ...)
{
	int           i;
    int       count;
	t_print *t_spec;
    t_spec = (t_print *)malloc(sizeof(t_print));
    if(!t_spec)
        return(-1);
    ft_spec_init(t_spec);
	
	va_start(t_spec->args, format);
	i = 0;
    count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
            i++;
            //check if we have flags
            if (format[i] == '+')
            {
                t_spec->sign = '+';
                i++;
            }
            //print according kind of variable
            if (format[i] == 'd')
	        {
                			//print according the flags
                if((t_spec->sign == '+') && (t_spec->args >= 0))
                    {
                        write(1, "+", 1);
                        t_spec->len_total++;
                    }
		        int num = va_arg(t_spec->args, int);
		        ft_putnbr_fd(num, 1);
                i++;
                //falta contar digitos
	        }
	        else if (format[i] == 'c')
	        {
		        char c = (char) va_arg(t_spec->args, int);
		        ft_putchar_fd(c, 1);
                count++;
                i++;
	        }
	        /*else
		        write(1, "error", 5);
			i =++;*/
            ft_spec_reset(t_spec);
		}
		else
		{
			count += write(1, &format[i], 1);
			i++;
		}
	}
    count += t_spec->len_total;
	va_end(t_spec->args);
    free(t_spec);
    return(count);
}


int main(void)
{
    int value;
	/*printint("%d", 4563);
	printint("%c", 'f');
	printint("%d", 4563);
	printint("%s", "hola");*/
	value=ft_printf("Quiero imprimir el numero %d por favor\n", 42);
    ft_printf("%d \n", value);
	value=ft_printf("Quiero imprimir la letra %c por favor\n", 'A');
    ft_printf("%d \n", value);
	value=ft_printf("Quiero imprimir el numero %d por favor y la letra %+c y la letra %c tambien\n", 42, 's', 'Z');
    ft_printf("%d \n", value);
    value=ft_printf("Quiero imprimir los numeros %+d, %+d y %+d tambien\n", 42, 7, -4);
    ft_printf("%d \n", value);
    value=ft_printf("Quiero imprimir los numeros %d, %+d y %d tambien\n", 42, 7, -4);
    ft_printf("%d \n", value);

    value=printf("Quiero imprimir el numero %d por favor\n", 42);
    ft_printf("%d \n", value);
	value=printf("Quiero imprimir la letra %c por favor\n", 'A');
    ft_printf("%d \n", value);
	value=printf("Quiero imprimir el numero %d por favor y la letra %+c y la letra %c tambien\n", 42, 's', 'Z');
    ft_printf("%d \n", value);
    value=printf("Quiero imprimir los numeros %+d, %+d y %+d tambien\n", 42, 7, -4);
    ft_printf("%d \n", value);
    value=printf("Quiero imprimir los numeros %d, %+d y %d tambien\n", 42, 7, -4);
    ft_printf("%d \n", value);
	return 0;
}

//importante!!!!
//el valor que regresa la funcion cuenta qué? exactamente... es lo mismo imprimir 4 que 44 o deberia entonces contar 1 y 2?!!!!!