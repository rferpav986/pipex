/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauferna <rauferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:02:48 by rauferna          #+#    #+#             */
/*   Updated: 2023/12/21 18:16:15 by rauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

/// @brief main function of ft_printf it has typeformat that is a function 
// wich select the type of format, and go to another specific function 
// depending what is one position more of the %
/// @param s 
/// @param  
/// @return lenght
int				ft_printf(char const *s, ...);

/// @brief take anumber and print it with the function write using recursivity
/// @param nb 
/// @return the lenght of the number
int				ft_putnbrr(int nb);

/// @brief take only positive numbers and print it with the function 
// write using recursivity
/// @param nb 
/// @return the lenght of the number
int				ft_putnbr_unsigned(unsigned int nb);

/// @brief taka a string and print with the function write
/// @param str 
/// @return the lenght of the string
int				ft_putstrr(char *str);

/// @brief take a character and print it with the function write
/// @param n 
/// @return 1 if its true 0 if is not
int				ft_putcharr(char n);

/// @brief Is the function for %p that prints the number with 
/// 0x and his converision in long long unsigned to hexadecimal
/// @param ptr 
/// @return the lenght of the number in hexadecimal
int				ft_pointer(void *ptr);

/// @brief it takes a decimal number and converts it in hexadecimal
/// if c is X use upper, but if c is x use lowers
/// @param s 
/// @param c 
/// @return 
int				ft_upperhex(unsigned long long int s);

int				ft_lowerhex(unsigned long long int s);

#endif