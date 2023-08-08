#include "parsing.h"

static void	get_line_identifier(char *identifier, t_parsing *data);
static void	count_element(int identifier, t_data *all);
static void	check_element_exception(t_parsing *datat_data *all);
static void	check_information_count(int	identifier, char **split);

void	check_identifier(t_parsing *data, t_data *all)
{
	get_line_identifier(data->line.info[0], data);
	count_element(data->line.identifier, all);
	check_element_exception(data, all);
	check_information_count(identifier, data->line.string);
}

static void	get_line_identifier(char *identifier, t_parsing *data)
{
	int	identifier_size;

	identifier_size = ft_strlen(identifier);
	if (ft_strncmp("A", identifier, identifier_size) == 0)
		data->line.identifier = AMBIENT;
	else if (ft_strncmp("C", identifier, identifier_size) == 0)
		data->line.identifier = CAMERA;
	else if (ft_strncmp("L", identifier, identifier_size) == 0)
		data->line.identifier = LIGHT;
	else if (ft_strncmp("sp", identifier, identifier_size) == 0)
		data->line.identifier = SPHERE;
	else if (ft_strncmp("pl", identifier, identifier_size) == 0)
		data->line.identifier = PLANE;
	else if (ft_strncmp("cy", identifier, identifier_size) == 0)
		data->line.identifier = CYLINDER;
	else
		ft_parsing_error(DATA_ERROR, 0, data);
}

static void	count_element(int identifier, t_data *all)
{
	if (identifier == AMBIENT)
		all->count.ambient++;
	else if (identifier == CAMERA)
		all->count.camera++;
	else if (identifier == LIGHT)
		all->count.light++;
	else if (identifier == SPHERE)
		all->count.sp++;
	else if (identifier == PLANE)
		all->count.pl++;
	else if (identifier == CYLINDER)
		all->count.cy++;
}

static void	check_element_exception(t_parsing *datat_data *all)
{
	if (all->count.ambient > 1 || all->count.camera > 1
		|| all->count.light > 1)
		ft_parsing_error(DATA_ERROR, 0);
	if (all->count.sp < 0 || all->count.pl < 0
		|| all->count.cy < 0)
		ft_parsing_error(DATA_ERROR, 0, data);
}

static void	check_information_count(t_parsing *data)
{
	int	identifier;
	int	info_count;
	int	i;

	identifier = data->line.identifier;
	i = 0;
	while (data->line.info[i] != (void *) 0)
		i++;
	info_count = i;
	if ((identifier == AMBIENT || identifier == CAMERA) && info_count != 3)
		ft_parsing_error(DATA_ERROR, 0, data);
	else if ((identifier == LIGHT || identifier == SPHERE
			|| identifier == PLANE) && info_count != 4)
		ft_parsing_error(DATA_ERROR, 0, data);
	else if (identifier == CYLINDER && info_count != 6)
		ft_parsing_error(DATA_ERROR, 0, data);
}
