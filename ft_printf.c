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
		return (0);
	return (str[pos + 1]);
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
	//int		arg_number;
	char	mod;
	//va_list	args;
	//char	c_arg;

	i = 0;
	//arg_number = 0;
	//va_start(args, str);
	printf("str len = %ld\n", strlen(str));
	while (str[i] && next_percent_pos > -1)
	{
		next_percent_pos = get_next_perc_position(str, i);
		if (next_percent_pos > 0)
		{
			mod = get_next_modifier(str, next_percent_pos);
			printf("mod = %c, position = %d\n", mod, next_percent_pos + 1);
			i = next_percent_pos + 1;
		}
		
	}

	//va_end(args);

	return (i);
}

// va_list args
// va_start(args, count); 
// for (int i = 0; i < count; ++i) {
//     result += va_arg(args, int);
// }
// va_end(args);
// return result;
int	main(void)
{
	char	c;
	char	c1;
	int		d;
	int		result;

	c = 'a';
	c1 = 'b';
	d = 3;
	result = ft_printf("the first char = %c, the second = %c, the third = %d", c, c1, d);
	return (result == 0);
}