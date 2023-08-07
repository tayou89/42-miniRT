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

void	parse_data(int argc, char **argv, t_data *all);
void	parse_file(int fd, t_data *all);
void	parse_line(char *line, t_data *all);

void	ft_parsing_error(int error_number, int exit_number);
void	*free_2d_array(void **array);

#endif
