/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoui <mdaoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 08:19:36 by mdaoui            #+#    #+#             */
/*   Updated: 2026/11/13 10:44:22 by mdaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_nbr(int n)
{
    long nb;
    int count;
    
    nb = n;
    count = 0;
    if(nb < 0)
    {
       count += ft_putchar('-');
        nb = -nb;
        
    }
    if(nb > 9)
        count += ft_print_nbr(nb / 10);
    count +=  ft_putchar(nb % 10 + '0');
    return (count);
}