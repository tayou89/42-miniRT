#include "parsing.h"

static void	initialize_count(t_parsing *data);
static char	*remove_newline(char *line);

void	parse_file(int fd, t_data *all)
{
	char	*line;

	initialize_count(all);
	line = get_next_line(fd);
	if (line == (void *) 0)
		ft_parsing_error(MALLOC_ERROR, 1);
	while (line != (void *) 0)
	{
		line = remove_newline(line);
		parse_line(line, data, all);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

static void	initialize_count(t_data *all)
{
	all->count.ambient = 0;
	all->count.camera = 0;
	all->count.light = 0;
	all->count.sp = 0;
	all->count.pl = 0;
	all->count.cy = 0;
}

static char	*remove_newline(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			line[i] = '\0';
		i++;
	}
	return (line);
}
