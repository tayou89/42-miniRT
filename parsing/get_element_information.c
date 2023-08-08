#include "parsing.h"

void	get_element_information(t_parsing *data, t_data *all)
{
	if (identifier == AMBIENT)
		get_ambient_information(data, all);
}

void	get_ambient_information(t_parsing *data, t_data *all)
{
	all->ambient.ratio = ft_atod(data->info[0], data);
}
