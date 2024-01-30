/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauferna <rauferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:17:10 by rauferna          #+#    #+#             */
/*   Updated: 2023/12/21 17:10:58 by rauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_counts(char const *s1, char const *s2, char *str, int ls1)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[ls1] = s2[i];
		ls1++;
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		ls1;
	int		ls2;
	char	*res;

	if (s1 && s2)
	{
		ls1 = ft_strlen(s1);
		ls2 = ft_strlen(s2);
		res = (char *)malloc(sizeof(char) * (ls1 + ls2 + 1));
		if (!res)
			return (NULL);
		ft_counts(s1, s2, res, ls1);
		res[ls1 + ls2] = '\0';
		return (res);
	}
	return (NULL);
}
