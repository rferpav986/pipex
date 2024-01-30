/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauferna <rauferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:04:49 by rauferna          #+#    #+#             */
/*   Updated: 2023/12/21 18:29:36 by rauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_getlen(int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		len++;
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static int	ft_unsigned_getlen(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

int	ft_putnbrr(int nb)
{
	int	len;

	len = ft_getlen(nb);
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		ft_putcharr('-');
		nb = -nb;
		if (nb >= 10)
		{
			ft_putnbrr(nb / 10);
		}
		ft_putcharr('0' + nb % 10);
	}
	else if (nb >= 10)
	{
		ft_putnbrr(nb / 10);
		ft_putcharr('0' + nb % 10);
	}
	else
		ft_putcharr('0' + nb);
	return (len);
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb >= 10)
	{
		ft_putnbr_unsigned(nb / 10);
		ft_putcharr('0' + nb % 10);
	}
	else
		ft_putcharr('0' + nb);
	len = ft_unsigned_getlen(nb);
	return (len);
}
