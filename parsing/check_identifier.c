#include "parsing.h"

static int		get_line_identifier(char *identifier, t_parsing *data);
static t_count	count_element(int identifier, t_count count);
static void		check_element_exception(t_parsing *datat_data *all);
static void		check_information_count(int	identifier, char **split);

void	check_identifier(t_parsing *data, t_data *all)
{
	data->line.identifier = get_line_identifier(data->line.info[0], data);
	all->count = count_element(data->line.identifier, all->count);
	check_element_exception(all->count, data);
	check_information_count(identifier, data->line.info, data);
}

static int	get_line_identifier(char *identifier, t_parsing *data)
{
	int	identifier_size;

	identifier_size = ft_strlen(identifier);
	if (ft_strncmp("A", identifier, identifier_size) == 0)
		return (AMBIENT);
	else if (ft_strncmp("C", identifier, identifier_size) == 0)
		return (CAMERA);
	else if (ft_strncmp("L", identifier, identifier_size) == 0)
		return (LIGHT);
	else if (ft_strncmp("sp", identifier, identifier_size) == 0)
		return (SPHERE);
	else if (ft_strncmp("pl", identifier, identifier_size) == 0)
		return (PLANE);
	else if (ft_strncmp("cy", identifier, identifier_size) == 0)
		return (CYLINDER);
	else
		ft_parsing_error(DATA_ERROR, 0, data);
}

static t_count	count_element(int identifier, t_count count)
{
	if (identifier == AMBIENT)
		count.ambient++;
	else if (identifier == CAMERA)
		count.camera++;
	else if (identifier == LIGHT)
		count.light++;
	else if (identifier == SPHERE)
		count.sp++;
	else if (identifier == PLANE)
		count.pl++;
	else if (identifier == CYLINDER)
		count.cy++;
	return (count);
}

static void	check_element_exception(t_count count, t_parsing *data)
{
	if (count.ambient > 1 || count.camera > 1 || count.light > 1)
		ft_parsing_error(DATA_ERROR, 0, data);
	if (count.sp < 0 || count.pl < 0 || count.cy < 0)
		ft_parsing_error(DATA_ERROR, 0, data);
}

static void	check_information_count(t_parsing *data)
{
	int	identifier;
	int	info_count;

	identifier = data->line.identifier;
	info_count = get_array_count((void *) data->line.info);
	if ((identifier == AMBIENT || identifier == CAMERA) && info_count != 3)
		ft_parsing_error(DATA_ERROR, 0, data);
	else if ((identifier == LIGHT || identifier == SPHERE
			|| identifier == PLANE) && info_count != 4)
		ft_parsing_error(DATA_ERROR, 0, data);
	else if (identifier == CYLINDER && info_count != 6)
		ft_parsing_error(DATA_ERROR, 0, data);
}
