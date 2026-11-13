/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoui <mdaoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 10:01:54 by mdaoui            #+#    #+#             */
/*   Updated: 2026/11/13 11:02:55 by mdaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_handle_format(char c, va_list args)
{
    
    if ( c == 'c')
        return(ft_print_char(va_arg(args, int)));
    if ( c == 's')
        return(ft_print_str(va_arg(args, char *)));
    if ( c == 'p')
        return(ft_print_ptr(va_arg(args, void *)));
    if ( c == 'd')
        return(ft_print_nbr(va_arg(args, int)));
     if ( c == 'i')
         return(ft_print_nbr(va_arg(args, int)));
     if ( c == 'u')
        return(ft_print_unsigned(va_arg(args, unsigned int)));
     if ( c == 'x')
        return(ft_printf_hex(va_arg(args, unsigned int),'x'));
     if ( c == 'X')
        return(ft_printf_hex(va_arg(args, unsigned int),'X'));
     if ( c == '%')
        return(ft_putchar('%'));
    return(0);
}