/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:06:16 by arendon-          #+#    #+#             */
/*   Updated: 2022/02/01 21:26:05 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

typedef struct
{
	double x,y;
}point;
 
void pythagorasTree(point a,point b,int times){
 
	point c,d,e;
 
	c.x = b.x - (a.y -  b.y);
	c.y = b.y - (b.x - a.x);
 
	d.x = a.x - (a.y -  b.y);
	d.y = a.y - (b.x - a.x);
 
	e.x = d.x +  ( b.x - a.x - (a.y -  b.y) ) / 2;
	e.y = d.y -  ( b.x - a.x + a.y -  b.y ) / 2;
 
	if(times>0){
		setcolor(rand()%15 + 1);
 
		line(a.x,a.y,b.x,b.y);
		line(c.x,c.y,b.x,b.y);
		line(c.x,c.y,d.x,d.y);
		line(a.x,a.y,d.x,d.y);
 
		pythagorasTree(d,e,times-1);
		pythagorasTree(e,c,times-1);
	}
}