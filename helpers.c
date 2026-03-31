/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkazmina <tkazmina@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:15:14 by tkazmina          #+#    #+#             */
/*   Updated: 2026/03/31 18:56:53 by tkazmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void flip_buf(char *buf, int size)
{
	int i;
	char temp;

	for (i = 0; i < size / 2; i++)
	{
		temp = buf[i];
		buf[i] = buf[size - i - 1];
		buf[size - i - 1] = temp;
	}
}

void write_num(char *buffer, char *digits, int num, int base)
{
	int i;
	unsigned int unum;

	i = 0;
	if (num < 0)
	{
		buffer[i] = '-';
		i ++;
		unum = num * -1;
	}
	else
		unum = num;
	while (unum > 0)
	{
		buffer[i] = digits[unum % base];
		unum = unum / base;
		i++;
	}
	flip_buf(buffer, i);
	buffer[i] = '\0';
}

char *itoa_base(int number, int base, int uppercase)
{
	char *digits = "0123456789abcdef";
	char *ucase_digits = "0123456789ABCDEF";
	char buffer[33];
	if (uppercase)
		write_num(buffer, ucase_digits, number, base);
	else
		write_num(buffer, digits, number, base);
	return (strdup(buffer));
	
}