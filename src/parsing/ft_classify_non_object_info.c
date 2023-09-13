/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_classify_non_object_info.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:28:02 by tayou             #+#    #+#             */
/*   Updated: 2023/09/13 18:28:05 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	classify_ambient_information(char **info, t_parsing *parsing)
{
	check_information_count(info, AMBIENT, parsing);
	parsing->info.ratio = get_duplicated_string(info[0], parsing);
	parsing->info.color = get_splitted_array(info[1], ',', parsing);
	check_information_count(parsing->info.color, COLOR, parsing);
}

void	classify_camera_information(char **info, t_parsing *parsing)
{
	check_information_count(info, CAMERA, parsing);
	parsing->info.coordinate = get_splitted_array(info[0], ',', parsing);
	check_information_count(parsing->info.coordinate, COORDINATE, parsing);
	parsing->info.vector = get_splitted_array(info[1], ',', parsing);
	check_information_count(parsing->info.vector, VECTOR, parsing);
	parsing->info.fov = get_duplicated_string(info[2], parsing);
}

void	classify_light_information(char **info, t_parsing *parsing)
{
	check_information_count(info, LIGHT, parsing);
	parsing->info.coordinate = get_splitted_array(info[0], ',', parsing);
	check_information_count(parsing->info.coordinate, COORDINATE, parsing);
	parsing->info.ratio = get_duplicated_string(info[1], parsing);
}
