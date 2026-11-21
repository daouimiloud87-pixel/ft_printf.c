/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoui <mdaoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 08:34:25 by mdaoui            #+#    #+#             */
/*   Updated: 2026/11/21 11:57:11 by mdaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int n)
{
	int	count;
	int	ret;

	count = 0;
	if (n > 9)
	{
		ret = ft_print_unsigned(n / 10);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	ret = ft_putchar(n % 10 + '0');
	if (ret == -1)
		return (-1);
	return (count + ret);
}
