/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauferna <rauferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:31:03 by rauferna          #+#    #+#             */
/*   Updated: 2024/01/30 18:51:35 by rauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	error_cnf(char *command)
{
	ft_printfd2("pipex: %s: command not found\n", command);
	exit(EXIT_FAILURE);
}

int	error_cnfpath(char *command)
{
	ft_printfd2("pipex: %s: command not found\n", command);
	exit(127);
}

int	error_fnf(char *file)
{
	ft_printfd2("pipex: %s: No such file or directory\n", file);
	exit(0);
}

int	error_usage(void)
{
	ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> ... <file2>\n", 2);
	exit(127);
}
