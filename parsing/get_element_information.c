#include "parsing.h"

void	get_element_information(t_parsing *data, t_data *all)
{
	if (identifier == AMBIENT)
		get_ambient_information(data, all);
	data->line.info = free_2d_array(data->line.info);
}

void	get_ambient_information(t_parsing *data, t_data *all)
{
	all->ambient.ratio = ft_atod(data->info[1], data);
	all->ambient.color = get_color_data(data->info[2], data);
}
