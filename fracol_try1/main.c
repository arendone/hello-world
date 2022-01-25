/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:01:25 by arendon-          #+#    #+#             */
/*   Updated: 2022/01/24 19:29:38 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fracol.h"

//gcc main.c -L ./mlx/ -lmlx -framework OpenGL -framework AppKit -o magic 

void	my_mlx_pixel_put(t_info *fractal, int x, int y, int color)
{
	char	*dst;

	dst = fractal->addr + (y * fractal->line_length
			+ x * (fractal->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main()
{
	t_info	frac;
	t_info	*fractal;
	float	transp;
	int		color;
//hay que sacar de aqui la siguiente parte y llamarlo con el * y mandarlo como &fractal sin necesidad de declarar puntero
	fractal = &frac;
	fractal->mlx = mlx_init();
	fractal->win = mlx_new_window(fractal->mlx, 1920, 1080, "Magic Window");
	fractal->img = mlx_new_image(fractal->mlx, 1920, 1080);
	fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bits_per_pixel,
			&fractal->line_length, &fractal->endian);
	transp = 0.0;
	while (transp < 1)
	{
		color = 0x009400D3;
		color = add_shade(color, transp);
		cuadrado(fractal, 310, 1 + (transp * 200), color);
		transp = transp + 0.005;
	}
	transp = 0.0;
	while (transp < 1)
	{
		color = 0x000000D3;
		color = add_shade(color, transp);
		cuadrado(fractal, 510, 1 + (transp * 200), color);
		transp = transp + 0.05;
	}
	//triangle
	
	triangle(fractal, "1500, 100", 90, 0x00FF7F00);
	triangle(fractal, "1500, 300", 90, 0x00FF7F00);
	triangle(fractal, "1500, 500", 90, 0x50FF7F00);
	triangle(fractal, "1500, 700", 90, 0x99FF7F00);
	triangle(fractal, "1500, 900", 90, 0xBBFF7F00);
	
	//circle
	transp = 0.0;
	while(transp < 1)
	{
		color = 0x00FF0000;
		color = add_shade(color, transp);
		circle(fractal, 800, 100 + (transp * 150), color);
		transp = transp + 0.10;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
	mlx_key_hook(fractal->win, deal_key, &fractal);
	mlx_loop(fractal->mlx);
	return (0);
}

/*int main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	float	transp;
	int		color;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Magic Window");
	fractal.img = mlx_new_image(mlx, 1920, 1080);

// After creating an image, we can call `mlx_get_data_addr`, we pass
// `bits_per_pixel`, `line_length`, and `endian` by reference. These will
// then be set accordingly for the *current* data address.

	fractal.addr = mlx_get_data_addr(fractal.img, &fractal.bits_per_pixel,
			&fractal.line_length, &fractal.endian);

	//cuadrado
	cuadrado(&img, 100, 100, 0x009400D3);
	cuadrado(&img, 110, 100, 0x004B0082);
	cuadrado(&img, 120, 100, 0x0000FF00);
	cuadrado(&img, 130, 100, 0x00FFFF00);
	cuadrado(&img, 140, 100, 0x00FF7F00);
	cuadrado(&img, 150, 100, 0x00FF0000);

	transp = 0.0;
	while (transp < 1)
	{
		color = 0x009400D3;
		color = add_shade(color, transp);
		cuadrado(&img, 310, 1 + (transp * 200), color);
		transp = transp + 0.005;
	}
	transp = 0.0;
	while (transp < 1)
	{
		color = 0x000000D3;
		color = add_shade(color, transp);
		cuadrado(&img, 510, 1 + (transp * 200), color);
		transp = transp + 0.05;
	}
	//triangle
	
	triangle(&img, "1500, 100", 90, 0x00FF7F00);
	triangle(&img, "1500, 300", 90, 0x00FF7F00);
	triangle(&img, "1500, 500", 90, 0x50FF7F00);
	triangle(&img, "1500, 700", 90, 0x99FF7F00);
	triangle(&img, "1500, 900", 90, 0xBBFF7F00);
	
	//circle
	transp = 0.0;
	while(transp < 1)
	{
		color = 0x00FF0000;
		color = add_shade(color, transp);
		circle(&img, 800, 100 + (transp * 150), color);
		transp = transp + 0.10;
	}

	mlx_put_image_to_window(mlx, mlx_win, fractal.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}*/
