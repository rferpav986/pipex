/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pipex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauferna <rauferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:09:46 by rauferna          #+#    #+#             */
/*   Updated: 2024/01/29 12:09:54 by rauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>

static int	repsc(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] && s[i] != c)
				i++;
			j++;
		}
	}
	return (j);
}

static char	*getarray(const char *s, char c)
{
	int		i;
	char	*res;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static char	*check_quotes(char *str, const char *s)
{
	char	*res;

	if (str[0] == 39)
	{
		res = getarray(s + 1, 39);
		free(str);
		return (res);
	}
	else if (str[0] == 34)
	{
		res = getarray(s + 1, 34);
		free(str);
		return (res);
	}
	return (str);
}

char	**free_mem(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	**ft_split_pipex(char const *s, char c)
{
	int		i;
	int		len;
	char	**res;

	i = 0;
	len = repsc(s, c);
	res = malloc(sizeof(char *) * ((len + 1)));
	if (!res)
		return (NULL);
	while (*s && i < len)
	{
		while (*s && *s == c)
			s++;
		res[i] = getarray(s, c);
		if (!res[i])
			return (free_mem(res));
		res[i] = check_quotes(res[i], s);
		s += ft_strlen(res[i]);
		i++;
		while (*s && *s != c)
			s++;
	}
	res[i] = 0;
	return (res);
}
