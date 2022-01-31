/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:44:16 by arendon-          #+#    #+#             */
/*   Updated: 2022/01/31 20:46:42 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	deal_key(int key, t_info *fr)
{
	printf("key pressed %i\n", key);
	if (key == 53 || key == 12)
	{
		free (fr);
		exit(0);
	}
	else if (key == 46)//Mandelbrot
		reinit_mandelbrot(fr);
	//else if (key == 38) //julia
	//	reinit_julia(fr);
	//plot_window(fr);
	return (0);
}

void	paint_imagen_black(t_info *fr)
{
	int	i;
	int	j;

	i = 0;
	while (i < 1024)//(fr->img_width))
	{
		j = 0;
		while (j < 768)//(fr->img_height))
		{
			my_mlx_pixel_put(fr, i, j, 0x00000000);
			j++;
		}
		i++;
	}
}

void	reinit_mandelbrot(t_info *fr)
{
	paint_imagen_black(fr);
	mlx_clear_window(fr->mlx, fr->win);
	//mlx_destroy_image(fr->mlx, fr->img);
	//fr->img = NULL;
	//fr->img = mlx_new_image(fr->mlx, fr->img_width,
	//		fr->img_height);
	//fr->addr = mlx_get_data_addr(fr->img, &fr->bits_per_pixel,
	//		&fr->line_length, &fr->endian);
	fr->name_fr = 'm';
	fr->color = 'f';
	//quitarlas de funcion general de mandelbrot
	fr->rmin = -2.0;
	fr->rmax = 1.0;
	fr->imin = -1.2;
	fr->imax = fr->imin + (fr->rmax - fr->rmin)
		* (fr->img_height * 1.0 / fr->img_width * 1.0);
	plot_window(fr);
}
/*
 * esc(53) and q(12) - exit
 * M(46) and J(38) - mandelbrot and julia sets
 * Z(6) and X(7) - zoom in and out
 * arrows left(123), top(126), down(125), right(124)
 */
/*

int	handle_keypress(int keycode, t_Window *fr)
{
	ft_printf("key pressed %i", keycode);
	if (keycode == 53 || keycode == 12)
		exit(0);
	else if (keycode == 46)
		restart_mandelbrot(fr);
	else if (keycode == 38)
		restart_julia(fr);
	else if (keycode == 6)
		zoom(fr, 0.8);
	else if (keycode == 7)
		zoom(fr, 1.2);
	else if (keycode == 123)
		shift_raxis(fr, -0.05);
	else if (keycode == 124)
		shift_raxis(fr, 0.05);
	else if (keycode == 125)
		shift_iaxis(fr, -0.05);
	else if (keycode == 126)
		shift_iaxis(fr, 0.05);
	plot_image(fr);
	return (0);
}*/

//void	plot_image(t_vars vars, t_data *img)
//{
//	printf("Plot\n");
//	plot_fr(fr);
//	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
//}

/*
1) 
Gets the current mouse position on the window.
int		mlx_mouse_get_pos(void *win_ptr, int *x, int *y);

2)
Destroys an image instance accordingly.
int		mlx_destroy_image(void *mlx_ptr, void *img_ptr);

*/