/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoui <mdaoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 09:25:15 by mdaoui            #+#    #+#             */
/*   Updated: 2026/11/13 11:06:58 by mdaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int ft_printf_hex(unsigned int n, char format)
{
    if(format == 'x')
        return (ft_putnbr_base(n,"0123456789abcdef"));
    else if(format == 'X')
        return(ft_putnbr_base(n, "0123456789ABCDEF"));

    return(0);
}
int ft_print_ptr(void *ptr)
{
    int i;

    i = 0;
    if (!ptr)
        return(ft_print_str("(nil)"));
    i += ft_print_str("0x");
    i += ft_putnbr_base((unsigned long)ptr,"0123456789abcdef");
    return (i);
    
}