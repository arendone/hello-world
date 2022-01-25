/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fracol.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:56:40 by arendon-          #+#    #+#             */
/*   Updated: 2022/01/24 19:27:22 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACOL_H
# define FRACOL_H

# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include <math.h>
# include <stdio.h> //BORRAR

typedef struct s_info{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*win;
}	t_info;

/*playing with minilibx, files: analitic_geometry.c colors.c*/
void	cuadrado(t_info *fractal, int center, int size, int color);
void	triangle(t_info *fractal, char *inter_cat, int size_cat, int color);
void	circle(t_info *fractal, int c, int radio, int color);
int		add_shade(int color, float transp);

/* file main.c */
void	my_mlx_pixel_put(t_info *fractal, int x, int y, int color);

/* file interaccion.c */
int		deal_key(int key, t_info *fractal);
#endif