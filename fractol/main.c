/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:01:25 by arendon-          #+#    #+#             */
/*   Updated: 2022/01/25 19:24:38 by arendon-         ###   ########.fr       */
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
}

void	mandelbrot(t_info *fr)
{
	fr->rmin = -2.0;
	fr->rmax = 1.0;
	fr->imin = -1.2;
	fr->imax = fr->imin + (fr->rmax - fr->rmin)
		* (fr->img_height * 1.0 / fr->img_width * 1.0);

	//i need the coordenate or every pixel to proof if it is a mandelbrot point or not and then paint it
	
	double	re_factor;
	double	im_factor;
	int		x;
	int		y;
	double	c_re;
	double	c_im;
	bool	isInside;
	int		interac;
	double	Z_re;
	double	Z_im;

	re_factor = (fr->rmax - fr->rmin) / (fr->img_width - 1);
	im_factor = (fr->imax - fr->imin) / (fr->img_height - 1);
	x = 0;
	while (x < (fr->img_width))
	{
		c_re = (fr->rmin) + (x * re_factor);
		y = 0;
		while (y < (fr->img_height))
		{
			c_im = (fr->imax) - (y * im_factor);
			// Calculate whether c belongs to the Mandelbrot set or
        // not and draw a pixel at coordinates (x,y) accordingly
			Z_re = c_re;
			Z_im = c_im;
			isInside = true;
			interac = 30;
			while (interac >= 0)
			{
				double Z_re2 = Z_re*Z_re, Z_im2 = Z_im*Z_im;
				//printf("x =%i, y=%i, Z_re = %f, Z_im = %f\n", x, y, Z_re, Z_im);
				if (x == 100 && y == 200)
					printf("x =%i, y=%i, c_re=%f, c_im=%f, Z_re = %f, Z_im = %f\n", x, y, c_re, c_im, Z_re, Z_im);
				if (((Z_re * Z_re) + (Z_im * Z_im)) > 4)
				{
					isInside = false;
					break ;
				}
				Z_im = (2 * Z_re * Z_im) + c_im;
				Z_re = (Z_re2) - (Z_im2) + c_re;
				interac--;
			}
			//printf("x =%i, y=%i, Z_re = %f, Z_im = %f\n", x, y, Z_re, Z_im);
			if (isInside == true)
				my_mlx_pixel_put(fr, x, y, 0x000000FF);
			y++;
		}
		x++;
	}
	printf("refactor =%f, imfactor=%f, fr->imax = %f\n", re_factor, im_factor, fr->imax);
}

void	plot_window(t_info *fr)
{
	//ft_printf("Plot %s. k_re\n", fr->fr_set);
	mandelbrot(fr);
	//plot_fr(fr); //mandelbrot(fr)
	mlx_put_image_to_window(fr->mlx, fr->win, fr->img, 0, 0);
}

int	main()
{
	t_info	fr;
	//float	transp;
	//int		color;
	init_window(&fr);
	//mandelbrot(&fr);
	plot_window(&fr);
	mlx_key_hook(fr.win, deal_key, &fr);
	mlx_loop(fr.mlx);
	return (0);
}
