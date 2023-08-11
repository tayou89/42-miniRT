#include "parsing.h"

static void	get_line_identifier(char *identifier, t_parsing *data);
static void	count_element(int identifier, t_data *data);
static void	check_element_exception(t_parsing *datat_data *all);
static void	check_information_count(int	id, char **info, t_parsing *parsing);

void	check_identifier(t_parsing *parsing)
{
	get_line_identifier(data->line.info[0], parsing);
	count_element(parsing->line.identifier, &parsing->data);
	check_element_exception(parsing->data.count, parsing);
	check_information_count(identifier, parsing->line.info, parsing);
}

static void	get_line_identifier(char *identifier, t_parsing *parsing)
{
	int	identifier_size;

	identifier_size = ft_strlen(identifier);
	if (ft_strncmp("A", identifier, identifier_size) == 0)
		parsing->line.identifer = AMBIENT;
	else if (ft_strncmp("C", identifier, identifier_size) == 0)
		parsing->line.identifer = CAMERA;
	else if (ft_strncmp("L", identifier, identifier_size) == 0)
		parsing->line.identifer = LIGHT;
	else if (ft_strncmp("sp", identifier, identifier_size) == 0)
		parsing->line.identifer = SPHERE;
	else if (ft_strncmp("pl", identifier, identifier_size) == 0)
		parsing->line.identifer = PLANE;
	else if (ft_strncmp("cy", identifier, identifier_size) == 0)
		parsing->line.identifer = CYLINDER;
	else
		ft_parsing_error(DATA_ERROR, 0, parsing);
}

static void	count_element(int identifier, t_data *data)
{
	if (identifier == AMBIENT)
		data->count.ambient++;
	else if (identifier == CAMERA)
		data->count.camera++;
	else if (identifier == LIGHT)
		data->count.light++;
	else if (identifier == SPHERE)
		data->count.sp++;
	else if (identifier == PLANE)
		data->count.pl++;
	else if (identifier == CYLINDER)
		data->count.cy++;
}

static void	check_element_exception(t_count count, t_parsing *parsing)
{
	if (count.ambient > 1 || count.camera > 1 || count.light > 1)
		ft_parsing_error(DATA_ERROR, 0, parsing);
	if (count.sp < 0 || count.pl < 0 || count.cy < 0)
		ft_parsing_error(DATA_ERROR, 0, parsing);
}

static void	check_information_count(int id, char **info, t_parsing *parsing)
{
	int	identifier;
	int	info_count;

	identifier = id;
	info_count = get_array_count((void *) info);
	if ((identifier == AMBIENT || identifier == CAMERA) && info_count != 3)
		ft_parsing_error(DATA_ERROR, 0, parsing);
	else if ((identifier == LIGHT || identifier == SPHERE
			|| identifier == PLANE) && info_count != 4)
		ft_parsing_error(DATA_ERROR, 0, parsing);
	else if (identifier == CYLINDER && info_count != 6)
		ft_parsing_error(DATA_ERROR, 0, parsing);
}
