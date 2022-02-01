/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:44:16 by arendon-          #+#    #+#             */
/*   Updated: 2022/02/01 18:34:00 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 * esc(53) and q(12) - exit
 * M(46) and J(38) - mandelbrot and julia sets
 * arrows left(123), right(124), down(125), top(126)
 * Z(6) and X(7) - zoom in and zoom out
 */

int	deal_key(int key, t_info *fr)
{
	printf("key pressed %i\n", key);
	if (key == 53 || key == 12)
	{
		free (fr);
		exit(0);
	}
	else if (key == 46)
		init_mandelbrot(fr);
	else if (key == 38)
		init_julia(fr);
	else if (key == 123)
		panning_x(fr, -0.05);
	else if (key == 124)
		panning_x(fr, 0.05);
	else if (key == 125)
		panning_y(fr, -0.05);
	else if (key == 126)
		panning_y(fr, 0.05);
	//else if (key == 6)
	//	zoom(fr, 0.8);
	//else if (key == 7)
	//	zoom(fr, 1.2);
	plot_window(fr);
	return (0);
}

void	panning_x(t_info *fr, double p)
{
	fr->rmin = fr->rmin + p;
	fr->rmax = fr->rmax + p;
}

void	panning_y(t_info *fr, double p)
{
	fr->imin = fr->imin + p;
	fr->imax = fr->imax + p;
}

void	zoom(t_info *fr, double p)
{
	
}

void	paint_imagen_black(t_info *fr)
{
	int	i;
	int	j;

	i = 0;
	while (i < fr->img_width)
	{
		j = 0;
		while (j < fr->img_height)
		{
			my_mlx_pixel_put(fr, i, j, 0x00000000);
			j++;
		}
		i++;
	}
}

/*
1) 
Gets the current mouse position on the window.
int		mlx_mouse_get_pos(void *win_ptr, int *x, int *y);

2)
Destroys an image instance accordingly.
int		mlx_destroy_image(void *mlx_ptr, void *img_ptr);

*/