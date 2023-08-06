#include "parsing.h"

void	parse_file_data(t_parsing *data, t_data *all)
{
	char	*line;

	initialize_count(data);
	line = get_next_line(data->file.fd);
	if (line == (void *) 0)
		ft_parsing_error(MALLOC_ERROR, 1);
	while (line != (void *) 0)
	{
		parse_line(line, data, all);
		free(line);
		line = get_next_line(data->file.fd);
	}
	close(fd);
}

void	initialize_count(t_parsing *data)
{
	data->count.ambient = 0;
	data->count.camera = 0;
	data->count.light = 0;
	data->count.sp = 0;
	data->count.pl = 0;
	data->count.cy = 0;
}

void	parse_line(char *line, t_parsing *data, t_data *all)
{
	char	**split;
	int		identifier;

	split = ft_split(line, ' ');
	if (split == (void *) 0)
		ft_parsing_error(MALLOC_ERROR, 1);
	identifier = get_identifier(split[0]);
	count_element(identifier, data);
	check_element_exception(data);
	
}

int	get_identifier(char *identifier)
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
		ft_parsing_error(DATA_ERROR, 0);
}

void	count_element(int identifier, t_parsing *data)
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

void	check_element_exception(t_parsing *data)
{
	if (data->count.ambient > 1 || data->count.camera > 1
		|| data->count.light > 1)
		ft_parsing_error(DATA_ERROR, 0);
	if (data->count.sp < 0 || data->count.pl < 0
		|| data->count.cy < 0)
		ft_parsing_error(DATA_ERROR, 0);
}
