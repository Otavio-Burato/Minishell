#include "libft.h"

void	ft_free(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

void	ft_free_array(char **ptr)
{
	int	len;

	len = 0;
	while (ptr[len])
	{
		ft_free(ptr[len]);
		len++;
	}
	ft_free(ptr);
}