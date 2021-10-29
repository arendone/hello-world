#include "libftprintf.h"
#include <stdio.h>

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
            flags_characters(format, i , t_spec);
			while (ft_strchr("csdiupxX%", format[i]) == NULL)
				i++;
            //printf("- width: %d -", t_spec->width_details);
            //print according kind of variable
            if (format[i] == 'd')
	        {
                			//print according the flags
                if((t_spec->sign == true) && (t_spec->args >= 0))
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
                ft_print_char(format, i, t_spec);
			else if (format[i] == 's')
				ft_print_str(format, i, t_spec);
			i++;
            	//i = ft_print_str(format, i, t_spec);
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
	value=ft_printf("Quiero imprimir el numero %d por favor\n", 42);
    ft_printf("%d \n", value);
	value=ft_printf("Quiero imprimir el numero %d por favor y la letra %c y la letra %c tambien\n", 42, 's', 'Z');
    ft_printf("%d \n", value);
    value=ft_printf("Quiero imprimir los numeros %+d, %d y %d tambien\n", 42, 7, -4);
    ft_printf("%d \n", value);
    value=ft_printf("Quiero imprimir los numeros %d, %+d y %d tambien\n", 42, 7, -4);
    ft_printf("%d \n", value);
	ft_printf("----------------------------\n");
    value=printf("Quiero imprimir el numero %5d por favor\n", 42);
    ft_printf("%d \n", value);
	value=printf("Quiero imprimir el numero %d por favor y la letra %c y la letra %c tambien\n", 42, 's', 'Z');
    ft_printf("%d \n", value);
    value=printf("Quiero imprimir los numeros %+d, %+d y %+d tambien\n", 42, 7, -4);
    ft_printf("%d \n", value);
    value=printf("Quiero imprimir los numeros %d, %+d y %d tambien\n", 42, 7, -4);
    ft_printf("%d \n", value);
	ft_printf("-----------PRUEBA STR-----------------\n");
	value=printf("Quiero imprimir la cadena:%77s por favor\n", "HOLA");
    ft_printf("%d \n", value);
	value=ft_printf("Quiero imprimir la cadena:%77s por favor\n", "HOLA");
    ft_printf("%d \n", value);
	value=printf("Quiero imprimir la cadena:%.3s por favor\n", "HOLA");
    ft_printf("%d \n", value);
	value=ft_printf("Quiero imprimir la cadena:%.3s por favor\n", "HOLA");
    ft_printf("%d \n", value);
	value=printf("Quiero imprimir la cadena:%-33s por favor\n", "HOLA");
    ft_printf("%d \n", value);
	value=ft_printf("Quiero imprimir la cadena:%-33s por favor\n", "HOLA");
    ft_printf("%d \n", value);
	value=printf("Quiero imprimir la cadena:%10.2s por favor\n", "hola\0");
    ft_printf("%d \n", value);
	value=ft_printf("Quiero imprimir la cadena:%10.2s por favor\n", "hola\0");
    ft_printf("%d \n", value);
    value=printf("Quiero imprimir la cadena:%10.3s por favor\n", NULL);
    ft_printf("%d \n", value);
	value=ft_printf("Quiero imprimir la cadena:%10.3s por favor\n", NULL);
    ft_printf("%d \n", value);
    value=printf("Quiero imprimir la cadena:%.3s por favor\n", NULL);
    ft_printf("%d \n", value);
	value=ft_printf("Quiero imprimir la cadena:%.3s por favor\n", NULL);
    ft_printf("%d \n", value);
    ft_printf("----------------------------\n");
    value=ft_printf("Quiero imprimir la letra %3c por favor\n", 'A');
    ft_printf("%d \n", value);
    value=printf("Quiero imprimir la letra %3c por favor\n", 'A');
    ft_printf("%d \n", value);
    value=ft_printf("Quiero imprimir la letra %5c por favor\n", 'A');
    ft_printf("%d \n", value);
    value=printf("Quiero imprimir la letra %5c por favor\n", 'A');
    ft_printf("%d \n", value);
	return (0);
}

/*void	howisit(t_print *t_spec)
{
	if(t_spec->number == true)
		printf(" # is true ");
	if(t_spec->zero == true)
		printf(" 0 is true ");
	if(t_spec->dash == true)
		printf(" - is true ");
	if(t_spec->space == true)
		printf(" space is true ");
	if(t_spec->sign == true)
		printf(" sign is true ");
	if(t_spec->width == true)
		printf(" width is true ");
	if(t_spec->precision == true)
		printf(" precision is true ");	
}*/

//importante!!!!
//el valor que regresa la funcion cuenta qué? exactamente... es lo mismo imprimir 4 que 44 o deberia entonces contar 1 y 2?!!!!!
/*void	ft_print_char(t_print *t_spec, char c)
{
	if (t_spec->width && !t_spec->dash)
		ft_print_chars(t_spec, t_spec->pad_chr, t_spec->width - 1);
	t_spec->len_total += write(1, &c, 1);
	if (t_spec->width && t_spec->dash)
		ft_print_chars(t_spec, ' ', t_spec->width - 1);
}

void	ft_print_chars(t_print *t_spec, char c, int n)
{
	while (n > 0)
	{
		t_spec->len_total += write(1, &c, 1);
		n--;
	}
}*/