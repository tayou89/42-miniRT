#include "parsing_bonus.h"

void	free_every_parsing_data(t_parsing *parsing)
{
	t_data	*data;

	data = &parsing->data;
	free_info_data(&parsing->info);
	free_list(parsing->data.obj);
	free_list(parsing->data.light);
	if (parsing->line.info != (void *) 0)
		parsing->line.info = free_2d_array((void *) parsing->line.info);
	if (parsing->file.line != (void *) 0)
		parsing->file.line = free_1d_array((void *) parsing->file.line);
}

void	free_info_data(t_info *info)
{
	if (info->color != (void *) 0)
		info->color = free_2d_array((void *) info->color);
	if (info->coordinate != (void *) 0)
		info->coordinate = free_2d_array((void *) info->coordinate);
	if (info->vector != (void *) 0)
		info->vector = free_2d_array((void *) info->vector);
	if (info->ratio != (void *) 0)
		info->ratio = free_1d_array((void *) info->ratio);
	if (info->diameter != (void *) 0)
		info->diameter = free_1d_array((void *) info->diameter);
	if (info->height != (void *) 0)
		info->height = free_1d_array((void *) info->height);
	if (info->fov != (void *) 0)
		info->fov = free_1d_array((void *) info->fov);
	if (info->width != (void *) 0)
		info->width = free_1d_array((void *) info->width);
	if (info->length != (void *) 0)
		info->length = free_1d_array((void *) info->length);
}
