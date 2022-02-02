/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:44:16 by arendon-          #+#    #+#             */
/*   Updated: 2022/02/02 20:54:55 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 * esc(53) and q(12) - exit
 * M(46) and J(38) - mandelbrot and julia sets
 * arrows left(123), right(124), down(125), top(126)
 * Z(6) and X(7) - zoom in and zoom out
 */

int	deal_key(int key, t_info *fr)
{
	if (key <= 60)
	{
		if (key == 53 || key == 12)
		{
			free (fr);
			exit(0);
		}
		else if (key == 46)
			init_mandelbrot(fr);
		else if (key == 38)
			init_julia(fr);
		else if (key == 17)
		{
			fr->Maxint = 1;
			init_tree(fr);
		}
		else if (key == 6)
			zoom(fr, 0.833);
		else if (key == 7)
			zoom(fr, 1.2);
		plot_window(fr);
	}
	else
		deal_key2(key, fr);
	return (0);
}

int	deal_key2(int key, t_info *fr)
{
	if (key == 123)
		panning_x(fr, -0.05);
	else if (key == 124)
		panning_x(fr, 0.05);
	else if (key == 125)
		panning_y(fr, -0.05);
	else if (key == 126)
		panning_y(fr, 0.05);
	else if (key == 69 && fr->name_fr == 't')
	{
		fr->Maxint++;
		init_tree(fr);
	}
	else if (key == 78 && fr->name_fr == 't')
	{
		fr->Maxint--;
		init_tree(fr);
	}
	plot_window(fr);
	return (0);
}

int	mouse_event(int button, int x, int y, t_info *fr)
{
	fr->point.x = x;
	fr->point.y = y;
	if (button == 4)
		zoom(fr, 1.2);
	if (button == 5)
		zoom(fr, 0.833);
	plot_window(fr);
	return (0);
}

void	panning_x(t_info *fr, double p)
{
	fr->rmin = fr->rmin + p;
	fr->rmax = fr->rmax + p;
}

/* despues de usarla mucho deja de moverse pero hace un efecto de brillo
void	panning_x(t_info *fr, double p)
{
	fr->rmin = fr->rmin + (p * fr->rmax);
	fr->rmax = fr->rmax + (p * fr->rmax);
} */

void	panning_y(t_info *fr, double p)
{
	fr->imin = fr->imin + p;
	fr->imax = fr->imax + p;
}

/*
double	inter_pol(double start, double end, double inter)
{
	return (start + (end - start) * inter);
}*/

/*int	mouse_event(int button, int x, int y, t_info *fr)
{
	if (button == 4)
		ft_zoom(fr, x, y);
	if (button == 5)
		ft_dezoom(fr, x, y);
	plot_window(fr);
	return (0);
}*/

void	zoom(t_info *fr, double p)
{
	double	grad_x;
	double	grad_y;
	//double	mx;
	//double	my;
	//printf("rmin: %f, rmax:%f\n", fr->rmin, fr->rmax);
	//printf("ïmin: %f, imax:%f\n", fr->imin, fr->imax);
	grad_x = fr->rmin + (fr->point.x * (fr->rmax - fr->rmin) / (fr->img_width - 1));
	grad_y = fr->imin + (fr->point.y * (fr->imax - fr->imin) / (fr->img_height - 1));
	//printf("gradx: %f, grady:%f\n", grad_x, grad_y);
	//printf("mx: %f, my:%f\n", mx, my);
	if(p < 1)
	{
		fr->rmin = fr->rmin + (grad_x / 2);// - mx);
		fr->rmax = fr->rmax + (grad_x / 2);// - mx);
		fr->imin = fr->imin - (grad_y / 2);// - my);
		fr->imax = fr->imax - (grad_y / 2);// - my);
	}
	fr->rmin = fr->rmin * p;
	fr->rmax = fr->rmax * p;
	fr->imin = fr->imin * p;
	fr->imax = fr->imax * p;

	//printf("rmin: %f, rmax:%f\n", fr->rmin, fr->rmax);
	//printf("ïmin: %f, imax:%f\n", fr->imin, fr->imax);
	//
	//grad_x = fr->rmin + (fr->point.x * (fr->rmax - fr->rmin) / (fr->img_width - 1));
	//grad_y = fr->imin + (fr->point.y * (fr->imax - fr->imin) / (fr->img_height - 1));
	//printf("gradx: %f, grady:%f\n", grad_x, grad_y);
	//printf("rmin: %f, rmax:%f\n", fr->rmin, fr->rmax);
	//printf("ïmin: %f, imax:%f\n", fr->imin, fr->imax);
}

/*
1) 
Gets the current mouse position on the window.
int		mlx_mouse_get_pos(void *win_ptr, int *x, int *y);

2)
Destroys an image instance accordingly.
int		mlx_destroy_image(void *mlx_ptr, void *img_ptr);

*/

/*void	ft_zoom(t_info *fr, int x, int y)
{
	t_point	m_pos;
	
	m_pos.x = (double)x / (fr->img_width / (fr->rmax - fr->rmin)) + fr->rmin;
	m_pos.y = (double)y / (fr->img_height / (fr->imax - fr->imin)) * -1 + fr->imin;//max;
	fr->rmax = inter_pol(m_pos.x, fr->rmax, 0.833);
	fr->imax = inter_pol(m_pos.y, fr->imax, 0.833);
	fr->rmin = inter_pol(m_pos.x, fr->rmin, 0.833);
	fr->imin = inter_pol(m_pos.y, fr->imin, 0.833);
	//start_frtols(fr);
}

void	ft_dezoom(t_info *fr, int x, int y)
{
	t_point	m_pos;
	
	m_pos.x = (double)x / (fr->img_width
			/ (fr->rmax - fr->rmin)) + fr->rmin;
	m_pos.y = (double)y / (fr->img_height
			/ (fr->imax - fr->imin)) * -1 + fr->imin;//max;
	fr->rmax = inter_pol(m_pos.x, fr->rmax, 1.2);
	fr->imax = inter_pol(m_pos.y, fr->imax, 1.2);
	fr->rmin = inter_pol(m_pos.x, fr->rmin, 1.2);
	fr->imin = inter_pol(m_pos.y, fr->imin, 1.2);
	//start_frtols(fr);
}*/
