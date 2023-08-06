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

typedef struct s_count
{
	int	ambient;
	int	camera;
	int	light;
	int	sp;
	int	pl;
	int	cy;
}	t_count;

typedef struct s_file
{
	int		fd;
}	t_file;

typedef struct s_parsing
{
	t_file	file;
	t_count	count;
}	t_parsing;

void	parse_data(int argc, char **argv, t_data *all);

char	*get_next_line(int fd);
void	ft_parsing_error(int error_number, int exit_number);

#endif
