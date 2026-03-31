#include "ft_printf.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sstr;
	size_t	i;

	i = 0;
	while (start > 0 && *s)
	{
		s++;
		start--;
	}
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	sstr = malloc(sizeof(char) * (len + 1));
	if (!sstr)
		return (NULL);
	while (i < len && *s)
	{
		sstr[i] = *s++;
		i++;
	}
	sstr[i] = '\0';
	return (sstr);
}