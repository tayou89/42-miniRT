#include "parsing.h"

void	*free_2d_array(void **array)
{
	int	i;

	i = 0;
	while (array[i] != (void *) 0)
	{
		array[i] = free_1d_array(array[i]);
		i++;
	}
	free(array);
	array = (void *) 0;
	return (array);
}

void	*free_1d_array(void *array)
{
	free(array);
	array = (void *) 0;
	return (array);
}
