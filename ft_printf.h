/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkazmina <tkazmina@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:14:59 by tkazmina          #+#    #+#             */
/*   Updated: 2026/04/01 15:14:45 by tkazmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <stdint.h>

int		ft_printf(const char *str, ...);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *b, size_t n);
int		itoa_base(int number, int base, int uppercase);
int		write_unsigned(unsigned int num, const char *digits, int base);
int		write_percent(void);
int		write_pointer(uintptr_t ptr);
int		write_u(unsigned int u_arg);

#endif