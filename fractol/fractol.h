/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:56:40 by arendon-          #+#    #+#             */
/*   Updated: 2022/01/28 16:35:27 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include <math.h>
# include <stdio.h> //perror
# include <stdbool.h>
# include <stdarg.h>

typedef struct s_info{
	//init window
	void		*mlx;
	void		*win;
	void		*img;
	int			img_width;
	int			img_height;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	// values assigned in the fractal funtion
	double		rmin;
	double		rmax;
	double		imin;
	double		imax;
	double		Z_re;
	double		Z_im;
	double		Z_re2;
	double		Z_im2;
	bool		isInside;
	// default values, will be change in the arg - control
	int			Maxint;
	char		name_fr;
	char		color;
	double		K_re;
	double		K_im;
}	t_info;

/*playing with minilibx, files: analitic_geometry.c colors.c*/
//void	cuadrado(t_info *fr, int center, int size, int color);
//void	triangle(t_info *fr, char *inter_cat, int size_cat, int color);
//void	circle(t_info *fr, int c, int radio, int color);
//int		add_shade(int color, float transp);

/* file main.c */
void	my_mlx_pixel_put(t_info *fr, int x, int y, int color);
void	init_window(t_info *fr);
void	plot_window(t_info *fr);
void	plot_window2(t_info *fr); //borrar

/* file interaccion.c */
int		deal_key(int key, t_info *fr);

/* colors.c */
int		create_trgb(int t, int r, int g, int b);
int		add_shade(int color, float transp);
int		colors(int n);

/*mandelbrot.c */
void	mandelbrot(t_info *fr);
void	julia(t_info *fr);
#endif