/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajazbuti <ajazbuti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 18:14:08 by ajazbuti          #+#    #+#             */
/*   Updated: 2022/02/26 16:26:51 by ajazbuti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_close_pipes(t_pipex *ppx, int pipe_fail)
{
	int	i;
	int	n;

	i = -1;
	n = ppx->cmd_nbr - 1;
	if (pipe_fail)
		n = pipe_fail;
	while (++i < n)
	{
		close(*(ppx->pp + 2 * i));
		close(*(ppx->pp + 2 * i + 1));
	}
	if (ppx->here_doc)
		close(ppx->pp1[0]);
}

static void	ft_clean_child(t_pipex *ppx, char *msg)
{
	if (ppx->cmd1)
		free(ppx->cmd1);
	ppx->cmd1 = NULL;
	ft_close_pipes(ppx, 0);
	ft_clean_exit(msg, ppx);
}

static void	ft_dup_dup(t_pipex *ppx, int i, int ac, char **av)
{
	if (!i)
	{
		if (ppx->here_doc)
			ft_dup2_dup2(ppx->pp1[0], *(ppx->pp + 2 * i + 1));
		else
		{
			ppx->fd[0] = open(av[1], O_RDONLY);
			if (ppx->fd[0] < 0)
				ft_clean_child(ppx, av[1]);
			ft_dup2_dup2(ppx->fd[0], *(ppx->pp + 2 * i + 1));
		}
	}
	if (i == ppx->cmd_nbr - 1)
	{
		if (ppx->here_doc)
			ppx->fd[1] = open(av[ac -1], O_CREAT | O_APPEND | O_WRONLY, 0666);
		else
			ppx->fd[1] = open(av[ac -1], O_CREAT | O_TRUNC | O_WRONLY, 0666);
		if (ppx->fd[1] < 0)
			ft_clean_child(ppx, av[ac - 1]);
		ft_dup2_dup2(*(ppx->pp + 2 * i - 2), ppx->fd[1]);
	}
	else
		ft_dup2_dup2(*(ppx->pp + 2 * i - 2), *(ppx->pp + 2 * i + 1));
}

static void	ft_child(t_pipex *ppx, int i, int ac, char **av)
{
	if (ppx->id == 0)
	{
		ppx->cmd1 = ft_get_cmnd(ppx, ppx->cmd[i][0]);
		ft_dup_dup(ppx, i, ac, av);
		ft_close_pipes(ppx, 0);
		if (!(ppx->cmd1))
		{
			ft_putstr_fd("ppx: command not found: ", 2);
			ft_putstr_fd(ppx->cmd[i][0], 2);
			ft_putstr_fd("\n", 2);
			ft_clean_exit(NULL, ppx);
		}
		execve(ppx->cmd1, ppx->cmd[i], ppx->ep);
	}
}

void	ft_piping(t_pipex *ppx, int ac, char **av)
{
	int	i;

	i = -1;
	ppx->pp = (int *)malloc(sizeof(int) * 2 * (ppx->cmd_nbr - 1));
	if (!(ppx->pp))
		ft_clean_exit("Malloc->kaputt", ppx);
	while (++i < ppx->cmd_nbr - 1)
	{
		if (pipe(ppx->pp + 2 * i))
		{
			if (i)
				ft_close_pipes(ppx, i);
			ft_clean_exit("pipe()->kaputt", ppx);
		}
	}
	i = -1;
	while (ppx->cmd[++i])
	{
		ppx->id = fork();
		if (ppx->id == -1)
			ft_clean_child(ppx, "fork()->kaputt");
		ft_child(ppx, i, ac, av);
	}
	ft_close_pipes(ppx, 0);
	waitpid(-1, NULL, 0);
}
