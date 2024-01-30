/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfd2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauferna <rauferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:59:56 by rauferna          #+#    #+#             */
/*   Updated: 2024/01/28 21:51:54 by rauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdarg.h>

static int	typeformat(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putcharr(va_arg(args, int));
	else if (c == 's')
		len += ft_putstrr((va_arg(args, char *)));
	else if (c == '%')
		len += ft_putcharr('%');
	return (len);
}

int	ft_putcharr(char c)
{
	return (write(2, &c, 1));
}

int	ft_putstrr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (write (2, "(null)", 6));
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_printfd2(char const *s, ...)
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
