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
// prints given string symbols from start to the next % or
// the end of line.
// returns number of symbols printed, eol is not included
int	print_chunk(const char *str, int start)
{
	int i;

	i = start;

	while (str[i] && str[i] != '%')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i - start);
}

int	print_arg(char mod, va_list *args)
{
	if (mod == 'c')
		return ft_putchar(va_arg(*args, int));
	else if (mod == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (mod == 'd' || mod == 'i')
		return (write_base(va_arg(*args, int), 10, 0));
	else if (mod == 'x')
		return (write_base(va_arg(*args, int), 16, 0));
	else if (mod == 'X')
		return (write_base(va_arg(*args, int), 16, 1));
	else if (mod == 'u')
		return (write_u( va_arg(*args, unsigned int)));
	else if (mod == '%')
		return (write_percent());
	else if (mod == 'p')
		return (write_pointer((unsigned long)va_arg(*args, void *)));
	return (0);
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
	int		next_percent_pos;
	int		print_start;
	char	mod;
	va_list	args;
	int		printed_count;

	print_start = 0;
	va_start(args, str);
	next_percent_pos = 0;
	printed_count = 0;
	while (str[print_start] && next_percent_pos > -1)
	{
		next_percent_pos = get_next_perc_position(str, print_start);
		printed_count += print_chunk(str, print_start);
		if (next_percent_pos >= 0)
		{
			mod = get_next_modifier(str, next_percent_pos);
			printed_count += print_arg(mod, &args);
			print_start = next_percent_pos + 2;
		}
	}
	va_end(args);
	return (printed_count);
}

static void	test_s(void)
{
	int		result;
	int		expected_res;

	result = ft_printf("0");
	expected_res = printf("0");
	printf(__func__);
	printf(" result = %d, expected = %d\n", result, expected_res);
	result = ft_printf("\n");
	expected_res = printf("\n");
	printf(__func__);
	printf(" result = %d, expected = %d\n", result, expected_res);
	result = ft_printf("%s\n", "test string");
	expected_res = printf("%s\n", "test string");
	printf(__func__);
	printf(" result = %d, expected = %d\n", result, expected_res);
	result = ft_printf("string arg = %s\n", "test string");
	expected_res = printf("string arg = %s\n", "test string");
	printf(__func__);
	printf(" result = %d, expected = %d\n", result, expected_res);

	result = ft_printf("string arg = %s smth else\n", "test string");
	expected_res = printf("string arg = %s smth else\n", "test string");
	printf(__func__);
	printf(" result = %d, expected = %d\n", result, expected_res);
}

static void test_u()
{
	int		result;
	int		expected_res;
	
	result = ft_printf("the first arg = %u smth else\n", 12353);
	expected_res = printf("the first arg = %u smth else\n", 12353);
	printf(__func__);
	printf(" result = %d, expected = %d\n", result, expected_res);
}

static void test_p()
{
	int		result;
	int		expected_res;
	
	result = ft_printf("ft_printf the first arg = %p smth else\n", "test");
	expected_res = printf("printf the first arg = %p smth else\n", "test");
	printf(__func__);
	printf(" result = %d, expected = %d\n", result, expected_res);
}

static void test_c()
{
	int		result;
	int		expected_res;
	char c = 'a';
	char d = 3;
	
	result = ft_printf("the first arg = %c, the second = %d qwer\n", c, d);
	expected_res = printf("the first arg = %c, the second = %d qwer\n", c, d);
	printf(__func__);
	printf(" result = %d, expected = %d\n", result, expected_res);
}

static void test_i()
{
	int		result;
	int		expected_res;
	
	result = ft_printf("int arg = %i asdfw\n", INT32_MIN);
	expected_res = printf("int arg = %i asdfw\n", INT32_MIN);
	printf(__func__);
	printf(" result = %d, expected = %d\n", result, expected_res);
}

static void test_x()
{
	int		result;
	int		expected_res;
	
	result = ft_printf("x result = %x bnld , 87 \n", 0x23ABC);
	expected_res = printf("x result = %x bnld , 87 \n", 0x23ABC);
	printf(__func__);
	printf(" result = %d, expected = %d\n", result, expected_res);

	result = ft_printf("x result = %X bnld , 87 \n", 0x23ABC);
	expected_res = printf("x result = %X bnld , 87 \n", 0x23ABC);
	printf(__func__);
	printf(" result = %d, expected = %d\n", result, expected_res);
}

static void test_percent()
{
	int		result;
	int		expected_res;
	
	result = ft_printf("%% res = %%\n");
	expected_res = printf("%% res = %%\n");
	printf(__func__);
	printf(" result = %d, expected = %d\n", result, expected_res);

	result = ft_printf("%");
	expected_res = 0;
	printf(__func__);
	printf(" result = %d, expected = %d\n", result, expected_res);
}

int	main(void)
{
	test_s();
	test_u();
	test_p();
	test_c();
	test_i();
	test_x();
	test_percent();
	return (0);
}
