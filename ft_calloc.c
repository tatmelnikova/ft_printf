
#include <stdlib.h>
#include "ft_printf.h"

// The calloc() function allocates memory for an array of nmemb 
// elements of size bytes each and returns a pointer to the allocated
// memory.  The memory is set to zero.  If nmemb or size is 0, 
// then calloc() returns either NULL, or a unique pointer value that
// can later be successfully passed to free().  If the multiplication
// of nmemb and size would result in integer overflow, then calloc()
// returns an error.
// The calloc() function returns a pointer to the allocated memory, 
// which is suitably aligned for any built-in type.  On error, these
// functions return NULL.  NULL may also be returned by a successful
// call to calloc() with nmemb or size equal to zero.
// SUBJECT:
// Depending on your current operating system, the ’calloc’ 
// function’s behavior may differ from its man page description. 
// You must follow this rule: If nmemb or size is 0, then calloc()
// returns a unique pointer value that can be successfully passed to
// free().
void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*result;

	result = (unsigned char *)malloc(nmemb * size);
	if (result != NULL)
	{
		ft_bzero(result, size * nmemb);
	}
	return (result);
}