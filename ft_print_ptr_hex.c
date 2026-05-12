/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabu <mbabu@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 02:25:50 by mbabu             #+#    #+#             */
/*   Updated: 2026/03/17 03:00:33 by mbabu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned long num, int limit)
{
	int		i;
	char	*base;

	i = 0;
	if (limit)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (num == 0)
		return (ft_putchar('0'));
	if (num >= 16)
		i = i + ft_printhex(num / 16, limit);
	i += ft_putchar(base[num % 16]);
	return (i);
}

int	ft_printpoint(void *ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	i += ft_putstr("0x");
	i += ft_printhex((unsigned long)ptr, 0);
	return (i);
}
