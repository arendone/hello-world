/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:01:25 by arendon-          #+#    #+#             */
/*   Updated: 2022/02/01 18:23:59 by arendon-         ###   ########.fr       */
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
	fr->img_width = 1024;//(fr->w_width);
	fr->img_height = 768;//(fr->w_height);
	fr->win = mlx_new_window(fr->mlx, fr->img_width,
			fr->img_height, "Fract-ol");
	fr->img = mlx_new_image(fr->mlx, fr->img_width,
			fr->img_height);
	fr->addr = mlx_get_data_addr(fr->img, &fr->bits_per_pixel,
			&fr->line_length, &fr->endian);
	plot_window_firsttime(fr);
}

void	plot_window_firsttime(t_info *fr)
{
	paint_imagen_black(fr);
	mlx_clear_window(fr->mlx, fr->win);
	if (fr->name_fr == 'm')
		init_mandelbrot(fr);
	if (fr->name_fr == 'j')
		init_julia(fr);
	//if (fr->name_fr == 't')
		//tree(fr);
	mlx_put_image_to_window(fr->mlx, fr->win, fr->img, 0, 0);
}

void	plot_window(t_info *fr)
{
	paint_imagen_black(fr);
	mlx_clear_window(fr->mlx, fr->win);
	if (fr->name_fr == 'm')
		mandelbrot(fr);
	if (fr->name_fr == 'j')
		julia(fr);
	//if (fr->name_fr == 't')
		//tree(fr);
	mlx_put_image_to_window(fr->mlx, fr->win, fr->img, 0, 0);
}

int	print_error(void)
{
	printf("\n\033[0;31mWrong input!\
	\n\033[0;37mThe input should be like: './fractol\033[0;32m   name_of_fractal\
	\033[0;33mset_of_colors\033[0;34m   K_re\033[0;35m   K_im\033[0;37m'\
	\n\033[0;32m -Fractals: mandelbrot, julia, tree\
	\n\033[0;33m -Set of colors : fuego, psycho, lila\
	\n\033[0;34m -Value of K_re (Only for fractal Julia)\
	\n\033[0;35m -Value of K_im (Only for fractal Julia)\
	\n\033[0;37m*Only name_of_fractal is essential :)\n\n");
	return (EXIT_FAILURE);
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
		print_error();
		return (-1);
	}
	free (fr);
	return (0);
}
