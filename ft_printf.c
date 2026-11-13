/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoui <mdaoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 10:43:20 by mdaoui            #+#    #+#             */
/*   Updated: 2026/11/13 11:14:35 by mdaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
    va_list args;
    int i;
    int count ;
    
    if(!format)
        return (-1);
    i = 0;
    count = 0;
    va_start(args, format);
    while(format[i])
    {
        if(format[i] == '%' && format[i + 1])
        {
            count += ft_handle_format(format[i + 1],args);
            i += 2;
        }
        else
        {
        count += ft_putchar(format[i]);
        i++;
        }
    }
    va_end(args);
    return (count);
}
