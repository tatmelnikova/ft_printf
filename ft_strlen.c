/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkazmina <tkazmina@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 13:59:36 by tkazmina          #+#    #+#             */
/*   Updated: 2026/04/14 14:13:24 by tkazmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// The strlen() function calculates the length of the string pointed
// to by s, excluding the terminating null byte ('\0').
size_t	ft_strlen(const char *str)
{
	char	c;
	int		count;

	c = *str;
	count = 0;
	while (c != '\0')
	{
		count++;
		str++;
		c = *str;
	}
	return (count);
}
