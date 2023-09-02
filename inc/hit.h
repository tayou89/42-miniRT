#ifndef HIT_H
# define HIT_H

# include "ray.h"
# define EXPONENT 64
# define SHADOW 0.5
# define SHINY 0.8

int	color_get_trgb(int t, int r, int g, int b);
int	hit_object(t_data *data, t_ray primary, t_rec *rec);
int	pl_hit(t_list *obj, t_ray ray, t_rec *rec);
int	sp_hit(t_list *obj, t_ray ray, t_rec *rec);
int	cy_hit(t_list *obj, t_ray ray, t_rec *rec);
int	cy_hit_surface(t_cy *cy, t_ray ray, t_rec *rec);
int	phong_lighting(t_rec *rec, t_data *scene);
#endif