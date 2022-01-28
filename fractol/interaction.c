/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:44:16 by arendon-          #+#    #+#             */
/*   Updated: 2022/01/27 19:20:35 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	deal_key(int key, t_info *fr)
{
	printf("key pressed %i\n", key); //NECESITAS TU FT_PRINTF
	if (key == 53 || key == 12)
		exit(0);
	else if (key == 46)
		//printf("mandelbrot %lu", sizeof(fr));
		plot_window2(fr);
		//cuadrado(fr, 600, 10, 0x0000FF00); SEGMENTATION FAUL
	//else if (key == 38)
		//printf("julia");
		//cuadrado(fr, 600, 100, 0x000000FF);
	plot_window(fr);
	return (0);
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