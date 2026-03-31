/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkazmina <tkazmina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:17:37 by tkazmina          #+#    #+#             */
/*   Updated: 2026/03/26 18:15:10 by tkazmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_next_perc_position(const char *str, int start_from)
{
	int pos;

	pos = start_from;
	while (str[pos])
	{
		if (str[pos] == '%')
			return (pos);
		pos++;
	}
	return (-1);
}

char	get_next_modifier(const char *str, int pos)
{
	if (str[pos + 1] == '\0')
		return (-1);
	return (str[pos + 1]);
}

int print_chunk(const char *str, int start, int end)
{
	int i;

	i = start;
	while (i <= end)
	{
		write(1, &str[i], 1);
		i++;
	}
	//write(1, (char *)"\n", 1);
	return (i - start);
}

void print_arg(char mod, va_list *args)
{
	if (mod == 'c')
	{
		char c_arg = va_arg(*args, int);
		write(1, &c_arg, 1);
	}
	else if (mod == 's')
	{
		char *s_arg = va_arg(*args, char *);
		write(1, s_arg, strlen(s_arg));
	}
	else if (mod == 'd' || mod == 'i')
	{
		int d_arg = va_arg(*args, int);
		char *d_str = ft_itoa(d_arg);
		write(1, d_str, strlen(d_str));
		free(d_str);
	}
	else if (mod == 'x')
	{
		int d_arg = va_arg(*args, int);
		char *d_str = itoa_base(d_arg, 16, 0);
		write(1, d_str, strlen(d_str));
		free(d_str);
	}
	else if (mod == 'X')
	{
		int d_arg = va_arg(*args, int);
		char *d_str = itoa_base(d_arg, 16, 1);
		write(1, d_str, strlen(d_str));
		free(d_str);
	}
}

// cspdiuxX%
// external functions: malloc, free, write, va_start, va_arg,
// va_copy, va_end
// • %c Prints a single character.
// • %s Prints a string (as defined by the common C convention).
// • %p The void * pointer argument has to be printed in hexadecimal format.
// • %d Prints a decimal (base 10) number.
// • %i Prints an integer in base 10.
// • %u Prints an unsigned decimal (base 10) number.
// • %x Prints a number in hexadecimal (base 16) lowercase format.
// • %X Prints a number in hexadecimal (base 16) uppercase format.
// • %% Prints a percent sign.
int	ft_printf(const char *str, ...)
{
	int		i;
	int		next_percent_pos;
	int		print_start;
	int		print_end;
	//int		arg_number;
	char	mod;
	long int str_len;
	va_list	args;
	//char	c_arg;

	i = 0;
	print_start = 0;
	print_end = 0;
	//arg_number = 0;
	va_start(args, str);
	str_len = strlen(str);
	printf("str len = %ld\n", str_len);
	while (str[i] && next_percent_pos > -1)
	{
		print_start = i;
		next_percent_pos = get_next_perc_position(str, i);
		print_end = next_percent_pos - 1;
		print_chunk(str, print_start, print_end);
		if (print_end < print_start)
			return (i);
		if (next_percent_pos > 0)
		{
			mod = get_next_modifier(str, next_percent_pos);
			print_arg(mod, &args);
			//printf("mod = %c, position = %d\n", mod, next_percent_pos + 1);
			i = next_percent_pos + 2;
		}
		
	}
	va_end(args);
	return (i);
}

int	main(void)
{
	char	c;
	char	c1;
	int		d;
	int		result;

	c = 'a';
	c1 = 'b';
	d = 3;
	ft_printf("%");
	result = ft_printf("the first arg = %c, the second = %c, the third = %d", c, c1, d);
	ft_printf("result = %x", 4779);
	ft_printf("str result = %s", "hello");
	printf("\nresult = %x\n", 4779);
	
	return (result == 0);
}