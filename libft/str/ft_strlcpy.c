/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauferna <rauferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:20:57 by rauferna          #+#    #+#             */
/*   Updated: 2023/12/21 17:11:04 by rauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	length_src;
	size_t	i;

	length_src = 0;
	while (src[length_src])
		length_src++;
	if (n)
	{
		i = -1;
		if (length_src + 1 < n)
			while (++i < length_src)
				dest[i] = src[i];
		else
			while (++i < n - 1)
				dest[i] = src[i];
		dest[i] = '\0';
	}
	return (length_src);
}
