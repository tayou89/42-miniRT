#include "image_bonus.h"

static int	is_shadow(t_rec *rec, t_light *light, t_data *data)
{
	t_rec	temp;
	t_ray	ray;
	t_vec3	hitp;

	hitp = vadd_v(rec->intersect, vmul_s(rec->normal, EPSILON));
	temp = *rec;
	temp.tmax = vlen(vsub_v(light->point, temp.intersect));
	ray = ray_init(hitp, vsub_v(light->point, temp.intersect));
	if (hit_object(data, ray, &temp))
		return (TRUE);
	return (FALSE);
}

static t_color	get_ambient(t_ambient *amb)
{
	return (vmul_s(amb->color, amb->ratio));
}

static t_color	get_specula(t_rec *rec, t_light *light, t_camera camera)
{
	t_vec3	from_light;
	t_vec3	to_view;
	t_vec3	reflect;
	t_color	specula;
	double	t;

	from_light = vunit(vsub_v(rec->intersect, light->point));
	to_view = vunit(vmul_s(camera.normal, -1));
	reflect = vsub_v(from_light, \
				vmul_s(rec->normal, vdot(from_light, rec->normal) * 2.0));
	t = pow(fmax(vdot(to_view, reflect), 0.0), EXPONENT);
	specula = vmul_s(vmul_s(light->color, SHINY), t);
	return (specula);
}

static t_color	get_diffuse(t_rec *rec, t_light	*light)
{
	t_color	diffuse;
	t_vec3	dir;
	double	t;

	dir = vunit(vsub_v(light->point, rec->intersect));
	t = fmax(vdot(rec->normal, dir), 0.0);
	diffuse = vmul_s(light->color, t);
	return (diffuse);
}

int	phong_lighting(t_rec *rec, t_data *data)
{
	t_list	*light;
	t_color	light_color;
	int		color;
	double	shadow;

	light_color = vset(0, 0, 0);
	light = data->light;
	while (light)
	{
		shadow = 1;
		if (is_shadow(rec, light->element, data))
			shadow = SHADOW;
		light_color = vadd_v(light_color, get_diffuse(rec, light->element));
		light_color = vadd_v(light_color, get_specula(rec, light->element, data->camera));
		light_color = vmul_s(light_color, shadow);
		light = light->next;
	}
	light_color = vadd_v(light_color, get_ambient(&data->ambient));
	light_color = vmin(vmul_v(light_color, rec->albedo), vset(1, 1, 1));
	light_color = vmul_s(light_color, 255.999);
	color = color_get_trgb(0x0, light_color.x, light_color.y, light_color.z);
	return (color);
}
