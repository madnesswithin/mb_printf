/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabu <mbabu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 20:42:18 by mbabu             #+#    #+#             */
/*   Updated: 2026/03/17 02:59:56 by mbabu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_specifier(va_list *args, char type)
{
	if (type == 'c')
		return (ft_putchar(va_arg(*args, int)));
	if (type == '%')
		return (ft_putchar('%'));
	if (type == 's')
		return (ft_putstr(va_arg(*args, char *)));
	if (type == 'u')
		return (ft_unsignputnbr(va_arg(*args, unsigned int)));
	if (type == 'd' || type == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	if (type == 'x')
		return (ft_printhex(va_arg(*args, unsigned int), 0));
	if (type == 'X')
		return (ft_printhex(va_arg(*args, unsigned int), 1));
	if (type == 'p')
		return (ft_printpoint(va_arg(*args, void *)));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%' && s[i + 1])
		{
			len += ft_type_specifier(&args, s[i + 1]);
			i++;
		}
		else
			len += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (len);
}
