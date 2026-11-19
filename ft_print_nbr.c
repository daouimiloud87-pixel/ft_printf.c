/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoui <mdaoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 08:19:36 by mdaoui            #+#    #+#             */
/*   Updated: 2026/11/19 11:41:28 by mdaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_digit_safe(char c, int *count)
{
	int	ret;

	ret = ft_putchar(c);
	if (ret == -1)
		return (-1);
	*count += ret;
	return (0);
}

int	ft_print_nbr(int n)
{
	long	nb;
	int		count;
	int		ret;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		if (ft_put_digit_safe('-', &count) == -1)
			return (-1);
		nb = -nb;
	}
	if (nb > 9)
	{
		ret = ft_print_nbr(nb / 10);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	if (ft_put_digit_safe(nb % 10 + '0', &count) == -1)
		return (-1);
	return (count);
}
