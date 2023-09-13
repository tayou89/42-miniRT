/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_range_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:30:50 by tayou             #+#    #+#             */
/*   Updated: 2023/09/13 18:30:51 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

int	check_rgb_range(int color)
{
	if (color >= 0 && color <= 255)
		return (TRUE);
	else
		return (FALSE);
}

int	check_fov_range(int fov)
{
	if (fov > 0 && fov < 180)
		return (TRUE);
	else
		return (FALSE);
}

int	check_ratio_range(double ratio)
{
	if (ratio >= 0 && ratio <= 1)
		return (TRUE);
	else
		return (FALSE);
}

int	check_vector_range(double vector)
{
	if (vector >= -1 && vector <= 1)
		return (TRUE);
	else
		return (FALSE);
}
