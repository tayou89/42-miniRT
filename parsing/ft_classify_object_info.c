#include "parsing.h"

void	classify_sphere_information(char **info, t_parsing *parsing)
{
	check_information_count(info, SPHERE, parsing);
	parsing->info.coordinate = get_splitted_array(info[0], ',', parsing);
	check_information_count(parsing->info.coordinate, COORDINATE, parsing);
	parsing->info.diameter = get_duplicated_string(info[1]);
	parsing->info.color = get_splitted_array(info[2], ',', parsing);
	check_information_count(parsing->info.color, COLOR, parsing);
}

void	classify_plane_information(char **info, t_parsing *parsing)
{
	check_information_count(info, PLANE, parsing);
	parsing->info.coordinate = get_splitted_array(info[0], ',', parsing);
	check_information_count(parsing->info.coordinate, COORDINATE, parsing);
	parsing->info.vector = get_splitted_array(info[1], ',', parsing);
	check_information_count(parsing->info.vector, VECTOR, parsing);
	parsing->info.color = get_splitted_array(info[2], ',', parsing);
	check_information_count(parsing->info.color, COLOR, parsing);
}

void	classify_cylinder_information(char **info, t_parsing *parsing)
{
	check_information_count(info, CYLINDER, parsing);
	parsing->info.coordinate = get_splitted_array(info[0], ',', parsing);
	check_information_count(parsing->info.coordinate, COORDINATE, parsing);
	parsing->info.vector = get_splitted_array(info[1], ',', parsing);
	check_information_count(parsing->info.vector, VECTOR, parsing);
	parsing->info.diameter = get_duplicated_string(info[2]);
	parsing->info.height = get_duplicated_string(info[3]);
	parsing->info.color = get_splitted_array(info[4], ',', parsing);
	check_information_count(parsing->info.color, COLOR, parsing);
}
