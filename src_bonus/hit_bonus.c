/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang <jhwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:39:11 by jhwang            #+#    #+#             */
/*   Updated: 2023/09/13 18:39:12 by jhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_bonus.h"

static void	set_hit_func(int (*hit_func[])(t_list *, t_ray, t_rec *))
{
	hit_func[PLANE] = pl_hit;
	hit_func[SPHERE] = sp_hit;
	hit_func[CYLINDER] = cy_hit;
	hit_func[CONE] = co_hit;
	hit_func[CHECKER] = sp_hit;
}

int	hit_object(t_data *data, t_ray primary, t_rec *rec)
{
	t_list	*world;
	int		is_hit;
	int		(*hit_func[5])(t_list *, t_ray, t_rec *);

	set_hit_func(hit_func);
	world = data->obj;
	is_hit = FALSE;
	while (world)
	{
		if (hit_func[world->type](world, primary, rec))
			is_hit = TRUE;
		world = world->next;
	}
	return (is_hit);
}
