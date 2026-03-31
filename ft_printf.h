/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkazmina <tkazmina@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:14:59 by tkazmina          #+#    #+#             */
/*   Updated: 2026/03/31 19:03:17 by tkazmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>

int		ft_printf(const char *str, ...);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *b, size_t n);
char 	*itoa_base(int number, int base, int uppercase);
void	write_num(char *buffer, char *digits, int num, int base);
void	write_unsigned(unsigned int num);
int		write_percent();
char	*write_pointer(unsigned long ptr);

#endif