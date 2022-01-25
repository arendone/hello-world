/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:28:56 by arendon-          #+#    #+#             */
/*   Updated: 2022/01/24 12:16:33 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fracol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

/*static int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}*/

int	add_shade(int color, float transp)
{
	int	entero;
	int	shade;

	entero = 256 * transp;
	shade = entero << 24;
	color = color + shade;
	return (color);
}
