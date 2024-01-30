/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauferna <rauferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:20:35 by rauferna          #+#    #+#             */
/*   Updated: 2023/12/21 17:11:01 by rauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	idst;
	unsigned int	isrc;
	unsigned int	srcsize;
	unsigned int	dsize;

	idst = 0;
	isrc = 0;
	while (dst[idst] != '\0')
		idst++;
	dsize = ft_strlen(dst);
	srcsize = ft_strlen(src);
	if (dstsize <= dsize)
		return (srcsize + dstsize);
	while (src[isrc] != '\0' && isrc < (dstsize - dsize - 1))
	{
		dst[idst] = src[isrc];
		idst++;
		isrc++;
	}
	dst[idst] = '\0';
	return (srcsize + dsize);
}
