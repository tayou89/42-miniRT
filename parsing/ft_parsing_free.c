#include "parsing.h"

void	free_every_parsing_data(t_parsing *data)
{
	if (data->file.line != (void *) 0)
		data->file.line = free_1d_array((void *) data->file.line);
	if (data->line.string != (void *) 0)
		data->line.string = free_2d_array((void *) data->line.string);
}

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
