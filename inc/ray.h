/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang <jhwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:36:39 by jhwang            #+#    #+#             */
/*   Updated: 2023/09/13 18:36:40 by jhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H
# include "utils_vec.h"

t_ray	ray_init(t_point orig, t_vec3 dir);
t_point	ray_at(t_ray ray, double t);
t_ray	get_primary_ray(t_camera camera, t_viewport viewport, t_pixel pixel);
#endif