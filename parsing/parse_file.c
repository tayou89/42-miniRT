#include "parsing.h"

static void	initialize_count(t_parsing *data);
static char	*remove_newline(char *line);

void	parse_file(t_parsing *data, t_data *all)
{
	initialize_data(all);
	data->file.line = get_next_line(data->file.fd);
	if (data->file.line == (void *) 0)
		ft_parsing_error(MALLOC_ERROR, 1);
	while (data->file.line != (void *) 0)
	{
		remove_newline(data->file.line);
		parse_line(data, all);
		free(data->file.line);
		line = get_next_line(data->file.fd);
	}
	close(data->file.fd);
}

static void	initialize_data(t_parsing *data, t_data *all)
{
	all->count.ambient = 0;
	all->count.camera = 0;
	all->count.light = 0;
	all->count.sp = 0;
	all->count.pl = 0;
	all->count.cy = 0;
	data->file.line = (void *) 0;
	data->line.info = (void *) 0;
	data->info.rgb = (void *) 0;
	data->info.xyz = (void *) 0;
}

static char	*remove_newline(char *line)
{
	char	*line;
	int		i;

	line = data->file.line;
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			line[i] = '\0';
		i++;
	}
	return (line);
}
