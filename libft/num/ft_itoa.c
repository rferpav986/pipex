/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauferna <rauferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:11:02 by rauferna          #+#    #+#             */
/*   Updated: 2023/12/21 17:09:35 by rauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_isnegative(int *n)
{
	if (*n < 0)
	{
		*n = -*n;
		return (1);
	}
	return (0);
}

static int	ft_getlen(int nb, int len)
{
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*res;
	int				len;
	int				ne;

	len = 0;
	len = ft_getlen(n, len);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	ne = ft_isnegative(&n);
	len += ne;
	res = (char *)malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	while (len)
	{
		len--;
		res[len] = n % 10 + '0';
		n = n / 10;
	}
	if (ne == 1)
		res[len] = '-';
	return (res);
}
/*
int main(void)
{
	int a = 34534;
    char *result = ft_itoa(a);
    if (result) {
        printf("%s\n", result);
        free(result);
    } else {
        printf("Error: no se pudo asignar memoria.\n");
    }
    return 0;
}∫
*/