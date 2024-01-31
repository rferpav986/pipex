/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauferna <rauferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:25:14 by rauferna          #+#    #+#             */
/*   Updated: 2024/01/31 12:31:10 by rauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"

//fd[0] = read
//fd[1] = write

void	child_process(char **av, int *fd, char **envp)
{
	int		infile;

	infile = openfile(av[1], 1);
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[0]);
	callexecve(av[2], envp);
}

void	parent_process(char **av, int *fd, char **envp)
{
	int		outfile;
	pid_t	pid;

	outfile = openfile(av[4], 2);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	else if (pid == 0)
		callexecve(av[3], envp);
	waitpid(pid, NULL, 0);
}

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (ac == 5)
	{
		if (pipe(fd) == -1)
			exit(EXIT_FAILURE);
		pid = fork();
		if (pid == -1)
			exit(EXIT_FAILURE);
		else if (pid == 0)
			child_process(av, fd, envp);
		parent_process(av, fd, envp);
	}
	else
	{
		ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 2);
		return (127);
	}
	exit(EXIT_SUCCESS);
}
