/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoui <mdaoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 10:02:49 by mdaoui            #+#    #+#             */
/*   Updated: 2026/11/14 14:43:49 by mdaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_putnbr_base(unsigned long n, char *base);
int	ft_putchar(char c);
int	ft_printf_hex(unsigned int n, char format);
int	ft_print_ptr(void *ptr);
int	ft_print_unsigned(unsigned int n);
int	ft_print_str(char *str);
int	ft_print_nbr(int n);
int	ft_print_char(char c);
int	ft_handle_format(char c, va_list args);
int	ft_printf(const char *format, ...);

#endif
