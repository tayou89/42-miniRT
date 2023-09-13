/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:31:00 by tayou             #+#    #+#             */
/*   Updated: 2023/09/13 18:31:01 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

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
