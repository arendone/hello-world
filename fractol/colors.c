/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:28:56 by arendon-          #+#    #+#             */
/*   Updated: 2022/01/28 17:20:12 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

int	colors(int n)
{
	if (n < 4)
		return (add_shade(0x00900C3F, (n * 0.10)));
	else if (n < 8)
		return (add_shade(0x00C70039, ((n / 2) * 0.10)));
	else if (n < 12)
		return (add_shade(0x00FF5733, ((n / 3) * 0.05)));
	else if (n < 16)
		return (add_shade(0x00FFC30F, ((n / 4) * 0.05)));
	else if (n < 20)
		return (add_shade(0x00900C3F, ((n / 5) * 0.15)));
	else if (n < 24)
		return (add_shade(0x00C70039, ((n / 6) * 0.05)));
	else if (n < 28)
		return (add_shade(0x00FF5733, ((n / 7) * 0.05)));
	else if (n < 32)
		return (add_shade(0x00FFC30F, ((n / 8) * 0.05)));
	else
		return (0x00000000);
}

//rosa y verde psicodelico
/*int	colors(int n)
{
	if (n < 4)
		return (add_shade(0x00DF00FF, (n * 0.10)));
	else if (n < 8)
		return (add_shade(0x0021FF00, ((n / 2) * 0.10)));
	else if (n < 12)
		return (add_shade(0x00DF00FF, ((n / 3) * 0.05)));
	else if (n < 16)
		return (add_shade(0x0021FF00, ((n / 4) * 0.05)));
	else if (n < 20)
		return (add_shade(0x00DF00FF, ((n / 5) * 0.10)));
	else if (n < 24)
		return (add_shade(0x0021FF00, ((n / 6) * 0.10)));
	else if (n < 28)
		return (add_shade(0x00DF00FF, ((n / 7) * 0.05)));
	else if (n < 32)
		return (add_shade(0x0021FF00, ((n / 8) * 0.05)));
	else
		return (0x00000000);
}*/

// tonos lila-morado-centro blanco
/*int	colors(int n)
{
	if (n < 4)
		return (add_shade(0x009400D3, (n * 0.25)));
	else if (n < 8)
		return (add_shade(0x009400D3, ((n / 2) * 0.25)));
	else if (n < 12)
		return (add_shade(0x005000D3, ((n / 3) * 0.25)));
	else if (n < 16)
		return (add_shade(0x005000D3, ((n / 4) * 0.25)));
	else if (n < 20)
		return (add_shade(0x002500D3, ((n / 5) * 0.25)));
	else if (n < 24)
		return (add_shade(0x002500D3, ((n / 6) * 0.25)));
	else if (n < 28)
		return (add_shade(0x00009999, ((n / 7) * 0.25)));
	else if (n < 32)
		return (add_shade(0x00000000, ((n / 8) * 0.25)));
	else
		return (0x00000000);
}*/