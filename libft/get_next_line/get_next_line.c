/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauferna <rauferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:13:31 by rauferna          #+#    #+#             */
/*   Updated: 2023/12/21 17:48:34 by rauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_allocs1(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
	{
		s1 = ft_calloc(sizeof(char), 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

char	*ft_readfile(int fd, char *copy)
{
	char	*buffer;
	int		nbytes;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (0);
	nbytes = 1;
	while (!ft_strchr(copy, '\n') && nbytes > 0)
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[nbytes] = '\0';
		copy = ft_strjoin_allocs1(copy, buffer);
	}
	free(buffer);
	return (copy);
}

char	*ft_line(char *copy)
{
	int		i;
	char	*line;

	i = 0;
	if (!copy[i])
		return (NULL);
	while ((copy[i] && copy[i] != '\n'))
		i++;
	if (copy[i] == '\n')
		i++;
	line = ft_calloc((i + 1), sizeof(char));
	i = 0;
	while (copy[i])
	{
		line[i] = copy[i];
		if (copy[i] == '\n')
			return (line);
		i++;
	}
	return (line);
}

char	*ft_copyrest(char *copy)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	while (copy[i] && copy[i] != '\n')
		i++;
	if (!copy[i])
	{
		free(copy);
		return (NULL);
	}
	res = ft_calloc((ft_strlen(copy) - i + 1), sizeof(char));
	i++;
	while (copy[i])
		res[j++] = copy[i++];
	free(copy);
	return (res);
}

char	*get_next_line(int fd)
{
	static char		*copy[MAX_FD + 1];
	char			*line;

	if (fd == -1 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || fd > MAX_FD)
	{
		if (fd >= 0 && fd <= MAX_FD)
			free(copy[fd]);
		copy[fd] = NULL;
		return (NULL);
	}
	copy[fd] = ft_readfile(fd, copy[fd]);
	if (!copy[fd])
		return (NULL);
	line = ft_line(copy[fd]);
	copy[fd] = ft_copyrest(copy[fd]);
	if (copy[fd] == NULL || copy[fd][0] == '\0')
	{
		free(copy[fd]);
		copy[fd] = NULL;
	}
	return (line);
}
