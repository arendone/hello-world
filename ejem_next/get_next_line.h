/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachmull <sachmull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 18:16:19 by sachmull          #+#    #+#             */
/*   Updated: 2021/09/24 17:06:38 by sachmull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
# if (BUFFER_SIZE > 0)
char	*add_to_line(char *l, char *b, int fd, char fl_d[10240][BUFFER_SIZE]);
char	*get_leftovers(int fd, char fl_d[10240][BUFFER_SIZE]);
void	arrange(int fd, char fl_d[10240][BUFFER_SIZE]);

char	*sc(const char *s, int c);
void	*ft_calloc(size_t nitems, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	*ft_memset(void *str, int c, size_t n);
# endif
#endif
