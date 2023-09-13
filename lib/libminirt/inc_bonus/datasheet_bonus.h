/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datasheet_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang <jhwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:37:24 by jhwang            #+#    #+#             */
/*   Updated: 2023/09/13 18:37:24 by jhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATASHEET_BONUS_H
# define DATASHEET_BONUS_H
# include <math.h>

# define TRUE 1
# define FALSE 0
# define EPSILON 1e-6

enum e_obj{
	PLANE,
	SPHERE,
	CYLINDER,
	CONE,
	CHECKER,
	AMBIENT,
	CAMERA,
	LIGHT,
	COLOR,
	COORDINATE,
	VECTOR
};

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

typedef struct s_checker
{
	int		exist;
	int		width;
	int		length;
	t_color	color_1;
	t_color	color_2;
}t_ch;

typedef struct s_sphere
{
	t_point	center;
	t_color	color;
	double	diameter;
	double	radius;
	double	radius2;
	int		checker_exist;
	t_ch	checker;
}t_sp;

typedef struct s_plane
{
	t_point	center;
	t_vec3	normal;
	t_color	color;
}t_pl;

typedef struct s_cylinder
{
	t_point	center;
	t_vec3	normal;
	t_color	color;
	t_vec3	top;
	t_vec3	base;
	double	diameter;
	double	radius;
	double	radius2;
	double	height;
}t_cy;

typedef struct s_cone
{
	t_point	center;
	t_point	disk_center;
	t_vec3	normal;
	t_vec3	height_vector;
	t_vec3	height_unit;
	t_color	color;
	t_point	top;
	double	diameter;
	double	radius;
	double	radius2;
	double	height;
	double	cosine;
}t_co;

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

typedef struct s_viewport
{
	double	width;
	double	height;
	t_point	center;
	t_point	left_top;
	t_point	starting;
	t_vec3	right_vector;				
	t_vec3	down_vector;
	t_vec3	right_unit;
	t_vec3	down_unit;
	t_vec3	axis_vector;
}t_viewport;

typedef struct s_list
{
	int				type;
	void			*element;
	struct s_list	*next;
}t_list;

typedef struct s_world
{
	t_count		count;
	t_ambient	ambient;
	t_camera	camera;
	t_list		*light;
	t_list		*obj;
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
	void	*texture;
	void	*map;
}t_rec;

typedef struct s_mapping
{
	double	u;
	double	v;
}t_mapping;

int	double_equal(double x, double y);
#endif
