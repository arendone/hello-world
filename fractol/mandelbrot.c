/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:37:35 by arendon-          #+#    #+#             */
/*   Updated: 2022/01/28 19:23:37 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_info *fr) //no se si tengo que pintar todo de negro antes porque se sigue viendo
//el otro fractal 
{
	fr->rmin = -2.0;
	fr->rmax = 1.0;
	fr->imin = -1.2;
	fr->imax = fr->imin + (fr->rmax - fr->rmin)
		* (fr->img_height * 1.0 / fr->img_width * 1.0);

	int		x;
	int		y;
	double	c_re;
	double	c_im;
	int		n;


	//fr->Maxint = 30;
	x = 0;
	while (x < (fr->img_width))
	{
		c_re = (fr->rmin) + (x * (fr->rmax - fr->rmin) / (fr->img_width - 1));
		y = 0;
		while (y < (fr->img_height))
		{
			c_im = (fr->imax) - (y * (fr->imax - fr->imin) / (fr->img_height - 1));
			// Calculate whether c belongs to the Mandelbrot set or not and draw a pixel at coordinates (x,y) accordingly
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
			//hacer funcion para colorear
			if (fr->isInside == false)
				my_mlx_pixel_put(fr, x, y, colors(n));
			else
				my_mlx_pixel_put(fr, x, y, 0x00000000);
			y++;
		}
		x++;
	}
	printf("Z_re = %f, Z_im = %f, Z_re2 = %f, Z_im2 = %f\n", fr->Z_re, fr->Z_im, fr->Z_re2, fr->Z_im2);
}

void	julia(t_info *fr)
{
	fr->rmin = -1.7;
	fr->rmax = 1.7;
	fr->imin = -1.3;
	fr->imax = fr->imin + (fr->rmax - fr->rmin)
		* (fr->img_height * 1.0 / fr->img_width * 1.0);

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
			// Calculate whether c belongs to the Mandelbrot set or
        // not and draw a pixel at coordinates (x,y) accordingly
			fr->Z_re = c_re;
			fr->Z_im = c_im;
			fr->isInside = true; //puedo declararlo en init
			n = 0;
			while (n <= (fr->Maxint))
			{
				fr->Z_re2 = fr->Z_re * fr->Z_re;
				fr->Z_im2 = fr->Z_im * fr->Z_im;
				if (((fr->Z_re2) + (fr->Z_im2)) > 4)
				{
					fr->isInside = false;
					break ;
				}
				fr->Z_im = (2.0 * fr->Z_re * fr->Z_im) + (fr->K_im);//mandelbrot: + c_im;
				fr->Z_re = (fr->Z_re2) - (fr->Z_im2) + (fr->K_re);//mndelbrot: + c_re;
				n++;
			}
			if (fr->isInside == true)
			{
				n = (sqrt(fr->Z_re2 + fr->Z_im2) * 60.0) / 1.0;
				my_mlx_pixel_put(fr, x, y, colors(32-n));
			}
			y++;
		}
		x++;
	}
}
