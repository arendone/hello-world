/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maximoint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:57:36 by marvin            #+#    #+#             */
/*   Updated: 2021/10/28 10:57:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include <stdarg.h>
//quitar libreria y ponerla en libft

int	ft_maximoint(int n, ...)
{
	int	i;
	int	val;
	int	largest;
	va_list	vl;
	va_start(vl,n);
	largest = va_arg(vl, int);
	for(i = 1; i < n; i++)
	{
		val = va_arg(vl, int);
        if (largest > val)
		    largest = largest;
        else
            largest = val;
	}
	va_end(vl);
	return (largest);
}
