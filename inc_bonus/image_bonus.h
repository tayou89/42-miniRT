/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang <jhwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:36:58 by jhwang            #+#    #+#             */
/*   Updated: 2023/09/13 18:36:58 by jhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_BONUS_H
# define IMAGE_BONUS_H

# include "initialize_bonus.h"
# include "hit_bonus.h"

void	draw_image_by_ray_tracing(t_mlx *mlx, t_data *data);
int		phong_lighting(t_rec *rec, t_data *data, t_ray ray);
int		color_get_trgb(int t, int r, int g, int b);
void	put_pixel(t_mlx *mlx, int x, int y, int color);
t_color	get_checker_color(const t_sp *sphere, t_point intersect);
t_color	tex_get_color_value(t_rec *rec, const t_sp *sp);
#endif