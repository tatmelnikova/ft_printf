/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkazmina <tkazmina@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:15:23 by tkazmina          #+#    #+#             */
/*   Updated: 2026/03/31 19:02:06 by tkazmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_unsigned(unsigned int num)
{
	char	c;

	if (num >= 10)
	{
		write_unsigned(num / 10);
		//c = '0' + num % 10;
		//write(1, &c, 1);
		
	}
	c = '0' + num % 10;
	write(1, &c, 1);
}

int	write_percent()
{
	write(1, "%", 1);
	return (1);
}

char	*write_pointer(unsigned long ptr)
{
	char *digits = "0123456789abcdef";
	char buffer[33];

	write(1, "0x", 2);
	write_num(buffer, digits, ptr, 16);
	return (strdup(buffer));
}