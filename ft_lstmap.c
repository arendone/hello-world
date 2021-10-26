/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 18:29:48 by arendon-          #+#    #+#             */
/*   Updated: 2021/09/20 21:06:39 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**map;
	int		size;
	int		i;
	int		j;

	if (lst == NULL)
		return (NULL);
	size = ft_lstsize(lst);
	map = (t_list **)malloc(sizeof(t_list) * size);
	if (map == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
        if (f(lst->content))
        {
            map[i]->content = f(lst->content);
		    map[i]->next = map[i + 1];
		    lst = lst->next;
		    i++;
        }
        else
        {
            
            ft_lstdelone(map[i], del);
		    i++; 
        }

	}
	i = 0;
	map[i]->next = NULL;
	while (i < size)
	{
		ft_lstdelone(map[i], del);
		i++;
	}
	return (map[0]);  //if map[0] is freed i have to take the next :)
}
