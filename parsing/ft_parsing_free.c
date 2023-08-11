#include "parsing.h"

void	free_every_parsing_data(t_parsing *parsing)
{
	t_data	*data;

	data = &parsing->data;
	if (parsing->file.line != (void *) 0)
		parsing->file.line = free_1d_array((void *) parsing->file.line);
	if (parsing->line.info != (void *) 0)
		parsing->line.info = free_2d_array((void *) parsing->line.info);
	if (parsing->info.rgb != (void *) 0)
		parsing->info.rgb = free_2d_array((void *) parsing->info.rgb);
	if (parsing->info.xyz != (void *) 0)
		parsing->info.xyz = free_2d_array((void *) parsing->info.xyz);
	if (data->sphere != (void *) 0)
		data->sphere = free_linked_list((void *) data->sphere);
	if (data->plane != (void *) 0)
		data->plane = free_linked_list((void *) data->plane);
	if (data->cylinder != (void *) 0)
		data->cylinder = free_linked_list((void *) data->cylinder);
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

void	*free_linked_list(void *list)
{
	void	*head;

	head = list;
	while (
}
