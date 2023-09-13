/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang <jhwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:37:43 by jhwang            #+#    #+#             */
/*   Updated: 2023/09/13 18:37:43 by jhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datasheet.h"

int	double_equal(double x, double y)
{
	if (fabs(x - y) <= EPSILON)
		return (TRUE);
	return (FALSE);
}
