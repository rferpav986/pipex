/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauferna <rauferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:08:08 by rauferna          #+#    #+#             */
/*   Updated: 2023/12/21 17:39:18 by rauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	n;

	n = c;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == n)
			return ((char *) s);
		s++;
	}
	if (n == '\0')
		return ((char *) s);
	return (0);
}
