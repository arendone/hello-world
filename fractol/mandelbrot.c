/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:37:35 by arendon-          #+#    #+#             */
/*   Updated: 2022/02/01 18:19:48 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* it did't work...
		mlx_destroy_image(fr->mlx, fr->img);
		fr->img = NULL;
		fr->img = mlx_new_image(fr->mlx, fr->img_width,
				fr->img_height);
		fr->addr = mlx_get_data_addr(fr->img, &fr->bits_per_pixel,
				&fr->line_length, &fr->endian); 
				*/

void	init_mandelbrot(t_info *fr)
{
	fr->rmin = -2.0;
	fr->rmax = 1.0;
	fr->imin = -1.2;
	fr->imax = fr->imin + (fr->rmax - fr->rmin)
		* (fr->img_height * 1.0 / fr->img_width * 1.0);
	fr->name_fr = 'm';
	mandelbrot(fr);
}

void	mandelbrot(t_info *fr)
{
	int		x;
	int		y;
	double	c_re;
	double	c_im;
	int		n;

	x = 0;
	while (x < (fr->img_width))
	{
		c_re = (fr->rmin) + (x * (fr->rmax - fr->rmin) / (fr->img_width - 1));
		y = 0;
		while (y < (fr->img_height))
		{
			c_im = (fr->imax) - (y * (fr->imax - fr->imin) / (fr->img_height - 1));
			fr->Z_re = c_re;
			fr->Z_im = c_im;
			fr->isInside = true;
			n = 0;
			while (n <= (fr->Maxint))
			{
				fr->Z_re2 = fr->Z_re * fr->Z_re;
				fr->Z_im2 = fr->Z_im * fr->Z_im;
				if (((fr->Z_re * fr->Z_re) + (fr->Z_im * fr->Z_im)) > 4)
				{
					fr->isInside = false;
					break ;
				}
				fr->Z_im = (2 * fr->Z_re * fr->Z_im) + c_im;
				fr->Z_re = (fr->Z_re2) - (fr->Z_im2) + c_re;
				n++;
			}
			color_point_mandelbrot(fr, x, y, n);
			y++;
		}
		x++;
	}
}

void	color_point_mandelbrot(t_info *fr, int x, int y, int n)
{
	if (fr->color == 'f' && fr->isInside == false)
	{
		my_mlx_pixel_put(fr, x, y, color_fuego(n));
	}
	if (fr->color == 'p' && fr->isInside == false)
	{
		my_mlx_pixel_put(fr, x, y, color_psycho(n));
	}
	if (fr->color == 'l')
	{
		if (fr->isInside == true)
			my_mlx_pixel_put(fr, x, y, 0x00FFFFFF);
		else
			my_mlx_pixel_put(fr, x, y, color_lila(n));
	}
}
