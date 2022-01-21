/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:01:25 by arendon-          #+#    #+#             */
/*   Updated: 2022/01/21 19:29:12 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fracol.h"

//gcc main.c -L ./mlx/ -lmlx -framework OpenGL -framework AppKit -o magic 

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	cuadrado(t_data *img, int center, int size, int color)
{
	int	i;

	i = center - (size / 2);
	while (i <= (center + (size / 2)))
	{
		my_mlx_pixel_put(img, i, center - (size / 2), color);
		my_mlx_pixel_put(img, center - (size / 2), i, color);
		my_mlx_pixel_put(img, center + (size / 2), i, color);
		my_mlx_pixel_put(img, i, center + (size / 2), color);
		i++;
	}
}

int main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		i;
	int		c;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Magic Window");
	img.img = mlx_new_image(mlx, 1920, 1080);
/*
** After creating an image, we can call `mlx_get_data_addr`, we pass
** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
** then be set accordingly for the *current* data address.
*/
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	//my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	//cuadrado
	cuadrado(&img, 100, 100, 0x009400D3);
	cuadrado(&img, 110, 100, 0x004B0082);
	cuadrado(&img, 120, 100, 0x0000FF00);
	cuadrado(&img, 130, 100, 0x00FFFF00);
	cuadrado(&img, 140, 100, 0x00FF7F00);
	cuadrado(&img, 150, 100, 0x00FF0000);

	cuadrado(&img, 500, 100, 0x009400D3);
	cuadrado(&img, 510, 200, 0x209400D3);
	cuadrado(&img, 520, 300, 0x409400D3);
	cuadrado(&img, 530, 400, 0x609400D3);
	cuadrado(&img, 540, 500, 0x809400D3);
	cuadrado(&img, 550, 600, 0x999400D3);
	/*triangle
	c = 400;
	i = c;
	while (i < 501)
	{
		my_mlx_pixel_put(&img, c + 100, i, 0x00FF0000);
		my_mlx_pixel_put(&img, i, c, 0x00FF0000);
		my_mlx_pixel_put(&img, i, i, 0x00FF0000);
		i++;
	}*/
		//circle (x-h)² + (y-k)² =r², donde (h,k) es el centro y r es el radio.
	c = 800;
	i = c - 100;
	while (i <= (c + 100))
	{
		my_mlx_pixel_put(&img, i, c + sqrt(10000 - (pow(i - c, 2))), 0x00FF0000);
		my_mlx_pixel_put(&img, i, c - sqrt(10000 - (pow(i - c, 2))), 0x99FF0000);
		//my_mlx_pixel_put(&img, 2 * i, c + sqrt(2500 - (pow(i - c, 2))), 0x00FF0000);
		//my_mlx_pixel_put(&img, 2 * i, c - sqrt(2500 - (pow(i - c, 2))), 0x00FF0000);
		//my_mlx_pixel_put(&img, 3 * i, c + sqrt(2500 - (pow(i - c, 2))), 0x00FF0000);
		//my_mlx_pixel_put(&img, 3 * i, c - sqrt(2500 - (pow(i - c, 2))), 0x00FF0000);
		i++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
/*
int	main()
{
	void	*mlx_ptr;
	void	*window_ptr;
	void	*img;
	int		i;

	i = 1;
	mlx_ptr = mlx_init();
	window_ptr = mlx_new_window(mlx_ptr, 1024, 720, "Magic Window");
	while (i < 1025)
	{
		mlx_pixel_put(mlx_ptr, window_ptr, i, 100, 0x00FF0000);
		i++;
	}
	mlx_loop(mlx_ptr);



	return (0);
}*/