#include "parsing.h"

static char	*remove_newline(char *line);

void	parse_file(t_parsing *parsing)
{
	parsing->file.line = get_next_line(parsing->file.fd);
	if (parsing->file.line == (void *) 0)
		ft_parsing_error(MALLOC_ERROR, 1, parsing);
	while (parsing->file.line != (void *) 0)
	{
		parsing->file.line = remove_newline(parsing->file.line);
		parse_line(parsing);
		free(parsing->file.line);
		line = get_next_line(parsing->file.fd);
	}
	close(parsing->file.fd);
}

static char	*remove_newline(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			line[i] = '\0';
		i++;
	}
	return (line);
}
