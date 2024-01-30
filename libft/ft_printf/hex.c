/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauferna <rauferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:24:11 by rauferna          #+#    #+#             */
/*   Updated: 2023/12/21 18:32:27 by rauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

static int	ft_getlen_hex(unsigned long long int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

int	ft_lowerhex(unsigned long long int s)
{
	int	len;

	len = 0;
	if (s >= 16)
	{
		ft_lowerhex(s / 16);
		ft_putcharr("0123456789abcdef"[(unsigned char) s % 16]);
	}
	else
		ft_putcharr("0123456789abcdef"[(unsigned char) s]);
	len = ft_getlen_hex(s);
	return (len);
}

int	ft_upperhex(unsigned long long int s)
{
	int		len;

	len = 0;
	if (s >= 16)
	{
		ft_upperhex(s / 16);
		ft_putcharr("0123456789ABCDEF"[(unsigned char) s % 16]);
	}
	else
		ft_putcharr("0123456789ABCDEF"[(unsigned char) s]);
	len = ft_getlen_hex(s);
	return (len);
}
