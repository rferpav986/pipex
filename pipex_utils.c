/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauferna <rauferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:25:05 by rauferna          #+#    #+#             */
/*   Updated: 2024/04/11 10:02:09 by rauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	openfile(char *file, int type)
{
	int	fd[2];

	if (type == 1)
	{
		fd[0] = open(file, O_RDONLY, 0644);
		if (fd[0] == -1)
			error_fnf(file);
		return (fd[0]);
	}
	else if (type == 2)
	{
		fd[1] = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd[1] == -1)
			error_fnf(file);
		return (fd[1]);
	}
	else if (type == 3)
	{
		fd[1] = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd[1] == -1)
			error_fnf(file);
		return (fd[1]);
	}
	exit(EXIT_FAILURE);
}

void	callexecve(char *command, char **envp)
{
	char	**args;
	char	*exec1;

	args = ft_split_pipex(command, ' ');
	if (ft_strncmp(command, "./", 2) != 0)
		exec1 = find_pathcmd(envp, args[0]);
	else
		exec1 = ft_strdup(command);
	if (execve(exec1, args, envp) == -1)
	{
		free(exec1);
		free_mem(args);
		error_cnf(command);
	}
}

char	*find_pathcmd(char **envp, char *command)
{
	int		i;
	char	*path;
	char	*path_line;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	path_line = envp[i] + 5;
	i = 0;
	while (path_line[i])
	{
		path = ft_split(path_line, ':')[i];
		path = ft_strjoin(path, "/");
		path = ft_strjoin(path, command);
		if (path == NULL)
		{
			free(path);
			error_cnfpath(command);
		}
		if (access(path, F_OK) == 0)
			return (path);
		i++;
	}
	return (NULL);
}
