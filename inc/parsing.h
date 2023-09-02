#ifndef PARSING_H
# define PARSING_H

# include "utils_vec.h"
# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>

# define ARGC_ERROR				0
# define EXTENSION_ERROR		1
# define MALLOC_ERROR			2
# define OPEN_ERROR				3
# define DATA_ERROR				4

# define AMBIENT_INFO_COUNT		2
# define CAMERA_INFO_COUNT		3
# define LIGHT_INFO_COUNT		3
# define SPHERE_INFO_COUNT		3
# define PLANE_INFO_COUNT		3
# define CYLINDER_INFO_COUNT	5
# define COLOR_INFO_COUNT		3
# define COORDINATE_INFO_COUNT	3
# define VECTOR_INFO_COUNT		3

typedef struct s_info
{
	int		identifier;
	char	**color;
	char	**coordinate;
	char	**vector;
	char	*ratio;
	char	*diameter;
	char	*height;
	char	*fov;
}	t_info;

typedef struct s_line
{
	char	**info;
}	t_line;

typedef struct s_file
{
	int		fd;
	char	*line;
}	t_file;

typedef struct s_parsing
{
	t_file	file;
	t_line	line;
	t_info	info;
	t_data	data;
}	t_parsing;

void	parse_data(int argc, char **argv, t_data *data);
void	parse_file(t_parsing *parsing);
void	parse_line(t_parsing *parsing);

void	classify_element_information(char *line, t_parsing *parsing);
void	classify_ambient_information(char **info, t_parsing *parsing);
void	classify_camera_information(char **info, t_parsing *parsing);
void	classify_light_information(char **info, t_parsing *parsing);
void	classify_sphere_information(char **info, t_parsing *parsing);
void	classify_plane_information(char **info, t_parsing *parsing);
void	classify_cylinder_information(char **info, t_parsing *parsing);

void	get_element_data(t_info *info, t_parsing *parsing);
void	get_ambient_data(t_data *data, t_info *info, t_parsing *parsing);
void	get_camera_data(t_data *data, t_info *info, t_parsing *parsing);
void	get_light_data(t_data *data, t_info *info, t_parsing *parsing);
void	get_sphere_data(t_data *data, t_info *info, t_parsing *parsing);
void	get_plane_data(t_data *data, t_info *info, t_parsing *parsing);
void	get_cylinder_data(t_data *data, t_info *info, t_parsing *parsing);

double	get_ratio_data(char *string, t_parsing *parsing);
int		get_fov_data(char *string, t_parsing *parsing);
t_color	get_color_data(char **string, t_parsing *parsing);
t_vec3	get_vector_data(char **string, t_parsing *parsing);
t_point	get_coordinate_data(char **string, t_parsing *parsing);

t_sp	*make_sphere_node(t_info *info, t_parsing *parsing);
t_pl	*make_plane_node(t_info *info, t_parsing *parsing);
t_cy	*make_cylinder_node(t_info *info, t_parsing *parsing);

t_sp	*add_sphere_node(t_sp *new, t_sp *list);
t_pl	*add_plane_node(t_pl *new, t_pl *list);
t_cy	*add_cylinder_node(t_cy *new, t_cy *list);

int		get_integer(char *string, t_parsing *parsing);
double	get_double(char *string, t_parsing *parsing);

int		check_rgb_range(int color);
int		check_fov_range(int fov);
int		check_ratio_range(double ratio);
int		check_vector_range(double vector);

char	**get_splitted_array(char *array, char seperator, t_parsing *parsing);
char	*get_duplicated_string(char *string, t_parsing *parsing);
void	check_information_count(char **string, int type, t_parsing *parsing);
int		get_array_count(void **array);
int		get_sign(int *index, char *string);

void	ft_parsing_error(int error_number, int exit_number, t_parsing *parsing);
void	free_every_parsing_data(t_parsing *parsing);
void	free_info_data(t_info *info);
void	*free_2d_array(void **array);
void	*free_1d_array(void *array);
t_list	*create_node(void *elem, int type);
void	push_back(t_list **world, void *elem);
void	free_list(t_list *world);
#endif
