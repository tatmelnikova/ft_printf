/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkazmina <tkazmina@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:15:14 by tkazmina          #+#    #+#             */
/*   Updated: 2026/04/14 14:10:20 by tkazmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_base(int number, int base, int uppercase)
{
	const char		*digits = "0123456789abcdef";
	const char		*ucase_digits = "0123456789ABCDEF";
	unsigned long	u_number;
	int				negative;

	negative = 0;
	if (number < 0)
	{
		u_number = number * -1;
		write(1, "-", 1);
		negative = 1;
	}
	else
		u_number = number;
	if (uppercase)
		return (write_unsigned(u_number, ucase_digits, base) + negative);
	else
		return (write_unsigned(u_number, digits, base) + negative);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	if (!s)
	{
		if (write (1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (s && s[count])
	{
		write(1, &s[count], 1);
		count++;
	}
	return (count);
}
