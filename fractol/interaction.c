/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:44:16 by arendon-          #+#    #+#             */
/*   Updated: 2022/02/02 13:08:33 by arendon-         ###   ########.fr       */
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
	else if (key == 17)
	{
		fr->Maxint = 1;
		init_tree(fr);
	}
	else if (key == 69 && fr->name_fr == 't')
	{
		fr->Maxint++;
		init_tree(fr);
	}
	else if (key == 78 && fr->name_fr == 't')
	{
		fr->Maxint--;
		init_tree(fr);
	}
	else if (key == 123)
		panning_x(fr, -0.05);
	else if (key == 124)
		panning_x(fr, 0.05);
	else if (key == 125)
		panning_y(fr, -0.05);
	else if (key == 126)
		panning_y(fr, 0.05);
	else if (key == 6)
		zoom(fr, 0.833);
	else if (key == 7)
		zoom(fr, 1.2);
	plot_window(fr);
	return (0);
}

int	mouse_event(int button, int x, int y, void *fr)
{
	printf("x: %i y: %i button: %i\n", x, y, button);
	if (button == 4)
		panning_y(fr, -0.1);
	else if (button == 5)
		panning_y(fr, 0.1);
	else if (button == 6)
		panning_x(fr, 0.1);
	else if (button == 7)
		panning_x(fr, -0.1);
	plot_window(fr);
	return (0);
}

void	panning_x(t_info *fr, double p)
{
	fr->rmin = fr->rmin + p;
	fr->rmax = fr->rmax + p;
}

/* despues de usarla mucho deja de moverse pero hace un efecto de brillo
void	panning_x(t_info *fr, double p)
{
	fr->rmin = fr->rmin + (p * fr->rmax);
	fr->rmax = fr->rmax + (p * fr->rmax);
} */

void	panning_y(t_info *fr, double p)
{
	fr->imin = fr->imin + p;
	fr->imax = fr->imax + p;
}

void	zoom(t_info *fr, double p)
{
	fr->rmin = fr->rmin * p;
	fr->rmax = fr->rmax * p;
	fr->imin = fr->imin * p;
	fr->imax = fr->imax * p;
}

/*
1) 
Gets the current mouse position on the window.
int		mlx_mouse_get_pos(void *win_ptr, int *x, int *y);

2)
Destroys an image instance accordingly.
int		mlx_destroy_image(void *mlx_ptr, void *img_ptr);

*/