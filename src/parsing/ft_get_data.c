#include "parsing.h"

double	get_ratio_data(char *string, t_parsing *parsing)
{
	double	ratio;

	ratio = get_double(string, parsing);
	if (check_ratio_range(ratio) == FALSE)
		ft_parsing_error(DATA_ERROR, 0, parsing);
	return (ratio);
}

int	get_fov_data(char *string, t_parsing *parsing)
{
	int	fov;

	fov = get_integer(string, parsing);
	if (check_fov_range(fov) == FALSE)
		ft_parsing_error(DATA_ERROR, 0, parsing);
	return (fov);
}

t_color	get_color_data(char **string, t_parsing *parsing)
{
	t_color	color;

	color.x = get_integer(string[0], parsing);
	color.y = get_integer(string[1], parsing);
	color.z = get_integer(string[2], parsing);
	if (check_rgb_range(color.x) == FALSE
		|| check_rgb_range(color.y) == FALSE
		|| check_rgb_range(color.z) == FALSE)
		ft_parsing_error(DATA_ERROR, 0, parsing);
	return (color);
}

t_vec3	get_vector_data(char **string, t_parsing *parsing)
{
	t_vec3	vector;

	vector.x = get_double(string[0], parsing);
	vector.y = get_double(string[1], parsing);
	vector.z = get_double(string[2], parsing);
	if (check_vector_range(vector.x) == FALSE
		|| check_vector_range(vector.y) == FALSE
		|| check_vector_range(vector.z) == FALSE)
		ft_parsing_error(DATA_ERROR, 0, parsing);
	if (vlen(vector) == 0)
		ft_parsing_error(DATA_ERROR, 0, parsing);
	return (vector);
}

t_point	get_coordinate_data(char **string, t_parsing *parsing)
{
	t_point	coordinate;

	coordinate.x = get_double(string[0], parsing);
	coordinate.y = get_double(string[1], parsing);
	coordinate.z = get_double(string[2], parsing);
	return (coordinate);
}
