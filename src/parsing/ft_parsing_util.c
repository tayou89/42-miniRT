/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:28:43 by tayou             #+#    #+#             */
/*   Updated: 2023/09/13 18:28:44 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	**get_splitted_array(char *array, char seperator, t_parsing *data)
{
	char	**splitted_array;

	splitted_array = ft_split(array, seperator);
	if (splitted_array == (void *) 0)
		ft_parsing_error(MALLOC_ERROR, 1, data);
	if (splitted_array[0] == (void *) 0)
		ft_parsing_error(DATA_ERROR, 0, data);
	return (splitted_array);
}

char	*get_duplicated_string(char *string, t_parsing *parsing)
{
	char	*duplicated_string;

	if (string == (void *) 0)
		ft_parsing_error(DATA_ERROR, 0, parsing);
	duplicated_string = ft_strdup(string);
	if (duplicated_string == (void *) 0)
		ft_parsing_error(MALLOC_ERROR, 1, parsing);
	return (duplicated_string);
}

void	check_information_count(char **string, int type, t_parsing *parsing)
{
	int	information_count;

	information_count = get_array_count((void *) string);
	if ((type == AMBIENT && information_count != AMBIENT_INFO_COUNT)
		|| (type == CAMERA && information_count != CAMERA_INFO_COUNT)
		|| (type == LIGHT && information_count != LIGHT_INFO_COUNT)
		|| (type == SPHERE && information_count != SPHERE_INFO_COUNT)
		|| (type == PLANE && information_count != PLANE_INFO_COUNT)
		|| (type == CYLINDER && information_count != CYLINDER_INFO_COUNT)
		|| (type == COLOR && information_count != COLOR_INFO_COUNT)
		|| (type == COORDINATE && information_count != COORDINATE_INFO_COUNT)
		|| (type == VECTOR && information_count != VECTOR_INFO_COUNT))
		ft_parsing_error(DATA_ERROR, 0, parsing);
}

int	get_array_count(void **array)
{
	int	array_count;
	int	i;

	if (array == (void *) 0)
		return (0);
	i = 0;
	while (array[i] != (void *) 0)
		i++;
	array_count = i;
	return (array_count);
}

int	get_sign(int *index, char *string)
{
	if (string[*index] == '-')
	{
		(*index)++;
		return (-1);
	}
	else if (string[*index] == '+')
	{
		(*index)++;
		return (1);
	}
	else
		return (1);
}
