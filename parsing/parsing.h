#ifndef PARSING_H
# define PARSING_H

# include "../common/datasheet.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>

# define ARGC_ERROR			0
# define EXTENSION_ERROR	1
# define MALLOC_ERROR		2
# define OPEN_ERROR			3
# define DATA_ERROR			4

# define AMBIENT			0
# define CAMERA				1
# define LIGHT				2
# define SPHERE				3
# define PLANE				4
# define CYLINDER			5

typedef struct s_info
{
	char	**rgb;
	char	**xyz;
}	t_info;

typedef struct s_line
{
	char	**info;
	int		identifier;
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
}	t_parsing;

void	parse_data(int argc, char **argv, t_data *all);
void	parse_file(t_parsing *data, t_data *all);
void	parse_line(t_parsing *data, t_data *all);

void	check_identifier(t_parsing *data, t_data *all);

int		get_integer(char *string, t_parsing *data);
double	get_double(char *string, t_parsing *data);

int		check_rgb_range(int data);
int		check_fov_range(int data);
int		check_ratio_range(double data);
int		check_vector_range(double data);

char	**get_splitted_array(char *array, char seperator, t_parsing *data);
int		get_array_count(void **array);
int		get_sign(int *index, char *string);

void	ft_parsing_error(int error_number, int exit_number, t_parsing *data);
void	free_every_parsing_data(t_parsing *data);
void	*free_2d_array(void **array);
void	*free_1d_array(void *array);

#endif
