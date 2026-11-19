/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoui <mdaoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 08:45:02 by mdaoui            #+#    #+#             */
/*   Updated: 2026/11/19 11:46:50 by mdaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long n, char *base)
{
	int	base_len;
	int	count;
	int	ret;

	base_len = 0;
	count = 0;
	while (base[base_len])
		base_len++;
	if (base_len < 2)
		return (0);
	if (n >= (unsigned long)base_len)
	{
		ret = ft_putnbr_base(n / base_len, base);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	ret = ft_putchar(base[n % base_len]);
	if (ret == -1)
		return (-1);
	return (count + ret);
}
