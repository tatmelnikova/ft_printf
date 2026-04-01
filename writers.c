/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkazmina <tkazmina@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:15:23 by tkazmina          #+#    #+#             */
/*   Updated: 2026/04/01 15:04:55 by tkazmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_unsigned(unsigned int num, const char *digits, int base)
{
	char	c;
	int		count;

	count = 0;
	if (num >= (unsigned int)base)
	{
		count += write_unsigned(num / base, digits, base);
	}
	c = digits[num % base];
	write(1, &c, 1);
	return (count + 1);
}

int	write_percent(void)
{
	write(1, "%", 1);
	return (1);
}

int write_pointer(uintptr_t ptr)
{
	const char	*digits = "0123456789abcdef";
	int			count;

	write(1, "0x", 2);
	count = write_unsigned((unsigned long)ptr, digits, 16);
	return (count);
}

int	write_u(unsigned int u_arg)
{
	const char	*digits = "0123456789abcdef";
	int			count;

	count = write_unsigned(u_arg, digits, 10);
	return (count);
}

