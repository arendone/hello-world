/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:01:25 by arendon-          #+#    #+#             */
/*   Updated: 2022/01/31 19:54:45 by arendon-         ###   ########.fr       */
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
	//fr->w_width = 1024; si las uso no se ve mi imagen??!!
	//fr->w_height = 768;
	fr->img_width = 1024;//(fr->w_width);
	fr->img_height = 768;//(fr->w_height);
	fr->win = mlx_new_window(fr->mlx, fr->img_width,
			fr->img_height, "Fract-ol");
	fr->img = mlx_new_image(fr->mlx, fr->img_width,
			fr->img_height);
	fr->addr = mlx_get_data_addr(fr->img, &fr->bits_per_pixel,
			&fr->line_length, &fr->endian);
	plot_window(fr);
}

void	plot_window(t_info *fr)
{
	if (fr->name_fr == 'm')
		mandelbrot(fr);
	if (fr->name_fr == 'j')
		julia(fr);
	//if (fr->name_fr == 't')
		//tree(fr);
	mlx_put_image_to_window(fr->mlx, fr->win, fr->img, 0, 0);
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
