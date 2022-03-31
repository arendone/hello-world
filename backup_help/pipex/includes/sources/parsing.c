/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajazbuti <ajazbuti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:04:54 by ajazbuti          #+#    #+#             */
/*   Updated: 2022/02/26 15:22:20 by ajazbuti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_dup2_dup2(int inpt, int outpt)
{
	dup2(inpt, 0);
	dup2(outpt, 1);
}

void	ft_get_path(char **envp, t_pipex *ppx)
{
	int	i;

	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			ppx->path = ft_split(envp[i] + 5, ':');
			if (ppx->path == NULL)
				ft_clean_exit("path split failed", ppx);
		}
	}
}

void	ft_get_cmds(int ac, char **av, t_pipex *ppx)
{
	int	i;
	int	j;

	i = 2;
	if (ppx->here_doc)
		i = 3;
	ppx->cmd = (char ***)malloc((ac - i) * sizeof(char **));
	if (!ppx->cmd)
		ft_clean_exit("Command parsing failure", ppx);
	j = 0;
	while (i < ac - 1)
	{
		ppx->cmd[j] = ft_split(av[i], ' ');
		if (!ppx->cmd[j][0])
			errno = EIO;
		if (!ppx->cmd[j][0])
			ft_clean_exit("Empty string", ppx);
		i++;
		j++;
	}
	ppx->cmd[j] = NULL;
	while (ppx->cmd[++ppx->cmd_nbr])
		continue ;
}

char	*ft_get_cmnd(t_pipex *ppx, char *cmd)
{
	char	*cmnd;
	char	*pth;
	int		i;

	i = -1;
	if (!access(cmd, X_OK))
		return (ft_strdup(cmd));
	while (ppx->path[++i])
	{
		pth = ft_strjoin(ppx->path[i], "/");
		cmnd = ft_strjoin(pth, cmd);
		free(pth);
		if (!access(cmnd, X_OK))
			return (cmnd);
		else
			free(cmnd);
	}
	return (NULL);
}
