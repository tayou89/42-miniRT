#include "parsing.h"

void	get_element_information(int	identifier, char **info, t_data *all)
{
	if (identifier == AMBIENT)
		get_ambient_information(info, all);
}

void	get_ambient_information(char **info, t_data *all)
{
	all->ambient.ratio = ft_atod(info[1]);
}
