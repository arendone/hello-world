/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:44:17 by ajazbuti          #+#    #+#             */
/*   Updated: 2022/02/26 20:26:13 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_clean_exit(char *s, t_pipex *ppx)
{
	int	i;

	i = -1;
	if (ppx->path)
		ft_free_tab(ppx->path);
	if (ppx->pp)
		free(ppx->pp);
	if (s)
		perror(s);
	if (ppx->cmd)
	{
		while (ppx->cmd[++i])
			ft_free_tab(ppx->cmd[i]);
		free(ppx->cmd);
	}
	exit(EXIT_FAILURE);
}

static void	ft_init(t_pipex *ppx, char **envp)
{
	ppx->path = NULL;
	ppx->cmd = NULL;
	ppx->pp = NULL;
	ppx->cmd1 = NULL;
	ppx->here_doc = 0;
	ppx->cmd_nbr = -1;
	ppx->ep = envp;
}

static void	ft_here_doc(char *LIMITER, t_pipex *ppx)
{
	char	*line;

	ppx->here_doc = 1;
	ppx->id = pipe(ppx->pp1);
	if (ppx->id)
		ft_clean_exit("Pipe exploaded during creation", ppx);
	ft_putstr_fd("heredoc> ", 1);
	line = get_next_line(0);
	while (line)
	{
		if (!ft_strncmp(LIMITER, line, ft_strlen(LIMITER))
			&& ft_strlen(line) - 1 == ft_strlen(LIMITER))
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, ppx->pp1[1]);
		free(line);
		ft_putstr_fd("heredoc> ", 1);
		line = get_next_line(0);
	}
	close(ppx->pp1[1]);
}

static void	ft_fast_check(int argc, char **argv, t_pipex *ppx)
{
	if (argc < 5)
		ft_clean_exit("not enough arguments provided", ppx);
	else if (ft_strncmp("here_doc", argv[1], 9) == 0)
		ft_here_doc(argv[2], ppx);
}

int	main(int argc, char	**argv, char **envp)
{
	t_pipex	ppx;
	int		i;
//i = -1;
//	while (envp[++i])
//		printf("%s\n", envp[i]);
	ft_init(&ppx, envp);
	ft_fast_check(argc, argv, &ppx);
	ft_get_cmds(argc, argv, &ppx);
	ft_get_path(envp, &ppx);
	ft_piping(&ppx, argc, argv);
	i = -1;
	if (ppx.path)
		ft_free_tab(ppx.path);
	if (ppx.pp)
		free(ppx.pp);
	if (ppx.cmd)
	{
		while (ppx.cmd[++i])
			ft_free_tab(ppx.cmd[i]);
		free(ppx.cmd);
	}
	return (0);
}
