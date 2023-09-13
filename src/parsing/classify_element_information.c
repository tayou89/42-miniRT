/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classify_element_information.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:27:50 by tayou             #+#    #+#             */
/*   Updated: 2023/09/13 18:27:57 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	get_identifier(char *identifier, t_parsing *parsing);
static void	count_element(int identifier, t_data *data);
static void	check_element_exception(t_count count, t_parsing *parsing);

void	classify_element_information(char *line, t_parsing *parsing)
{
	parsing->line.info = get_splitted_array(line, ' ', parsing);
	get_identifier(parsing->line.info[0], parsing);
	count_element(parsing->info.identifier, &parsing->data);
	check_element_exception(parsing->data.count, parsing);
	if (parsing->info.identifier == AMBIENT)
		classify_ambient_information(&parsing->line.info[1], parsing);
	else if (parsing->info.identifier == CAMERA)
		classify_camera_information(&parsing->line.info[1], parsing);
	else if (parsing->info.identifier == LIGHT)
		classify_light_information(&parsing->line.info[1], parsing);
	else if (parsing->info.identifier == SPHERE)
		classify_sphere_information(&parsing->line.info[1], parsing);
	else if (parsing->info.identifier == PLANE)
		classify_plane_information(&parsing->line.info[1], parsing);
	else if (parsing->info.identifier == CYLINDER)
		classify_cylinder_information(&parsing->line.info[1], parsing);
	parsing->line.info = free_2d_array((void *) parsing->line.info);
}

static void	get_identifier(char *identifier, t_parsing *parsing)
{
	int	identifier_size;

	identifier_size = ft_strlen(identifier);
	if (ft_strncmp("A", identifier, identifier_size) == 0)
		parsing->info.identifier = AMBIENT;
	else if (ft_strncmp("C", identifier, identifier_size) == 0)
		parsing->info.identifier = CAMERA;
	else if (ft_strncmp("L", identifier, identifier_size) == 0)
		parsing->info.identifier = LIGHT;
	else if (ft_strncmp("sp", identifier, identifier_size) == 0)
		parsing->info.identifier = SPHERE;
	else if (ft_strncmp("pl", identifier, identifier_size) == 0)
		parsing->info.identifier = PLANE;
	else if (ft_strncmp("cy", identifier, identifier_size) == 0)
		parsing->info.identifier = CYLINDER;
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
}

static void	check_element_exception(t_count count, t_parsing *parsing)
{
	if (count.ambient > 1 || count.camera > 1 || count.light > 1)
		ft_parsing_error(DATA_ERROR, 0, parsing);
}
