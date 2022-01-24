/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analitic_geometry.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 09:54:06 by arendon-          #+#    #+#             */
/*   Updated: 2022/01/24 19:25:03 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fracol.h"

void	cuadrado(t_info *fractal, int center, int size, int color)
{
	int	i;

	i = center - (size / 2);
	while (i <= (center + (size / 2)))
	{
		my_mlx_pixel_put(fractal, i, center - (size / 2), color);
		my_mlx_pixel_put(fractal, center - (size / 2), i, color);
		my_mlx_pixel_put(fractal, center + (size / 2), i, color);
		my_mlx_pixel_put(fractal, i, center + (size / 2), color);
		i++;
	}
}

void	triangle(t_info *fractal, char *inter_cat, int size_cat, int color)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = ft_atoi(&inter_cat[0]);
	y = ft_atoi(&inter_cat[5]); //no me gusta que tengo que calcularlo manual, tendria que usar split
	//printf("el x: %d y el y: %d", x, y);
	i = x;
	j = y - size_cat;
	while (i <= (x + size_cat))
	{
		my_mlx_pixel_put(fractal->img, i, j, color);
		my_mlx_pixel_put(fractal->img, i, y, color);
		i++;
		my_mlx_pixel_put(fractal->img, x, j, color);
		j++;
	}
}

//circle (x-h)² + (y-k)² =r², donde (h,k) es el centro y r es el radio.
void	circle(t_info *fractal, int c, int radio, int color)
{
	int	i;

	i = c - radio;
	while (i <= (c + radio))
	{
		my_mlx_pixel_put(fractal->img, i, c + sqrt(pow(radio, 2)
				- (pow(i - c, 2))), color);
		my_mlx_pixel_put(fractal->img, i, c - sqrt(pow(radio, 2)
				- (pow(i - c, 2))), color);
		//my_mlx_pixel_put(&img, 2 * i, c + sqrt(2500 - (pow(i - c, 2))), 0x00FF0000);
		//my_mlx_pixel_put(&img, 2 * i, c - sqrt(2500 - (pow(i - c, 2))), 0x00FF0000);
		//my_mlx_pixel_put(&img, 3 * i, c + sqrt(2500 - (pow(i - c, 2))), 0x00FF0000);
		//my_mlx_pixel_put(&img, 3 * i, c - sqrt(2500 - (pow(i - c, 2))), 0x00FF0000);
		i++;
	}
}
