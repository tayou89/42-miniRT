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
typedef t_vec3	t_point;
typedef t_vec3	t_color;

typedef struct s_sphere
{
	t_point	center;
	t_color	color;
	double	diameter;
	double	radius;
}t_sp;

typedef struct s_plane
{
	t_point	center;
	t_vec3	normal;
	t_color	color;
}t_pl;

typedef struct s_sylinder
{
	t_point	center;
	t_vec3	normal;
	t_color	color;
	double	diameter;
	double	radius;
	double	height;
}t_sy;

typedef struct s_ambient
{
	double	ratio;
	t_color	color;
}t_ambient;

typedef struct s_camera
{
	t_point	view_point;
	t_vec3	normal;
	int		fov;
}t_camera;

typedef struct s_light
{
	t_point	point;
	double	ratio;
	t_color	color;
}t_light;

typedef struct ray
{
	t_point	point;
	t_color	color;
}t_ray;
#endif