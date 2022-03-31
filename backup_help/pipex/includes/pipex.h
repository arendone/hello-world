/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajazbuti <ajazbuti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:00:46 by ajazbuti          #+#    #+#             */
/*   Updated: 2022/02/26 16:27:09 by ajazbuti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_pipex
{
	char	***cmd;
	char	**ep;
	char	**path;
	char	*cmd1;
	int		fd[2];
	int		pp1[2];
	pid_t	id;
	int		cmd_nbr;
	int		*pp;
	int		here_doc;
}t_pipex;

void	ft_dup2_dup2(int inpt, int outpt);
void	ft_clean_exit(char *s, t_pipex *ppx);
void	ft_get_path(char **envp, t_pipex *ppx);
void	ft_get_cmds(int ac, char **av, t_pipex *ppx);
char	*ft_get_cmnd(t_pipex *ppx, char *cmd);
void	ft_piping(t_pipex *ppx, int ac, char **av);
/*libft not authorised*/
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
char	**ft_free_tab(char **tab);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(const char *s, char c);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size);
size_t	ft_strlcat(char *dst, const char *src, size_t dst_size);

#endif
