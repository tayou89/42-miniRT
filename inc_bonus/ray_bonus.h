/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang <jhwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:37:07 by jhwang            #+#    #+#             */
/*   Updated: 2023/09/13 18:37:07 by jhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_BONUS_H
# define RAY_BONUS_H
# include "utils_vec_bonus.h"

t_ray	ray_init(t_point orig, t_vec3 dir);
t_point	ray_at(t_ray ray, double t);
t_ray	get_primary_ray(t_camera camera, t_viewport viewport, t_point pixel);
#endif