#ifndef DATASHEET_H
# define DATASHEET_H

# define TRUE 1
# define FALSE 0

typedef struct s_count
{
	int	ambient;
	int	camera;
	int	light;
	int	sphere;
	int	plane;
	int	cylinder;
}	t_count;

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}t_vec;
typedef t_vec	t_point;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}t_color;

typedef struct s_sphere
{
	t_point	center;
	t_color	color;
	double	diameter;
	double	radius;
	struct s_sphere	*next;
}t_sphere;

typedef struct s_plane
{
	t_point	center;
	t_vec	vecter;
	t_color	color;
}t_plane;

typedef struct s_cylinder
{
	t_point	center;
	t_vec	vector;
	t_color	color;
	double	diameter;
	double	radius;
	double	height;
}t_cylinder;

typedef struct s_ambient
{
	double		ratio;
	t_color		color;
}t_ambient;

typedef struct s_camera
{
	t_point		view_point;
	t_vec		vector;
	int			fov;
}t_camera;

typedef struct s_light
{
	t_point	point;
	double	ratio;
	t_color	color;
}t_light;

typedef struct s_ray
{
	t_point	point;
	t_color	color;
}t_ray;

typedef struct s_data
{
	t_count		count;
	t_camera	camera;
	t_light		light;
	t_ambient	ambient;
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
}t_data;

#endif
