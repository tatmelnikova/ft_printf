#include "ft_printf.h"

static void	fill_params(int n, size_t *num_chars, size_t *big_divider)
{
	size_t			count;
	size_t			divider;
	unsigned int	u_n;

	count = 1;
	if (n < 0)
	{
		count++;
		u_n = n * -1;
	}
	else
	{
		u_n = n;
	}
	divider = 1;
	while (u_n / 10 > 0)
	{
		count++;
		u_n = u_n / 10;
		divider = divider * 10;
	}
	*num_chars = count;
	*big_divider = divider;
}

static char	*fill_str(int n, size_t num_chars, size_t big_divider, char *result)
{
	unsigned int	i;
	unsigned int	u_n;
	unsigned int	next_num;

	i = 0;
	if (n < 0)
	{
		u_n = n * -1;
		result[0] = '-';
		i++;
	}
	else
		u_n = n;
	while (i < num_chars)
	{
		next_num = u_n / big_divider;
		result[i] = '0' + next_num;
		u_n = u_n - next_num * big_divider;
		big_divider = big_divider / 10;
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	size_t	num_chars;
	size_t	big_divider;
	char	*result;

	fill_params(n, &num_chars, &big_divider);
	result = malloc((num_chars + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result = fill_str(n, num_chars, big_divider, result);
	return (result);
}