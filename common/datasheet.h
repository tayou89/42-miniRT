#ifndef DATASHEET_H
# define DATASHEET_H

# define TRUE 1
# define FALSE 0

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}t_vec3;
typedef t_vec3	t_point3;

typedef struct s_color3
{
	int	r;
	int	g;
	int	b;
}t_color3;

typedef struct s_sphere
{
	t_point3	center;
	t_color3	color;
	double		diameter;
	double		radius;
}t_sp;

typedef struct s_plane
{
	t_point3	center;
	t_vec3		normal;
	t_color3	color;
}t_pl;

typedef struct s_cylinder
{
	t_point3	center;
	t_vec3		normal;
	t_color3	color;
	double		diameter;
	double		radius;
	double		height;
}t_cy;

typedef struct s_ambient
{
	double		ratio;
	t_color3	color;
}t_ambient;

typedef struct s_camera
{
	t_point3	view_point;
	t_vec3		normal;
	int			fov;
}t_camera;

typedef struct s_light
{
	t_point3	point;
	double		ratio;
	t_color3	color;
}t_light;

typedef struct s_ray
{
	t_point3	point;
	t_color3	color;
}t_ray;

typedef struct s_data
{
	t_camera	camera;
	t_light		light;
	t_ambient	ambient;
	t_sp		sp;
	t_pl		pl;
	t_cy		cy;
}t_data;
#endif
