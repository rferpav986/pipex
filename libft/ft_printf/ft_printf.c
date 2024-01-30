/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauferna <rauferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:59:56 by rauferna          #+#    #+#             */
/*   Updated: 2023/12/21 18:17:36 by rauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	typeformat(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putcharr(va_arg(args, int));
	else if (c == 'i' || c == 'd')
		len += ft_putnbrr(va_arg(args, int));
	else if (c == 's')
		len += ft_putstrr((va_arg(args, char *)));
	else if (c == 'p')
		len += ft_pointer((va_arg(args, void *)));
	else if (c == 'u')
		len += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (c == 'X')
		len += ft_upperhex(va_arg(args, unsigned int));
	else if (c == 'x')
		len += ft_lowerhex(va_arg(args, unsigned int));
	else if (c == '%')
		len += ft_putcharr('%');
	return (len);
}

int	ft_printf(char const *s, ...)
{
	long int			i;
	long int			len;
	va_list				args;

	i = 0;
	len = 0;
	va_start(args, s);
	if (write (1, "", 0) != 0)
		return (-1);
	while (s[i])
	{
		if (s[i] == '%')
			len += typeformat(s[++i], args);
		else
			len += ft_putcharr(s[i]);
		i++;
	}
	va_end(args);
	return (len);
}
