/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fracol.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:56:40 by arendon-          #+#    #+#             */
/*   Updated: 2022/01/21 16:14:09 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACOL_H
# define FRACOL_H

# include "./mlx/mlx.h"
# include <math.h>

typedef struct s_data{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

#endif