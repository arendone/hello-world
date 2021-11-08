#include "ft_printf.h"
#include <stdio.h>



int main(void)
{
    int value;
    ft_printf("-----------PRUEBA D-I-----------------\n");
	value=ft_printf("Quiero imprimir el numero %+04.0d por favor\n", 0);
    ft_printf("%d \n", value);
    value=printf("Quiero imprimir el numero %+04.0d por favor\n", 0);
    ft_printf("%d \n", value);
	value=ft_printf("Quiero imprimir el numero %2000.0008d, % 0.5d y %+11i \n", 42, 5, 13);
    ft_printf("%d \n", value);
    value=printf("Quiero imprimir el numero %2000.0008d, % 0.5d y %+11i \n", 42, 5, 13);
    ft_printf("%d \n", value);
    value=ft_printf("Quiero imprimir los numeros %+2d, %d y %.5d tambien\n", 42, 7, -4);
    ft_printf("%d \n", value);
    value=printf("Quiero imprimir los numeros %+2d, %d y %.5d tambien\n", 42, 7, -4);
    ft_printf("%d \n", value);
    value=ft_printf("Quiero imprimir los numeros % 4.3d, %3d y %-10d tambien\n", -42, 7, 4);
    ft_printf("%d \n", value);
    value=printf("Quiero imprimir los numeros % 4.3d, %3d y %-10d tambien\n", -42, 7, 4);
    ft_printf("%d \n", value);
	value=ft_printf("Quiero imprimir el numero %d, %03d, %04d por favor\n", 0, -14, -11);
    ft_printf("%d \n", value);
    value=printf("Quiero imprimir el numero %d, %03d, %04d por favor\n", 0, -14, -11);
    ft_printf("%d \n", value);
	value=ft_printf("Quiero imprimir el numero %.20d, %.2d, %.14d por favor\n", 16, -1, 4294967);
    ft_printf("%d \n", value);
    value=printf("Quiero imprimir el numero %.20d, %.2d, %.14d por favor\n", 16, -1, 4294967);
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
    ft_printf("--------------prueba %%--------------\n");
    value=ft_printf("Quiero imprimir la letra %3c, la cadena %25s, y la cadena %20.4s \n", 'A', "cadena", NULL);
    ft_printf("%d \n", value);
    value=printf("Quiero imprimir la letra %3c, la cadena %25s, y la cadena %20.4s \n", 'A', "cadena", NULL);
    ft_printf("%d \n", value);
    value=ft_printf("%% ....% %...%5%\n");
    ft_printf("%d \n", value);
    value=printf("%% ....% %...%5%\n");
    ft_printf("%d \n", value);
	ft_printf("--------------prueba x_X --------------\n");
    value=ft_printf("Quiero imprimir el num % #x en base x\n", 0);
    ft_printf("%d \n", value);
    value=printf("Quiero imprimir el num % #x en base x\n", 0);
    ft_printf("%d \n", value);
    value=ft_printf("Quiero imprimir el num %#x en base x\n", -9223372036854775);
    ft_printf("%d \n", value);
    value=printf("Quiero imprimir el num %#x en base x\n", -9223372036854775);
    ft_printf("%d \n", value);
	value=ft_printf("Quiero imprimir el num %#.5x en base x\n", 10);
    ft_printf("%d \n", value);
    value=printf("Quiero imprimir el num %#.5x en base x\n", 10);
    ft_printf("%d \n", value);
	ft_printf("--------------prueba p --------------\n");
    value=ft_printf("Quiero imprimir la direccion de value % p.\n", &value);
    ft_printf("%d \n", value);
	value=printf("Quiero imprimir la direccion de value % p.\n", &value);
    ft_printf("%d \n", value);
    value=ft_printf("Quiero imprimir la direccion de value %22p.\n", &value);
    ft_printf("%d \n", value);
    value=printf("Quiero imprimir la direccion de value %22p.\n", &value);
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