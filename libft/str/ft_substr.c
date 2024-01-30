/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauferna <rauferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:57:22 by rauferna          #+#    #+#             */
/*   Updated: 2023/12/21 17:11:32 by rauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;

	if (!s)
		return (0);
	i = ft_strlen(s);
	if (len <= 0 || start > i)
		return (ft_strdup(""));
	if (i - start < len)
		len = i - start;
	res = malloc (sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, (char *)(s + start), len + 1);
	return (res);
}

/*
int	main(void)
{
	char const	s[];

	s[] = "hola buenas tardes por la tarde";
	printf("%s\n", ft_substr(s, 10, 3));
}
*/