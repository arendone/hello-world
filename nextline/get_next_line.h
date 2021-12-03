/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:02:53 by arendon-          #+#    #+#             */
/*   Updated: 2021/11/29 11:35:52 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
void	ifree(char **str);
char	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*strjoin(char *pre_line, char *buffer, int i);
char	*clean_string(char *string, size_t start);
int		search_nextline(char *line, char *rest);
char	*read_more(int fd, char *line, char *rest);
char	*clean_and_keep_rest(char *line, char *rest, char *buffer, int i);
#endif