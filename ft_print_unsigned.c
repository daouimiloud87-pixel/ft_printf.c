/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoui <mdaoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 08:34:25 by mdaoui            #+#    #+#             */
/*   Updated: 2026/11/14 14:38:17 by mdaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int n)
{
	long	nb;
	int		count;

	nb = n;
	count = 0;
	if (nb > 9)
		count += ft_print_unsigned(nb / 10);
	count += ft_putchar(nb % 10 + '0');
	return (count);
}
