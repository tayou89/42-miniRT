#ifndef DATASHEET_H
# define DATASHEET_H

# define TRUE 1
# define FALSE 0

typedef struct s_count
{
	int	ambient;
	int	camera;
	int	light;
}t_count;

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
	t_point			center;
	t_color			color;
	double			diameter;
	double			radius;
	struct s_sphere	*next;
	struct s_sphere	*prev;
}t_sp;

typedef struct s_plane
{
	t_point			center;
	t_vec3			normal;
	t_color			color;
	struct s_plane	*next;
	struct s_plane	*prev;
}t_pl;

typedef struct s_cylinder
{
	t_point				center;
	t_vec3				normal;
	t_color				color;
	double				top;
	double				base;
	double				diameter;
	double				radius;
	double				height;
	struct s_cylinder	*next;
	struct s_cylinder	*prev;
}t_cy;

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

typedef struct s_ray
{
	t_point	orig;
	t_vec3	dir;
}t_ray;

typedef	struct s_pixel
{
	t_point	point;
	t_color	color;
}t_pixel;

typedef	struct s_viewport
{
	double	width;
	double	height;
	t_point	center;
	t_point	left_top;
	t_point	starting;					// 뷰포트 상에서 실제 primary_ray를 쏘는 시작지점
	t_vec3	right_vector;				
	t_vec3	down_vector;
	t_vec3	right_unit;					// right_vector / WIN_WIDTH
	t_vec3	down_unit;					// down_vector / WIN_HEIGHT
	t_vec3	axis_vector;				// 카메라 회전 축이 되는 기준 벡터
}t_viewport;

typedef struct t_data
{
	t_count		count;
	t_ambient	ambient;
	t_camera	camera;
	t_light		light;
	t_sp		*sphere;
	t_pl		*plane;
	t_cy		*cylinder;
	t_viewport	viewport;
}t_data;

typedef struct s_rec
{
	t_point	intersect;
	t_vec3	normal;
	t_color	albedo;
	double	t;
	double	tmin;
	double	tmax;
}t_rec;

#endif
