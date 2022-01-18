/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:01:25 by arendon-          #+#    #+#             */
/*   Updated: 2022/01/14 19:35:00 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"

//gcc main.c -L ./mlx/ -lmlx -framework OpenGL -framework AppKit -o magic 

int	main()
{
	void	*mlx_ptr;
	void	*window_ptr;
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
}