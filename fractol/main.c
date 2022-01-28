/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:01:25 by arendon-          #+#    #+#             */
/*   Updated: 2022/01/28 19:34:55 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//gcc main.c -L ./mlx/ -lmlx -framework OpenGL -framework AppKit -o magic 

void	my_mlx_pixel_put(t_info *fr, int x, int y, int color)
{
	char	*dst;

	dst = fr->addr + (y * fr->line_length
			+ x * (fr->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	init_window(t_info *fr)
{
	fr->mlx = mlx_init();
	fr->img_width = 1024;
	fr->img_height = 768;
	fr->win = mlx_new_window(fr->mlx, fr->img_width,
			fr->img_height, "Fract-ol");
	fr->img = mlx_new_image(fr->mlx, fr->img_width,
			fr->img_height);
	fr->addr = mlx_get_data_addr(fr->img, &fr->bits_per_pixel,
			&fr->line_length, &fr->endian);
	plot_window(fr); //julia
	//plot_window2(fr); //mandelbrot
}


void	plot_window(t_info *fr)
{
	//ft_printf("Plot %s. k_re\n", fr->fr_set);
	//mandelbrot(fr);
	julia(fr);
	//plot_fr(fr); //mandelbrot(fr)
	mlx_put_image_to_window(fr->mlx, fr->win, fr->img, 0, 0);
}

void	plot_window2(t_info *fr)
{
	//ft_printf("Plot %s. k_re\n", fr->fr_set);
	//mandelbrot(fr);
	mandelbrot(fr);
	//plot_fr(fr); //mandelbrot(fr)
	mlx_put_image_to_window(fr->mlx, fr->win, fr->img, 0, 0);
}

int	compare(char *s1, char *s2, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		if (s1[i] < s2[i])
			return (-1);
		else if (s1[i] > s2[i])
			return (1);
		else
			i++;
	}
	return (0);
}

int	control_name(char *name, t_info *fr)
{
	size_t	i;
	int		ret;

	ret = -1;
	if (name != NULL)
	{
		i = 0;
		while (name[i] != '\0')
			i++;
		if (i == 10)
			ret = compare(name, "Mandelbrot", 10);
		else if (i == 5)
			ret = compare(name, "Julia", 5);
		else if (i == 4)
			ret = compare(name, "Tree", 4);
	}
	if (ret == 0)
	{
		fr->name_fr = name[0];
		return (0);
	}
	return (ret);
}

int	control_color(char *color, t_info *fr)
{
	size_t	i;
	int		ret;

	ret = -1;
	if (color != NULL)
	{
		i = 0;
		while (color[i] != '\0')
			i++;
		if (i == 10)
			ret = compare(color, "pyscho", 6);
		else if (i == 5)
			ret = compare(color, "fuego", 5);
		else if (i == 4)
			ret = compare(color, "lila", 4);
	}
	if (ret == 0)
	{
		fr->color = color[0];
		return (0);
	}
	return (ret);
}

/*setting default values for Maxint, color, const K*/
/*evaluate and add the arg info to the t_info */
int	init_t_info(t_info *fr, int arg, char **str)
{
	int	ret;

	fr->Maxint = 30;
	fr->name_fr = 'N';
	fr->color = 'F';
	fr->K_re = .353;
	fr->K_im = .288;
	
	ret = -1;
	if (arg > 1)
		ret = control_name(&str[1][0], fr);
	if (arg > 2 && ret == 0)
		ret = control_color(&str[2][0], fr);
	//if (arg > 3) & 4
		//get the values of K
		//more arg are ignored
	return (ret);
}

int	main(int arg, char **str)
{
	t_info	*fr;
	int		ret;

	fr = (t_info *)malloc(sizeof(t_info));
	if (!fr)
		return (-1);
	ret = init_t_info(fr, arg, str);
	if (ret == 0)
	{
		init_window(fr);
		mlx_key_hook(fr->win, deal_key, fr);
		mlx_loop(fr->mlx);
	}
	else
	{
		free (fr);
		perror("Mensaje de que argumentos estan mal");
		//print instruccions again
		return (-1);
	}
	free (fr);
	//print instrucciones
	return (0);
}
