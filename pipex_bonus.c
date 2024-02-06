/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauferna <rauferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:25:38 by rauferna          #+#    #+#             */
/*   Updated: 2024/02/01 10:01:28 by rauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"

void	parent_process_doc(char **argv, int *fd, char **envp, int file)
{
	pid_t	pid;

	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	file = openfile(argv[5], 3);
	dup2(file, STDOUT_FILENO);
	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	else if (pid == 0)
	{
		callexecve(argv[4], envp);
		exit(EXIT_SUCCESS);
	}
	waitpid(pid, NULL, 0);
}

void	call_get_next_line(int file, char **av, char **envp, int *fd)
{
	char	*line;

	close(fd[0]);
	while (1)
	{
		write(2, "pipex heredoc> ", 15);
		line = get_next_line(0);
		if ((ft_strncmp(line, av[2], ft_strlen(av[2])) == 0)
			&& ft_strlen(line + 1) == ft_strlen(av[2]))
			exit(EXIT_SUCCESS);
		write(fd[1], line, ft_strlen(line));
	}
	close(file);
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	file = open(av[5], O_RDONLY);
	dup2(file, STDIN_FILENO);
	callexecve(av[3], envp);
}

void	here_doc_bonus(char **av, char **envp)
{
	int		fd[2];
	int		file;
	pid_t	pid;

	file = openfile(av[5], 3);
	if (pipe(fd) == -1)
		exit(EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	else if (pid == 0)
		call_get_next_line(file, av, envp, fd);
	waitpid(pid, NULL, 0);
	parent_process_doc(av, fd, envp, file);
}

void	child_process_bonus(char *av, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		exit(EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	else if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		callexecve(av, envp);
		waitpid(pid, NULL, 0);
		exit(EXIT_SUCCESS);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
	}
}

int	main(int ac, char **av, char **envp)
{
	int		i;
	int		infile;
	int		outfile;
	pid_t	pid;

	i = 2;
	if (ac == 6 && ft_strncmp(av[1], "here_doc", 8) == 0)
		here_doc_bonus(av, envp);
	else if (ac >= 5)
	{
		infile = openfile(av[1], 1);
		outfile = openfile(av[ac - 1], 2);
		dup2(infile, STDIN_FILENO);
		while (i < ac - 2)
			child_process_bonus(av[i++], envp);
		dup2(outfile, STDOUT_FILENO);
		pid = fork();
		if (pid == -1)
			exit(EXIT_FAILURE);
		else if (pid == 0)
			callexecve(av[i], envp);
	}
	else
		error_usage();
	exit(EXIT_SUCCESS);
}
