/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_lighting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang <jhwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:38:34 by jhwang            #+#    #+#             */
/*   Updated: 2023/09/14 17:00:01 by jhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"

static int	is_shadow(t_rec *rec, t_data *data)
{
	t_rec	temp;
	t_ray	light;
	t_vec3	hitp;

	hitp = vadd_v(rec->intersect, vmul_s(rec->normal, EPSILON));
	temp = *rec;
	temp.tmax = vlen(vsub_v(data->light.point, temp.intersect));
	light = ray_init(hitp, vsub_v(data->light.point, temp.intersect));
	if (hit_object(data, light, &temp))
		return (TRUE);
	return (FALSE);
}

static t_color	get_ambient(t_ambient *amb)
{
	return (vmul_s(amb->color, amb->ratio));
}

static t_color	get_specula(t_rec *rec, t_data *data, t_ray ray)
{
	t_vec3	from_light;
	t_vec3	to_view;
	t_vec3	reflect;
	t_color	specula;
	double	t;

	from_light = vunit(vsub_v(data->light.point, rec->intersect));
	to_view = vunit(vmul_s(ray.dir, -1));
	reflect = vsub_v(vmul_s(rec->normal, vdot(from_light, rec->normal) * 2.0), \
					from_light);
	t = pow(fmax(vdot(to_view, reflect), 0.0), EXPONENT);
	specula = vmul_s(vmul_s(data->light.color, SHINY), t);
	return (specula);
}

static t_color	get_diffuse(t_rec *rec, t_data *data)
{
	t_color	diffuse;
	t_vec3	dir;
	double	t;

	dir = vunit(vsub_v(data->light.point, rec->intersect));
	t = fmax(vdot(rec->normal, dir), 0.0);
	diffuse = vmul_s(data->light.color, t);
	return (diffuse);
}

int	phong_lighting(t_rec *rec, t_data *data, t_ray ray)
{
	t_color	light_color;
	int		color;
	double	shadow;

	shadow = 1;
	if (is_shadow(rec, data))
		shadow = 0;
	light_color = vset(0, 0, 0);
	light_color = vadd_v(light_color, get_diffuse(rec, data));
	light_color = vadd_v(light_color, get_specula(rec, data, ray));
	light_color = vmul_s(light_color, shadow);
	light_color = vmul_s(light_color, data->light.ratio * 2);
	light_color = vadd_v(light_color, get_ambient(&data->ambient));
	light_color = vmin(vmul_v(light_color, rec->albedo), vset(1, 1, 1));
	light_color = vmul_s(light_color, 255.999);
	color = color_get_trgb(0x0, light_color.x, light_color.y, light_color.z);
	return (color);
}
