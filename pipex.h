/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauferna <rauferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:25:02 by rauferna          #+#    #+#             */
/*   Updated: 2024/01/30 19:04:17 by rauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include "libft/libft.h"

void	callexecve(char *command, char **envp);

char	*find_pathcmd(char **envp, char *command);

void	child_process(char **argv, int *fd, char **envp);

void	parent_process(char **argv, int *fd, char **envp);

int		openfile(char *file, int type);

char	**free_mem(char **str);

char	**ft_split_pipex(char const *s, char c);

int		ft_printfd2(char const *s, ...);

int		ft_putcharr(char c);

int		ft_putstrr(char *str);

int		error_cnfpath(char *command);

int		error_usage(void);

int		error_cnf(char *command);

int		error_fnf(char *file);