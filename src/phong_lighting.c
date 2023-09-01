#include "hit.h"

int	is_shadow(t_rec *rec, t_data *data)
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

t_color	get_ambient(t_ambient *amb)
{
	return (vmul_s(amb->color, amb->ratio));
}

t_color	get_specula(t_rec *rec, t_data *data)
{
	t_vec3	from_light;
	t_vec3	to_view;
	t_vec3	reflect;
	t_color specula;
	t_vec3	coef;

	from_light = vunit(vsub_v(rec->intersect, data->light.point));
	to_view = vunit(vmul_s(data->camera.normal, -1));
	reflect = vsub_v(from_light, vmul_s(rec->normal, vdot(from_light, rec->normal) * 2.0));
	coef.x = 2;
	coef.y = 0.5;
	coef.z = pow(fmax(vdot(to_view, reflect), 0.0), coef.x);
	specula = vmul_s(vmul_s(data->light.color, coef.y), coef.z);
	return (specula);
}

t_color	get_diffuse(t_rec *rec, t_data *data)
{
	t_color	diffuse;
	t_vec3	dir;
	double	t;

	dir = vunit(vsub_v(data->light.point, rec->intersect));
	t = fmax(vdot(rec->normal, dir), 0.0);
	diffuse = vmul_s(data->light.color, t);
	return (diffuse);
}

int	phong_lighting(t_rec *rec, t_data *data)
{
	t_color	light_color;
	int		color;
	double	shadow;

	shadow = 1;
	if (is_shadow(rec, data))
		shadow = 0.6;
	light_color = vset(0, 0, 0);
	light_color = vadd_v(light_color, get_ambient(&data->ambient));
	light_color = vadd_v(light_color, get_diffuse(rec, data));
	light_color = vadd_v(light_color, get_specula(rec, data));
	light_color = vmul_s(light_color, shadow);
	light_color = vmin(vmul_v(light_color, rec->albedo), vset(1, 1, 1));
	light_color = vmul_s(light_color, 255.999);
	color = color_get_trgb(0x0, light_color.x, light_color.y, light_color.z);
	return (color);
}
