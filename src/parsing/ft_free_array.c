/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:28:10 by tayou             #+#    #+#             */
/*   Updated: 2023/09/13 18:28:12 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	*free_2d_array(void **array)
{
	int	i;

	i = 0;
	while (array[i] != (void *) 0)
	{
		array[i] = free_1d_array(array[i]);
		i++;
	}
	free(array);
	array = (void *) 0;
	return (array);
}

void	*free_1d_array(void *array)
{
	free(array);
	array = (void *) 0;
	return (array);
}
