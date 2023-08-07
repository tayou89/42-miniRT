#include "parsing.h"

void	*free_2d_array(void **array)
{
	int	i;

	i = 0;
	while (array[i] != (void *) 0)
	{
		free(array[i]);
		array[i] = (void *) 0;
		i++;
	}
	free(array);
	array = (void *) 0;
	return (array);
}
