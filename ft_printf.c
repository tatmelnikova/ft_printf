/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkazmina <tkazmina@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:14:28 by tkazmina          #+#    #+#             */
/*   Updated: 2026/04/01 15:14:58 by tkazmina         ###   ########.fr       */
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

int	print_chunk(const char *str, int start, int end)
{
	int i;

	i = start;
	if (end < 0)
	{
		while (str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
		return (i - start);
	}
	while (i <= end)
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i - start);
}

int	print_arg(char mod, va_list *args)
{
	int count;

	count = 0;
	if (mod == 'c')
	{
		char c_arg = va_arg(*args, int);
		write(1, &c_arg, 1);
		count = 1;
	}
	else if (mod == 's')
	{
		char *s_arg = va_arg(*args, char *);
		write(1, s_arg, strlen(s_arg));
		count = strlen(s_arg);
	}
	else if (mod == 'd' || mod == 'i')
	{
		int d_arg = va_arg(*args, int);
		count = itoa_base(d_arg, 10, 0);
	}
	else if (mod == 'x')
	{
		int d_arg = va_arg(*args, int);
		count += itoa_base(d_arg, 16, 0);
	}
	else if (mod == 'X')
	{
		int d_arg = va_arg(*args, int);
		count += itoa_base(d_arg, 16, 1);
	}
	else if (mod == 'u')
	{
		unsigned int	u_arg = va_arg(*args, unsigned int);
		write_u(u_arg);
	}
	else if (mod == '%')
	{
		write_percent();
	}
	else if (mod == 'p')
	{
		void *p_arg = va_arg(*args, void *);
		unsigned long	i_pointer = (unsigned long) p_arg;
		count += write_pointer(i_pointer);
	}
	return (count);
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
	char	mod;
	va_list	args;


	i = 0;
	print_start = 0;
	print_end = 0;

	va_start(args, str);
	next_percent_pos = 0;
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

static void	test_s(void)
{
	int		result;
	int		expected_res;

	result = ft_printf("string arg = %s\n", "test string");
	expected_res = printf("string arg = %s\n", "test string");
	printf("\nresult = %d, expected = %d\n", result, expected_res);
}

int	main(void)
{
	char	c;
	//char	c1;
	int		d;
	int		result;
	//int		expected_res;

	c = 'a';
	//c1 = 'b';
	d = 3;
	result = ft_printf("the first arg = %u\n", 12353);
	result = ft_printf("the first arg = %p\n", "test");
	ft_printf("%");
	result = ft_printf("the first arg = %c, the second = %d\n", c, d);
	result += ft_printf("int arg = %i\n", INT32_MIN);
	result += ft_printf("string arg = %s\n", "test string");
	result += ft_printf("x result = %x\n", 0x23ABC);
	result += ft_printf("x result = %X\n", 0x23ABC);
	result += ft_printf("\% result = %%\n");
	//expected_res = printf("the first arg = %c, the second = %d", c1, d);

	test_s();
	return (result);
}

//ft_printf("result = %x", 4779);
	//ft_printf("str result = %s", "hello");
	//printf("\nresult = %x\n", 4779);