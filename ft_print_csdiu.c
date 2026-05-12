/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_csdiu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabu <mbabu@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 01:29:57 by mbabu             #+#    #+#             */
/*   Updated: 2026/03/17 02:07:31 by mbabu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putnbr(int n)
{
	int	c;

	c = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n == 0)
		return (ft_putchar('0'));
	if (n < 0)
	{
		c = c + ft_putchar('-');
		c = c + ft_putnbr(-n);
		return (c);
	}
	if (n >= 10)
	{
		c += ft_putnbr(n / 10);
		c += ft_putchar(n % 10 + '0'); 
	}
	else
		c += ft_putchar(n + '0');
	return (c);
}

int	ft_putstr(char *st)
{
	unsigned int	i;

	i = 0;
	if (!st)
		return (write(1, "(null)", 6));
	while (st[i] != '\0')
	{
		write(1, &st[i], 1);
		i++;
	}
	return (i);
}

int	ft_unsignputnbr(unsigned int i)
{
	int	count;

	count = 0;
	if (i == 0)
		return (ft_putchar('0'));
	if (i >= 10)
	{
		count += ft_unsignputnbr(i / 10);
		count += ft_putchar(i % 10 + '0');
	}
	else
		count += ft_putchar(i + '0');
	return (count);
}
