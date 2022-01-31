/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:56:40 by arendon-          #+#    #+#             */
/*   Updated: 2022/01/31 19:53:37 by arendon-         ###   ########.fr       */
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
	//int			w_width; //no se si las necesito
	//int			w_height;
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

/* file interaccion.c */
int		deal_key(int key, t_info *fr);
void	paint_imagen_black(t_info *fr);//no debe estar aqui
void	reinit_mandelbrot(t_info *fr); //no debe estar aqui


/* colors.c */
int		add_shade(int color, float transp);
int		color_fuego(int n);
int		color_psycho(int n);
int		color_lila(int n);

/*mandelbrot.c */
void	mandelbrot(t_info *fr);
void	color_point_mandelbrot(t_info *fr, int x, int y, int n);
void	julia(t_info *fr);
void	color_point_julia(t_info *fr, int x, int y, int n);

/* ft_atof.c */ //agregar a libft!!!!!!!!
double	ft_atof(char *str);

/* read arguments in read_arg.c */
int		init_t_info(t_info *fr, int arg, char **str);
int		compare(char *s1, char *s2, size_t n);
int		control_name(char *name, t_info *fr);
int		control_color(char *color, t_info *fr);
int		control_k(char *param, t_info *fr, char t);
#endif