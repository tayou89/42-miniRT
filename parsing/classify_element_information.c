#include "parsing."

static int	get_identifier(char *identifier, t_parsing *parsing);
static void	count_element(int identifier, t_data *data);
static void	check_element_exception(t_count count, t_parsing *parsing);

void	classify_element_information(char *line, t_parsing *parsing)
{
	int	identifier;

	parsing->line.info = get_splitted_array(line, ' ', parsing);
	identifier = get_identifier(parsing->line.info[0], parsing);
	parsing->info.identifier = identifier;
	count_element(identifier, &parsing->data);
	check_element_exception(parsing->data.count, parsing);
	if (identifier == AMBIENT)
		classify_ambient_information(&parsing->line.info[1], parsing);
	else if (identifier == CAMERA)
		classify_camera_information(&parsing->line.info[1], parsing);
	else if (identifier == LIGHT)
		classify_light_information(&parsing->line.info[1], parsing);
	else if (identifier == SPHERE)
		classify_sphere_information(&parsing->line.info[1], parsing);
	else if (identifier == PLANE)
		classify_plane_information(&parsing->line.info[1], parsing);
	else if (identifier == CYLINDER)
		classify_cylinder_information(&parsing->line.info[1], parsing);
	parsing->line.info = free_2d_array((void *) parsing->line.info);
}

static int	get_identifier(char *identifier, t_parsing *parsing)
{
	int	identifier_size;

	if (identifier == (void *) 0)
		ft_parsing_error(DATA_ERROR, 0, parsing);
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
		data->count.sphere++;
	else if (identifier == PLANE)
		data->count.plane++;
	else if (identifier == CYLINDER)
		data->count.cylinder++;
}

static void	check_element_exception(t_count count, t_parsing *parsing)
{
	if (count.ambient > 1 || count.camera > 1 || count.light > 1)
		ft_parsing_error(DATA_ERROR, 0, parsing);
}
